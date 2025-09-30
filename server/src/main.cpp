#include "meta_program/meta_program.hpp"
#include "server_networking/network.hpp"
#include "networking/packets/packets.hpp"
#include "networking/packet_handler/packet_handler.hpp"

#include "fixed_frequency_loop/fixed_frequency_loop.hpp"
#include "utility/logger/logger.hpp"
#include "utility/meta_utils/meta_utils.hpp"
#include "utility/text_utils/text_utils.hpp"

#include <iostream>
#include <ostream>
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
    packet.header.size_of_data_without_header = sizeof(unsigned int) + packet.positions.size() * sizeof(PositionArray);
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
    packet.header.size_of_data_without_header = sizeof(unsigned int) + packet.positions.size() * sizeof(PositionArray);
    return packet;
}

int main() {

    meta_utils::CustomTypeExtractionSettings settings("src/networking/packet_types/packet_types.hpp");
    meta_utils::CustomTypeExtractionSettings settings1("src/networking/packet_data/packet_data.hpp");
    meta_utils::CustomTypeExtractionSettings settings2("src/networking/packets/packets.hpp");
    meta_utils::register_custom_types_into_meta_types({settings, settings1, settings2});
    meta_utils::generate_string_invokers_program_wide({}, meta_utils::meta_types.get_concrete_types());

    meta_program::MetaProgram mp(meta_utils::meta_types.get_concrete_types());

    // global_logger.remove_all_sinks();
    global_logger.add_file_sink("logs.txt", true);

    Network server(7777);

    int num_broadcasts_made = 0;

    std::function<void(unsigned int)> on_client_connect = [&](unsigned int client_id) {
        UniqueClientIDPacket packet;
        packet.header.type = PacketType::UNIQUE_CLIENT_ID;
        packet.header.size_of_data_without_header = sizeof(unsigned int) + sizeof(packet.client_id);
        packet.id = num_broadcasts_made;
        packet.client_id = client_id;

        auto buffer = mp.serialize_UniqueClientIDPacket(packet);

        server.reliable_send(client_id, buffer.data(), buffer.size());
        global_logger.info("just sent packet: {}", mp.UniqueClientIDPacket_to_string(packet));
    };

    server.set_on_connect_callback(on_client_connect);
    server.initialize_network();

    PacketHandler packet_handler;
    // std::function<void(const void *)>

    packet_handler.register_handler(PacketType::KEYBOARD_MOUSE_UPDATE, [&](std::vector<uint8_t> buffer) {
        MouseKeyboardUpdatePacket kmup = mp.deserialize_MouseKeyboardUpdatePacket(buffer);
        global_logger.info("just received packet: {}", mp.MouseKeyboardUpdatePacket_to_string(kmup));

        // global_logger.info(mp.MouseKeyboardUpdatePacket_to_string(kmup));

        // global_logger.info(
        //     text_utils::format_nested_brace_string_recursive(mp.MouseKeyboardUpdatePacket_to_string(kmup)));
        // print_mkup(kmup);
    });

    FixedFrequencyLoop game;

    auto termination = []() { return false; };

    bool toggle = false;

    auto tick = [&server, &toggle, &packet_handler, &num_broadcasts_made, &mp](double dt) {
        LogSection _(global_logger, "tick");
        auto packets = server.get_network_events_since_last_tick();
        packet_handler.handle_packets(packets);

        GameUpdatePositionsPacket packet = toggle ? create_mock_game_update_positions_packet_2(num_broadcasts_made)
                                                  : create_mock_game_update_positions_packet_1(num_broadcasts_made);
        toggle = !toggle;

        auto buffer = mp.serialize_GameUpdatePositionsPacket(packet);

        server.reliable_broadcast(buffer.data(), buffer.size());
        global_logger.info("just sent packet: {} ", mp.GameUpdatePositionsPacket_to_string(packet));

        ++num_broadcasts_made;
    };

    game.start(2, tick, termination);

    return 0;
}
