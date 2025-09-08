#ifndef PACKETS_HPP
#define PACKETS_HPP

#include "../packet_data/packet_data.hpp"

struct UniqueClientIDPacket {
  PacketHeader header;
  unsigned int id;
  unsigned int client_id;
};

using PositionArray = std::array<float, 3>;

struct GameUpdatePositionsPacket {
  PacketHeader header;
  unsigned int id;
  std::vector<PositionArray> positions;
};

struct MouseKeyboardUpdate {
  bool fire_pressed;
  bool forward_pressed;
  // ...
};

struct MouseKeyboardUpdatePacket {
  PacketHeader header;
  unsigned int id;
  MouseKeyboardUpdate mku;
};

#endif // PACKETS_HPP
