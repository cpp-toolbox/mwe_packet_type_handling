#include "server_networking/network.hpp"
#include "fixed_frequency_loop/fixed_frequency_loop.hpp"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <memory>
#include <vector>
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

using PositionArray = std::array<float, 3>;

struct GameUpdatePositionsPacket {
    PacketHeader header;
    std::vector<PositionArray> positions;
};

GameUpdatePositionsPacket create_mock_game_update_positions_packet_1() {
    GameUpdatePositionsPacket packet;
    packet.header.type = PacketType::GAME_UPDATE_POSITIONS;
    packet.positions = {
        {1.0f, 1.0f, 1.0f},
        {1.0f, 0.0f, 0.0f},
        {0.0f, 1.0f, 0.0f},
        {0.0f, 0.0f, 1.0f},
        {1.0f, 1.0f, 1.0f},
    };
    packet.header.size_of_data_without_header = packet.positions.size() * sizeof(PositionArray);
    return packet;
}

GameUpdatePositionsPacket create_mock_game_update_positions_packet_2() {
    GameUpdatePositionsPacket packet;
    packet.header.type = PacketType::GAME_UPDATE_POSITIONS;
    packet.positions = {
        {2.0f, 2.0f, 2.0f},
        {2.0f, 0.0f, 0.0f},
    };
    packet.header.size_of_data_without_header = packet.positions.size() * sizeof(PositionArray);
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

        server.reliable_send(client_id, &packet, sizeof(UniqueClientIDPacket));
    };

    server.set_on_connect_callback(on_client_connect);
    server.initialize_network();

    FixedFrequencyLoop game;

    auto termination = []() {
        return false;
    };

    bool toggle = false;

    auto tick = [&server, &toggle](double dt) {
        server.get_network_events_since_last_tick();

        GameUpdatePositionsPacket packet = toggle ? create_mock_game_update_positions_packet_2() : create_mock_game_update_positions_packet_1();
        toggle = !toggle;

        size_t packet_size = sizeof(PacketHeader) + packet.positions.size() * sizeof(PositionArray);
        std::vector<char> buffer(packet_size);
        std::memcpy(buffer.data(), &packet.header, sizeof(PacketHeader));
        std::memcpy(buffer.data() + sizeof(PacketHeader), packet.positions.data(), packet.positions.size() * sizeof(PositionArray));

        server.reliable_broadcast(buffer.data(), buffer.size());
    };

    game.start(2, tick, termination);

    return 0;
}
