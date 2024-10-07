#include "client_networking/network.hpp"
#include "fixed_frequency_loop/fixed_frequency_loop.hpp"
#include "packet_handler/packet_handler.hpp"   
#include "packet_types.hpp"     
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <memory>
#include <cstring>
#include <iostream>
#include <string>
#include <array>
#include <unordered_map>
#include <functional>
#include <vector>

constexpr size_t MAX_CLIENTS = 5;

using PositionArray = std::array<float, 3>;
using PositionPacketArray = std::array<PositionArray, MAX_CLIENTS>;

struct GameUpdatePositionsPacket {
    PacketHeader header;
    PositionPacketArray positions;
};

struct UniqueClientIDPacket {
    PacketHeader header;
    unsigned int client_id;
};

void handle_game_update_positions_packet(const GameUpdatePositionsPacket& packet) {
    for (const auto& pos : packet.positions) {
        std::cout << "Position: (" 
                  << pos[0] << ", "
                  << pos[1] << ", "
                  << pos[2] << ")\n";
    }
}

void handle_unique_client_id_packet(const UniqueClientIDPacket& packet) {
    std::cout << "Client ID: " << packet.client_id << "\n";
}

std::unordered_map<PacketType, PacketHandler::HandlerFunction> initialize_packet_handlers() {
    std::unordered_map<PacketType, PacketHandler::HandlerFunction> handlers;

    handlers[PacketType::UNIQUE_CLIENT_ID] = [](const void* data) {
        const UniqueClientIDPacket* packet = reinterpret_cast<const UniqueClientIDPacket*>(data);
        handle_unique_client_id_packet(*packet);
    };

    handlers[PacketType::GAME_UPDATE_POSITIONS] = [](const void* data) {
        const GameUpdatePositionsPacket* packet = reinterpret_cast<const GameUpdatePositionsPacket*>(data);
        handle_game_update_positions_packet(*packet);
    };

    return handlers;
}

int main() {
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    console_sink->set_level(spdlog::level::debug);

    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("network_logs.txt", true);
    file_sink->set_level(spdlog::level::info);

    std::vector<spdlog::sink_ptr> sinks = {console_sink, file_sink};

    std::string ip_address = "localhost";
    Network network(ip_address, 7777, sinks);
    FixedFrequencyLoop game;

    auto handlers = initialize_packet_handlers();
    PacketHandler packet_handler(handlers);

    network.initialize_network();
    network.attempt_to_connect_to_server();

    auto tick = [&network, &packet_handler](double dt) {
        std::cout << "tick" << "\n";
        std::vector<PacketWithSize> packets_since_last_tick = network.get_network_events_received_since_last_tick();
        for (const auto& packet : packets_since_last_tick) {
            std::cout << "Received packet of size: " << packet.size << "\n";
        }
        packet_handler.handle_packets(packets_since_last_tick); 
    };

    auto termination = []() {
        return false; 
    };

    game.start(2, tick, termination);

    return 0;
}
