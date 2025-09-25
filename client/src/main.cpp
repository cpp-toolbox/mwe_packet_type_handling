#include "client_networking/network.hpp"
#include "fixed_frequency_loop/fixed_frequency_loop.hpp"

#include "meta_program/meta_program.hpp"
#include "networking/packet_handler/packet_handler.hpp"
#include "networking/packet_types/packet_types.hpp"
#include "networking/packets/packets.hpp"
#include "utility/logger/logger.hpp"
#include "utility/meta_utils/meta_utils.hpp"

#include <memory>
#include <iostream>
#include <string>
#include <array>
#include <unordered_map>
#include <functional>
#include <vector>

constexpr size_t MAX_CLIENTS = 5;

int main() {

    meta_utils::CustomTypeExtractionSettings settings("src/networking/packet_types/packet_types.hpp");
    meta_utils::CustomTypeExtractionSettings settings1("src/networking/packet_data/packet_data.hpp");
    meta_utils::CustomTypeExtractionSettings settings2("src/networking/packets/packets.hpp");
    meta_utils::register_custom_types_into_meta_types({settings, settings1, settings2});
    meta_utils::generate_string_invokers_program_wide({}, meta_utils::meta_types.get_concrete_types());

    meta_program::MetaProgram mp(meta_utils::meta_types.get_concrete_types());

    std::string ip_address = "localhost";
    Network network(ip_address, 7777);
    FixedFrequencyLoop game{2};

    // global_logger.remove_all_sinks();
    global_logger.add_file_sink("logs.txt", true);

    PacketHandler packet_handler;

    PacketHandler::HandlerFunction f = [&](std::vector<uint8_t> buffer) {
        UniqueClientIDPacket packet = mp.deserialize_UniqueClientIDPacket(buffer);
        // global_logger.info("just received packet with id: {}", packet.id);
        global_logger.info("just received packet: {}", mp.UniqueClientIDPacket_to_string(packet));
    };

    packet_handler.register_handler(PacketType::UNIQUE_CLIENT_ID, f);

    PacketHandler::HandlerFunction g = [&](std::vector<uint8_t> buffer) {
        GameUpdatePositionsPacket packet = mp.deserialize_GameUpdatePositionsPacket(buffer);
        // global_logger.info("just received packet with id: {}", packet.id);
        global_logger.info("just received packet: {}", mp.GameUpdatePositionsPacket_to_string(packet));
        // global_logger.info(
        //     text_utils::format_nested_brace_string_recursive(mp.GameUpdatePositionsPacket_to_string(packet)));
    };

    packet_handler.register_handler(PacketType::GAME_UPDATE_POSITIONS, g);

    network.initialize_network();
    network.attempt_to_connect_to_server();

    int num_packets_sent = 0;
    auto tick = [&network, &packet_handler, &num_packets_sent, &mp](double dt) {
        LogSection _(global_logger, "tick");

        std::vector<PacketWithSize> packets_since_last_tick = network.get_network_events_received_since_last_tick();
        // for (const auto &packet : packets_since_last_tick) {
        //     std::cout << "Received packet of size: " << packet.size << "\n";
        // }
        packet_handler.handle_packets(packets_since_last_tick);

        MouseKeyboardUpdate kmu{num_packets_sent % 2 == 0, num_packets_sent % 3 == 0};
        MouseKeyboardUpdatePacket packet;
        packet.header.type = PacketType::KEYBOARD_MOUSE_UPDATE;
        packet.header.size_of_data_without_header = sizeof(MouseKeyboardUpdate) + sizeof(unsigned int);
        packet.id = num_packets_sent;
        packet.mku = kmu;

        auto buffer = mp.serialize_MouseKeyboardUpdatePacket(packet);

        // network.send_packet(&packet, sizeof(MouseKeyboardUpdatePacket));
        network.send_packet(buffer.data(), buffer.size());
        global_logger.info("just sent packet : {}", mp.MouseKeyboardUpdatePacket_to_string(packet));
        // global_logger.info(mp.MouseKeyboardUpdatePacket_to_string(packet));
        num_packets_sent += 1;
    };

    auto termination = []() { return false; };

    game.start(tick, termination);

    return 0;
}
