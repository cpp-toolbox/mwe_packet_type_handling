#ifndef PACKET_TYPES_HPP
#define PACKET_TYPES_HPP

#include <cstdint>

enum class PacketType : uint8_t {
    UNIQUE_CLIENT_ID,
    GAME_UPDATE_POSITIONS,
    GAME_UPDATE_ONE_TIME_EVENTS,
    USER_MESSAGES,
};

#endif // PACKET_TYPES_HPP
