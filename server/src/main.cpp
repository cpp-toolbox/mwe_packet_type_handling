#include "server_networking/network.hpp"
#include "fixed_frequency_loop/fixed_frequency_loop.hpp"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <memory>
#include <functional>
#include <array>

enum class PacketType : uint8_t {
    UNIQUE_CLIENT_ID,
    GAME_UPDATE_POSITIONS,
    GAME_UPDATE_ONE_TIME_EVENTS,
    USER_MESSAGES,
};

struct PacketHeader {
    PacketType type; 
    uint32_t size_of_data_without_header;
};

struct UniqueClientIDPacket {
    PacketHeader header;
    unsigned int client_id;
};

constexpr size_t MAX_CLIENTS = 5;
using PositionArray = std::array<float, 3>;  // Fixed size for each position
using PositionPacketArray = std::array<PositionArray, MAX_CLIENTS>;  // Array for multiple positions

struct GameUpdatePositionsPacket {
    PacketHeader header;
    PositionPacketArray positions;  // Using std::array for fixed-size storage
};

PositionPacketArray mock_positions = {{
    {1.0f, 1.0f, 1.0f},
    {1.0f, 0.0f, 0.0f},
    {0.0f, 1.0f, 0.0f},
    {0.0f, 0.0f, 1.0f},
    {1.0f, 1.0f, 1.0f},
}};

GameUpdatePositionsPacket create_mock_game_update_positions_packet() {
    GameUpdatePositionsPacket packet;
    packet.header.type = PacketType::GAME_UPDATE_POSITIONS;
    packet.header.size_of_data_without_header = sizeof(PositionPacketArray);
    packet.positions = mock_positions;  // Copy the positions directly

    return packet;
}

int main() {
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    console_sink->set_level(spdlog::level::debug);

    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("network_logs.txt", true);
    file_sink->set_level(spdlog::level::info);

    std::vector<spdlog::sink_ptr> sinks = {console_sink, file_sink};

    Network server(7777, sinks);

    std::function<void(unsigned int)> on_client_connect = [&](unsigned int client_id) {
        UniqueClientIDPacket packet;
        packet.header.type = PacketType::UNIQUE_CLIENT_ID; 
        packet.header.size_of_data_without_header = sizeof(packet.client_id);
        packet.client_id = client_id; 

        ENetPacket *enet_packet = enet_packet_create(&packet, sizeof(packet), ENET_PACKET_FLAG_RELIABLE);
        server.reliable_send(client_id, &packet, sizeof(UniqueClientIDPacket));
    };

    server.set_on_connect_callback(on_client_connect);
    server.initialize_network();

    FixedFrequencyLoop game;

    auto termination = []() {
        return false;
    };

    // Updated tick function to send the GameUpdatePositionsPacket
    auto tick = [&server](double dt) {
        server.get_network_events_since_last_tick();

        // Create and send the mock GameUpdatePositionsPacket
        GameUpdatePositionsPacket packet = create_mock_game_update_positions_packet();

        // Broadcast the packet to all connected clients
        server.reliable_broadcast(&packet, sizeof(PacketHeader) + packet.header.size_of_data_without_header);
    };

    game.start(2, tick, termination);

    return 0;
}
