#include "client_networking/network.hpp"
#include "fixed_frequency_loop/fixed_frequency_loop.hpp"

#include "networking/packet_handler/packet_handler.hpp"
#include "networking/packet_types/packet_types.hpp"
#include "networking/packets/packets.hpp"
#include "utility/logger/logger.hpp"

#include <memory>
#include <iostream>
#include <string>
#include <array>
#include <unordered_map>
#include <functional>
#include <vector>

constexpr size_t MAX_CLIENTS = 5;

void handle_game_update_positions_packet(const GameUpdatePositionsPacket &packet) {
    global_logger.info("just received packet with id: {}", packet.id);
    for (const auto &pos : packet.positions) {
        global_logger.info("Position: ({}, {}, {})", pos[0], pos[1], pos[2]);
    }
}

void handle_unique_client_id_packet(const UniqueClientIDPacket &packet) {
    global_logger.info("just received packet with id: {}", packet.id);
    global_logger.info("Client ID: ", packet.client_id);
}

std::unordered_map<PacketType, PacketHandler::HandlerFunction> initialize_packet_handlers() {
    std::unordered_map<PacketType, PacketHandler::HandlerFunction> handlers;

    // NOTE: after client connects to server, the server sends you back a unique id.
    handlers[PacketType::UNIQUE_CLIENT_ID] = [](const void *data) {
        const UniqueClientIDPacket *packet = reinterpret_cast<const UniqueClientIDPacket *>(data);
        handle_unique_client_id_packet(*packet);
    };

    handlers[PacketType::GAME_UPDATE_POSITIONS] = [](const void *data) {
        const char *ptr = reinterpret_cast<const char *>(data);

        GameUpdatePositionsPacket packet;

        // 1. Header
        std::memcpy(&packet.header, ptr, sizeof(PacketHeader));
        ptr += sizeof(PacketHeader);

        // 2. ID
        std::memcpy(&packet.id, ptr, sizeof(int));
        ptr += sizeof(int);

        // 3. Positions
        size_t num_positions = packet.header.size_of_data_without_header - sizeof(int);
        num_positions /= sizeof(PositionArray);

        packet.positions.resize(num_positions);
        if (num_positions > 0) {
            std::memcpy(packet.positions.data(), ptr, num_positions * sizeof(PositionArray));
        }

        handle_game_update_positions_packet(packet);
    };

    return handlers;
}

GameUpdatePositionsPacket deserialize(const char *data, size_t size) {
    GameUpdatePositionsPacket packet;

    const char *ptr = data;

    // 1. Header
    if (size < sizeof(PacketHeader)) {
        throw std::runtime_error("deserialize: buffer too small for header");
    }
    std::memcpy(&packet.header, ptr, sizeof(PacketHeader));
    ptr += sizeof(PacketHeader);
    size -= sizeof(PacketHeader);

    // 2. ID
    if (size < sizeof(int)) {
        throw std::runtime_error("deserialize: buffer too small for id");
    }
    std::memcpy(&packet.id, ptr, sizeof(int));
    ptr += sizeof(int);
    size -= sizeof(int);

    // 3. Positions
    size_t num_positions = size / sizeof(PositionArray);
    if (size % sizeof(PositionArray) != 0) {
        throw std::runtime_error("deserialize: buffer size not aligned with PositionArray");
    }

    packet.positions.resize(num_positions);
    if (num_positions > 0) {
        std::memcpy(packet.positions.data(), ptr, num_positions * sizeof(PositionArray));
    }

    return packet;
}

int main() {

    std::string ip_address = "localhost";
    Network network(ip_address, 7777);
    FixedFrequencyLoop game{2};

    // global_logger.remove_all_sinks();
    global_logger.add_file_sink("logs.txt", true);

    auto handlers = initialize_packet_handlers();
    PacketHandler packet_handler(handlers);

    network.initialize_network();
    network.attempt_to_connect_to_server();

    int num_packets_sent = 0;
    auto tick = [&network, &packet_handler, &num_packets_sent](double dt) {
        LogSection _(global_logger, "tick");

        std::vector<PacketWithSize> packets_since_last_tick = network.get_network_events_received_since_last_tick();
        // for (const auto &packet : packets_since_last_tick) {
        //     std::cout << "Received packet of size: " << packet.size << "\n";
        // }
        packet_handler.handle_packets(packets_since_last_tick);

        MouseKeyboardUpdate kmu{num_packets_sent % 2 == 0, num_packets_sent % 3 == 0};
        MouseKeyboardUpdatePacket packet;
        packet.header.type = PacketType::KEYBOARD_MOUSE_UPDATE;
        packet.header.size_of_data_without_header = sizeof(MouseKeyboardUpdate);
        packet.id = num_packets_sent;
        packet.mku = kmu;
        network.send_packet(&packet, sizeof(MouseKeyboardUpdatePacket));
        global_logger.info("just sent packet with id: {}", packet.id);
        num_packets_sent += 1;
    };

    auto termination = []() { return false; };

    game.start(tick, termination);

    return 0;
}
