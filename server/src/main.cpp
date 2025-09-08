#include "server_networking/network.hpp"
#include "networking/packets/packets.hpp"
#include "networking/packet_handler/packet_handler.hpp"

#include "fixed_frequency_loop/fixed_frequency_loop.hpp"
#include "utility/logger/logger.hpp"
#include <iostream>
#include <ostream>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <memory>
#include <vector>
#include <functional>
#include <array>

GameUpdatePositionsPacket create_mock_game_update_positions_packet_1(int id) {
    GameUpdatePositionsPacket packet;
    packet.header.type = PacketType::GAME_UPDATE_POSITIONS;
    packet.id = id;
    packet.positions = {
        {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f, 1.0f},
    };
    packet.header.size_of_data_without_header = packet.positions.size() * sizeof(PositionArray);
    return packet;
}

GameUpdatePositionsPacket create_mock_game_update_positions_packet_2(int id) {
    GameUpdatePositionsPacket packet;
    packet.header.type = PacketType::GAME_UPDATE_POSITIONS;
    packet.id = id;
    packet.positions = {
        {2.0f, 2.0f, 2.0f},
        {2.0f, 0.0f, 0.0f},
    };
    packet.header.size_of_data_without_header = packet.positions.size() * sizeof(PositionArray);
    return packet;
}

void print_mkup(const MouseKeyboardUpdatePacket &packet) {
    global_logger.info("just received packet with id: {}", packet.id);
    global_logger.info("MouseKeyboardUpdatePacket {{ fire_pressed: {}, forward_pressed {} }}", packet.mku.fire_pressed,
                       packet.mku.forward_pressed);
}

std::vector<char> serialize(const GameUpdatePositionsPacket &packet) {
    std::vector<char> buffer;
    buffer.reserve(sizeof(PacketHeader) + sizeof(int) + packet.positions.size() * sizeof(PositionArray));

    auto append = [&](auto *data, size_t size) {
        const char *raw = reinterpret_cast<const char *>(data);
        buffer.insert(buffer.end(), raw, raw + size);
    };

    append(&packet.header, sizeof(PacketHeader));
    append(&packet.id, sizeof(packet.id)); // use id instead of num_broadcasts_made?
    append(packet.positions.data(), packet.positions.size() * sizeof(PositionArray));

    return buffer;
}

int main() {

    // global_logger.remove_all_sinks();
    global_logger.add_file_sink("logs.txt", true);

    Network server(7777);

    int num_broadcasts_made = 0;

    std::function<void(unsigned int)> on_client_connect = [&](unsigned int client_id) {
        UniqueClientIDPacket packet;
        packet.header.type = PacketType::UNIQUE_CLIENT_ID;
        packet.header.size_of_data_without_header = sizeof(packet.client_id);
        packet.id = num_broadcasts_made;
        packet.client_id = client_id;

        server.reliable_send(client_id, &packet, sizeof(UniqueClientIDPacket));
    };

    server.set_on_connect_callback(on_client_connect);
    server.initialize_network();

    PacketHandler packet_handler;
    // std::function<void(const void *)>
    packet_handler.register_handler(PacketType::KEYBOARD_MOUSE_UPDATE, [](const void *raw_packet) {
        const MouseKeyboardUpdatePacket *kmup = reinterpret_cast<const MouseKeyboardUpdatePacket *>(raw_packet);
        print_mkup(*kmup);
    });

    FixedFrequencyLoop game;

    auto termination = []() { return false; };

    bool toggle = false;

    auto tick = [&server, &toggle, &packet_handler, &num_broadcasts_made](double dt) {
        LogSection _(global_logger, "tick");
        auto packets = server.get_network_events_since_last_tick();
        packet_handler.handle_packets(packets);

        GameUpdatePositionsPacket packet = toggle ? create_mock_game_update_positions_packet_2(num_broadcasts_made)
                                                  : create_mock_game_update_positions_packet_1(num_broadcasts_made);
        toggle = !toggle;

        auto buffer = serialize(packet);

        server.reliable_broadcast(buffer.data(), buffer.size());
        global_logger.info("just sent packet with id: {}", packet.id);
        ++num_broadcasts_made;
    };

    game.start(2, tick, termination);

    return 0;
}
