#ifndef META_PROGRAM_HPP
#define META_PROGRAM_HPP

#include "../networking/packet_types/packet_types.hpp"
#include "../networking/packet_data/packet_data.hpp"
#include "../networking/packet_data/packet_data.hpp"
#include "../networking/packets/packets.hpp"
#include "../networking/packets/packets.hpp"
#include "../networking/packets/packets.hpp"
#include "../networking/packets/packets.hpp"
#include "../networking/packets/packets.hpp"
#include <optional>
#include "../utility/meta_utils/meta_utils.hpp"

namespace meta_program {


class MetaProgram {
public:
        MetaProgram(std::vector<meta_utils::MetaType> concrete_types) : concrete_types(concrete_types) {
        }

public:
    std::vector<meta_utils::MetaType>  concrete_types;
    std::string char_to_string(char &v) {
        return std::to_string(v);

    }
    char string_to_char(std::string &s) {
        return static_cast<char>(s.empty() ? 0 : s[0]);

    }
    std::vector<uint8_t> serialize_char(char &v) {
        std::vector<uint8_t> buf(sizeof(char));   std::memcpy(buf.data(), &v, sizeof(char));   return buf;

    }
    size_t size_when_serialized_char(char &v) {
        return sizeof(char);

    }
    char deserialize_char(std::vector<uint8_t> &buf) {
        char v;   std::memcpy(&v, buf.data(), sizeof(char));   return v;

    }
    std::string int_to_string(int &v) {
        return std::to_string(v);

    }
    int string_to_int(std::string &s) {
        return std::stoi(s);

    }
    std::vector<uint8_t> serialize_int(int &v) {
        std::vector<uint8_t> buf(sizeof(int));   std::memcpy(buf.data(), &v, sizeof(int));   return buf;

    }
    size_t size_when_serialized_int(int &v) {
        return sizeof(int);

    }
    int deserialize_int(std::vector<uint8_t> &buf) {
        int v;   std::memcpy(&v, buf.data(), sizeof(int));   return v;

    }
    std::string unsigned_int_to_string(unsigned int &v) {
        return std::to_string(v);

    }
    unsigned int string_to_unsigned_int(std::string &s) {
        return static_cast<unsigned int>(std::stoul(s));

    }
    std::vector<uint8_t> serialize_unsigned_int(unsigned int &v) {
        std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf;

    }
    size_t size_when_serialized_unsigned_int(unsigned int &v) {
        return sizeof(unsigned int);

    }
    unsigned int deserialize_unsigned_int(std::vector<uint8_t> &buf) {
        unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v;

    }
    std::string uint8_t_to_string(uint8_t &v) {
        return std::to_string(v);

    }
    uint8_t string_to_uint8_t(std::string &s) {
        return static_cast<uint8_t>(std::stoul(s));

    }
    std::vector<uint8_t> serialize_uint8_t(uint8_t &v) {
        std::vector<uint8_t> buf(sizeof(uint8_t));   std::memcpy(buf.data(), &v, sizeof(uint8_t));   return buf;

    }
    size_t size_when_serialized_uint8_t(uint8_t &v) {
        return sizeof(uint8_t);

    }
    uint8_t deserialize_uint8_t(std::vector<uint8_t> &buf) {
        uint8_t v;   std::memcpy(&v, buf.data(), sizeof(uint8_t));   return v;

    }
    std::string uint32_t_to_string(uint32_t &v) {
        return std::to_string(v);

    }
    uint32_t string_to_uint32_t(std::string &s) {
        return static_cast<uint32_t>(std::stoul(s));

    }
    std::vector<uint8_t> serialize_uint32_t(uint32_t &v) {
        std::vector<uint8_t> buf(sizeof(uint32_t));   std::memcpy(buf.data(), &v, sizeof(uint32_t));   return buf;

    }
    size_t size_when_serialized_uint32_t(uint32_t &v) {
        return sizeof(uint32_t);

    }
    uint32_t deserialize_uint32_t(std::vector<uint8_t> &buf) {
        uint32_t v;   std::memcpy(&v, buf.data(), sizeof(uint32_t));   return v;

    }
    std::string size_t_to_string(size_t &v) {
        return std::to_string(v);

    }
    size_t string_to_size_t(std::string &s) {
        return static_cast<size_t>(std::stoull(s));

    }
    std::vector<uint8_t> serialize_size_t(size_t &v) {
        std::vector<uint8_t> buf(sizeof(size_t));   std::memcpy(buf.data(), &v, sizeof(size_t));   return buf;

    }
    size_t size_when_serialized_size_t(size_t &v) {
        return sizeof(size_t);

    }
    size_t deserialize_size_t(std::vector<uint8_t> &buf) {
        size_t v;   std::memcpy(&v, buf.data(), sizeof(size_t));   return v;

    }
    std::string float_to_string(float &v) {
        return std::to_string(v);

    }
    float string_to_float(std::string &s) {
        return std::stof(s);

    }
    std::vector<uint8_t> serialize_float(float &v) {
        std::vector<uint8_t> buf(sizeof(float));   std::memcpy(buf.data(), &v, sizeof(float));   return buf;

    }
    size_t size_when_serialized_float(float &v) {
        return sizeof(float);

    }
    float deserialize_float(std::vector<uint8_t> &buf) {
        float v;   std::memcpy(&v, buf.data(), sizeof(float));   return v;

    }
    std::string double_to_string(double &v) {
        return std::to_string(v);

    }
    double string_to_double(std::string &s) {
        return std::stod(s);

    }
    std::vector<uint8_t> serialize_double(double &v) {
        std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf;

    }
    size_t size_when_serialized_double(double &v) {
        return sizeof(double);

    }
    double deserialize_double(std::vector<uint8_t> &buf) {
        double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v;

    }
    std::string short_to_string(short &v) {
        return std::to_string(v);

    }
    short string_to_short(std::string &s) {
        return static_cast<short>(std::stoi(s));

    }
    std::vector<uint8_t> serialize_short(short &v) {
        std::vector<uint8_t> buf(sizeof(short));   std::memcpy(buf.data(), &v, sizeof(short));   return buf;

    }
    size_t size_when_serialized_short(short &v) {
        return sizeof(short);

    }
    short deserialize_short(std::vector<uint8_t> &buf) {
        short v;   std::memcpy(&v, buf.data(), sizeof(short));   return v;

    }
    std::string long_to_string(long &v) {
        return std::to_string(v);

    }
    long string_to_long(std::string &s) {
        return std::stol(s);

    }
    std::vector<uint8_t> serialize_long(long &v) {
        std::vector<uint8_t> buf(sizeof(long));   std::memcpy(buf.data(), &v, sizeof(long));   return buf;

    }
    size_t size_when_serialized_long(long &v) {
        return sizeof(long);

    }
    long deserialize_long(std::vector<uint8_t> &buf) {
        long v;   std::memcpy(&v, buf.data(), sizeof(long));   return v;

    }
    std::string std__string_to_string(std::string &s) {
        return s;

    }
    std::string string_to_std__string(std::string &s) {
        return s;

    }
    std::vector<uint8_t> serialize_std__string(std::string &v) {
        std::vector<uint8_t> buf;   size_t len = v.size();   buf.resize(sizeof(size_t) + len);   std::memcpy(buf.data(), &len, sizeof(size_t));   std::memcpy(buf.data() + sizeof(size_t), v.data(), len);   return buf;

    }
    size_t size_when_serialized_std__string(std::string &v) {
        return sizeof(size_t) + v.size();

    }
    std::string deserialize_std__string(std::vector<uint8_t> &buf) {
        if (buf.size() < sizeof(size_t)) return std::string();   size_t len;   std::memcpy(&len, buf.data(), sizeof(size_t));   if (buf.size() < sizeof(size_t) + len) return std::string();   return std::string(reinterpret_cast<const char*>(buf.data() + sizeof(size_t)), len);

    }
    std::string bool_to_string(bool &v) {
        return std::to_string(v);

    }
    bool string_to_bool(std::string &s) {
        return s == "true" || s == "1";

    }
    std::vector<uint8_t> serialize_bool(bool &v) {
        std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf;

    }
    size_t size_when_serialized_bool(bool &v) {
        return sizeof(uint8_t);

    }
    bool deserialize_bool(std::vector<uint8_t> &buf) {
        return buf[0] != 0;

    }
    std::string meta_utils__MetaType_to_string() {
        return "";

    }
    meta_utils::MetaType string_to_meta_utils__MetaType() {

    }
    std::vector<uint8_t> serialize_meta_utils__MetaType() {

    }
    size_t size_when_serialized_meta_utils__MetaType(meta_utils::MetaType &v) {
        return sizeof(meta_utils::MetaType);

    }
    meta_utils::MetaType deserialize_meta_utils__MetaType() {

    }
    std::string PacketType_to_string(PacketType value) {
        switch(value) {
                case PacketType::UNIQUE_CLIENT_ID: return "PacketType::UNIQUE_CLIENT_ID";
                case PacketType::GAME_UPDATE_POSITIONS: return "PacketType::GAME_UPDATE_POSITIONS";
                case PacketType::GAME_UPDATE_ONE_TIME_EVENTS: return "PacketType::GAME_UPDATE_ONE_TIME_EVENTS";
                case PacketType::KEYBOARD_MOUSE_UPDATE: return "PacketType::KEYBOARD_MOUSE_UPDATE";
                default: return "<unknown PacketType>";
            }

    }
    PacketType string_to_PacketType(std::string &s) {
        if (s == "PacketType::UNIQUE_CLIENT_ID") return PacketType::UNIQUE_CLIENT_ID;
            if (s == "PacketType::GAME_UPDATE_POSITIONS") return PacketType::GAME_UPDATE_POSITIONS;
            if (s == "PacketType::GAME_UPDATE_ONE_TIME_EVENTS") return PacketType::GAME_UPDATE_ONE_TIME_EVENTS;
            if (s == "PacketType::KEYBOARD_MOUSE_UPDATE") return PacketType::KEYBOARD_MOUSE_UPDATE;
            return static_cast<PacketType>(0); // default fallback

    }
    std::vector<uint8_t> serialize_PacketType(PacketType value) {
        std::vector<uint8_t> buffer(sizeof(uint8_t));
            uint8_t raw = static_cast<uint8_t>(value);
            std::memcpy(buffer.data(), &raw, sizeof(uint8_t));
            return buffer;

    }
    size_t size_when_serialized_PacketType(PacketType &obj) {
        return sizeof(uint8_t);

    }
    PacketType deserialize_PacketType(std::vector<uint8_t> &buffer) {
        if (buffer.size() < sizeof(uint8_t)) return static_cast<PacketType>(0);
            uint8_t raw = 0;
            std::memcpy(&raw, buffer.data(), sizeof(uint8_t));
            return static_cast<PacketType>(raw);

    }
    std::string PacketHeader_to_string(PacketHeader obj) {
        std::ostringstream oss;
            oss << "{";
            { auto conv = [=](PacketType value) -> std::string {
            switch(value) {
                case PacketType::UNIQUE_CLIENT_ID: return "PacketType::UNIQUE_CLIENT_ID";
                case PacketType::GAME_UPDATE_POSITIONS: return "PacketType::GAME_UPDATE_POSITIONS";
                case PacketType::GAME_UPDATE_ONE_TIME_EVENTS: return "PacketType::GAME_UPDATE_ONE_TIME_EVENTS";
                case PacketType::KEYBOARD_MOUSE_UPDATE: return "PacketType::KEYBOARD_MOUSE_UPDATE";
                default: return "<unknown PacketType>";
            }
        };
              oss << "type=" << conv(obj.type); }
            oss << ", ";
            { auto conv = [](const uint32_t &v) { return std::to_string(v); };
              oss << "size_of_data_without_header=" << conv(obj.size_of_data_without_header); }
            oss << "}";
            return oss.str();

    }
    PacketHeader string_to_PacketHeader(std::string &s) {
        PacketHeader obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> PacketType {
            if (s == "PacketType::UNIQUE_CLIENT_ID") return PacketType::UNIQUE_CLIENT_ID;
            if (s == "PacketType::GAME_UPDATE_POSITIONS") return PacketType::GAME_UPDATE_POSITIONS;
            if (s == "PacketType::GAME_UPDATE_ONE_TIME_EVENTS") return PacketType::GAME_UPDATE_ONE_TIME_EVENTS;
            if (s == "PacketType::KEYBOARD_MOUSE_UPDATE") return PacketType::KEYBOARD_MOUSE_UPDATE;
            return static_cast<PacketType>(0); // default fallback
        };
                    obj.type = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<uint32_t>(std::stoul(s)); };
                    obj.size_of_data_without_header = conv(value_str);
                }
            }
            return obj;

    }
    std::vector<uint8_t> serialize_PacketHeader(PacketHeader obj) {
        std::vector<uint8_t> buffer;
            { auto ser = [=](PacketType value) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer(sizeof(uint8_t));
            uint8_t raw = static_cast<uint8_t>(value);
            std::memcpy(buffer.data(), &raw, sizeof(uint8_t));
            return buffer;
        };
              auto bytes = ser(obj.type);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const uint32_t &v) {   std::vector<uint8_t> buf(sizeof(uint32_t));   std::memcpy(buf.data(), &v, sizeof(uint32_t));   return buf; };
              auto bytes = ser(obj.size_of_data_without_header);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;

    }
    size_t size_when_serialized_PacketHeader(PacketHeader obj) {
        size_t total = 0;
            { auto size_fn = [=](const PacketType &obj) -> size_t {
            return sizeof(uint8_t);
        };
              total += size_fn(obj.type); }
            { auto size_fn = [](const uint32_t &v) { return sizeof(uint32_t); };
              total += size_fn(obj.size_of_data_without_header); }
            return total;

    }
    PacketHeader deserialize_PacketHeader(std::vector<uint8_t> &buffer) {
        PacketHeader obj;
            size_t offset = 0;
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> PacketType {
            if (buffer.size() < sizeof(uint8_t)) return static_cast<PacketType>(0);
            uint8_t raw = 0;
            std::memcpy(&raw, buffer.data(), sizeof(uint8_t));
            return static_cast<PacketType>(raw);
        };
              auto size_fn = [=](const PacketType &obj) -> size_t {
            return sizeof(uint8_t);
        };
              size_t len = size_fn(obj.type);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.type = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   uint32_t v;   std::memcpy(&v, buf.data(), sizeof(uint32_t));   return v; };
              auto size_fn = [](const uint32_t &v) { return sizeof(uint32_t); };
              size_t len = size_fn(obj.size_of_data_without_header);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.size_of_data_without_header = deser(slice);
              offset += len;
            }
            return obj;

    }
    std::string PacketWithSize_to_string(PacketWithSize obj) {
        std::ostringstream oss;
            oss << "{";
            { auto conv = [=](const std::vector<char>& vec) -> std::string {
            std::ostringstream oss;
            oss << "{";
            auto conversion = [](const char &v) { return std::to_string(v); };
        
            for (size_t i = 0; i < vec.size(); ++i) {
                oss << conversion(vec[i]);
                if (i + 1 < vec.size())
                    oss << ", ";
            }
        
            oss << "}";
            return oss.str();
        };
              oss << "data=" << conv(obj.data); }
            oss << ", ";
            { auto conv = [](const size_t &v) { return std::to_string(v); };
              oss << "size=" << conv(obj.size); }
            oss << "}";
            return oss.str();

    }
    PacketWithSize string_to_PacketWithSize(std::string &s) {
        PacketWithSize obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &input) -> std::vector<char> {
            std::string trimmed = input;
            if (!trimmed.empty() && trimmed.front() == '{' && trimmed.back() == '}') {
                trimmed = trimmed.substr(1, trimmed.size() - 2);
            }
        
            std::vector<char> result;
            std::regex element_re(R"('(?:[^'\\]|\\.)')");
            auto begin = std::sregex_iterator(trimmed.begin(), trimmed.end(), element_re);
            auto end = std::sregex_iterator();
        
            for (auto it = begin; it != end; ++it) {
                try {
                    auto conversion = [](const std::string &s) { return static_cast<char>(s.empty() ? 0 : s[0]); };
                    result.push_back(conversion(it->str()));
                } catch (...) {
                    // Ignore malformed elements
                }
            }
            return result;
        };
                    obj.data = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<size_t>(std::stoull(s)); };
                    obj.size = conv(value_str);
                }
            }
            return obj;

    }
    std::vector<uint8_t> serialize_PacketWithSize(PacketWithSize obj) {
        std::vector<uint8_t> buffer;
            { auto ser = [=](const std::vector<char>& vec) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            size_t count = vec.size();
            buffer.resize(sizeof(size_t));
            std::memcpy(buffer.data(), &count, sizeof(size_t));
        
            auto element_serializer = [](const char &v) {   std::vector<uint8_t> buf(sizeof(char));   std::memcpy(buf.data(), &v, sizeof(char));   return buf; };
            if (!vec.empty()) {
                size_t elem_size = sizeof(char);
                buffer.resize(buffer.size() + vec.size() * elem_size);
                std::memcpy(buffer.data() + sizeof(size_t), vec.data(), vec.size() * elem_size);
            }
            return buffer;
        };
              auto bytes = ser(obj.data);
              size_t len = bytes.size();
              buffer.resize(buffer.size() + sizeof(size_t));
              std::memcpy(buffer.data() + buffer.size() - sizeof(size_t), &len, sizeof(size_t));
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const size_t &v) {   std::vector<uint8_t> buf(sizeof(size_t));   std::memcpy(buf.data(), &v, sizeof(size_t));   return buf; };
              auto bytes = ser(obj.size);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;

    }
    size_t size_when_serialized_PacketWithSize(PacketWithSize obj) {
        size_t total = 0;
            { auto size_fn = [=](const std::vector<char>& vec) -> size_t {
            size_t total_size = sizeof(size_t); // space for storing count
            if (!vec.empty()) {
                total_size += vec.size() * [](const char &v) { return sizeof(char); }(vec[0]);
            }
            return total_size;
        };
              total += sizeof(size_t); // length prefix
              total += size_fn(obj.data); }
            { auto size_fn = [](const size_t &v) { return sizeof(size_t); };
              total += size_fn(obj.size); }
            return total;

    }
    PacketWithSize deserialize_PacketWithSize(std::vector<uint8_t> &buffer) {
        PacketWithSize obj;
            size_t offset = 0;
            { auto deser = [=](const std::vector<uint8_t>& buffer) -> std::vector<char> {
            std::vector<char> result;
            if (buffer.size() < sizeof(size_t)) return result;
            size_t count;
            std::memcpy(&count, buffer.data(), sizeof(size_t));
        
            size_t offset = sizeof(size_t);
            auto element_deserializer = [](const std::vector<uint8_t> &buf) {   char v;   std::memcpy(&v, buf.data(), sizeof(char));   return v; };
            size_t elem_size = sizeof(char);
            if (offset + count * elem_size > buffer.size()) return result; // safety check
            for (size_t i = 0; i < count; ++i) {
                std::vector<uint8_t> elem_buf(buffer.begin() + offset, buffer.begin() + offset + elem_size);
                char elem = element_deserializer(elem_buf);
                result.push_back(elem);
                offset += elem_size;
            }
            return result;
        };
              if (offset + sizeof(size_t) > buffer.size()) return obj;
              size_t len = 0;
              std::memcpy(&len, buffer.data() + offset, sizeof(size_t));
              offset += sizeof(size_t);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.data = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   size_t v;   std::memcpy(&v, buf.data(), sizeof(size_t));   return v; };
              auto size_fn = [](const size_t &v) { return sizeof(size_t); };
              size_t len = size_fn(obj.size);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.size = deser(slice);
              offset += len;
            }
            return obj;

    }
    std::string UniqueClientIDPacket_to_string(UniqueClientIDPacket obj) {
        std::ostringstream oss;
            oss << "{";
            { auto conv = [=](const PacketHeader& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [=](PacketType value) -> std::string {
            switch(value) {
                case PacketType::UNIQUE_CLIENT_ID: return "PacketType::UNIQUE_CLIENT_ID";
                case PacketType::GAME_UPDATE_POSITIONS: return "PacketType::GAME_UPDATE_POSITIONS";
                case PacketType::GAME_UPDATE_ONE_TIME_EVENTS: return "PacketType::GAME_UPDATE_ONE_TIME_EVENTS";
                case PacketType::KEYBOARD_MOUSE_UPDATE: return "PacketType::KEYBOARD_MOUSE_UPDATE";
                default: return "<unknown PacketType>";
            }
        };
              oss << "type=" << conv(obj.type); }
            oss << ", ";
            { auto conv = [](const uint32_t &v) { return std::to_string(v); };
              oss << "size_of_data_without_header=" << conv(obj.size_of_data_without_header); }
            oss << "}";
            return oss.str();
        };
              oss << "header=" << conv(obj.header); }
            oss << ", ";
            { auto conv = [](const unsigned int &v) { return std::to_string(v); };
              oss << "id=" << conv(obj.id); }
            oss << ", ";
            { auto conv = [](const unsigned int &v) { return std::to_string(v); };
              oss << "client_id=" << conv(obj.client_id); }
            oss << "}";
            return oss.str();

    }
    UniqueClientIDPacket string_to_UniqueClientIDPacket(std::string &s) {
        UniqueClientIDPacket obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> PacketHeader {
            PacketHeader obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> PacketType {
            if (s == "PacketType::UNIQUE_CLIENT_ID") return PacketType::UNIQUE_CLIENT_ID;
            if (s == "PacketType::GAME_UPDATE_POSITIONS") return PacketType::GAME_UPDATE_POSITIONS;
            if (s == "PacketType::GAME_UPDATE_ONE_TIME_EVENTS") return PacketType::GAME_UPDATE_ONE_TIME_EVENTS;
            if (s == "PacketType::KEYBOARD_MOUSE_UPDATE") return PacketType::KEYBOARD_MOUSE_UPDATE;
            return static_cast<PacketType>(0); // default fallback
        };
                    obj.type = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<uint32_t>(std::stoul(s)); };
                    obj.size_of_data_without_header = conv(value_str);
                }
            }
            return obj;
        };
                    obj.header = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<unsigned int>(std::stoul(s)); };
                    obj.id = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<unsigned int>(std::stoul(s)); };
                    obj.client_id = conv(value_str);
                }
            }
            return obj;

    }
    std::vector<uint8_t> serialize_UniqueClientIDPacket(UniqueClientIDPacket obj) {
        std::vector<uint8_t> buffer;
            { auto ser = [=](const PacketHeader& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [=](PacketType value) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer(sizeof(uint8_t));
            uint8_t raw = static_cast<uint8_t>(value);
            std::memcpy(buffer.data(), &raw, sizeof(uint8_t));
            return buffer;
        };
              auto bytes = ser(obj.type);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const uint32_t &v) {   std::vector<uint8_t> buf(sizeof(uint32_t));   std::memcpy(buf.data(), &v, sizeof(uint32_t));   return buf; };
              auto bytes = ser(obj.size_of_data_without_header);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.header);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const unsigned int &v) {   std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf; };
              auto bytes = ser(obj.id);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const unsigned int &v) {   std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf; };
              auto bytes = ser(obj.client_id);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;

    }
    size_t size_when_serialized_UniqueClientIDPacket(UniqueClientIDPacket obj) {
        size_t total = 0;
            { auto size_fn = [=](const PacketHeader& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [=](const PacketType &obj) -> size_t {
            return sizeof(uint8_t);
        };
              total += size_fn(obj.type); }
            { auto size_fn = [](const uint32_t &v) { return sizeof(uint32_t); };
              total += size_fn(obj.size_of_data_without_header); }
            return total;
        };
              total += size_fn(obj.header); }
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id); }
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.client_id); }
            return total;

    }
    UniqueClientIDPacket deserialize_UniqueClientIDPacket(std::vector<uint8_t> &buffer) {
        UniqueClientIDPacket obj;
            size_t offset = 0;
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> PacketHeader {
            PacketHeader obj;
            size_t offset = 0;
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> PacketType {
            if (buffer.size() < sizeof(uint8_t)) return static_cast<PacketType>(0);
            uint8_t raw = 0;
            std::memcpy(&raw, buffer.data(), sizeof(uint8_t));
            return static_cast<PacketType>(raw);
        };
              auto size_fn = [=](const PacketType &obj) -> size_t {
            return sizeof(uint8_t);
        };
              size_t len = size_fn(obj.type);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.type = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   uint32_t v;   std::memcpy(&v, buf.data(), sizeof(uint32_t));   return v; };
              auto size_fn = [](const uint32_t &v) { return sizeof(uint32_t); };
              size_t len = size_fn(obj.size_of_data_without_header);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.size_of_data_without_header = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const PacketHeader& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [=](const PacketType &obj) -> size_t {
            return sizeof(uint8_t);
        };
              total += size_fn(obj.type); }
            { auto size_fn = [](const uint32_t &v) { return sizeof(uint32_t); };
              total += size_fn(obj.size_of_data_without_header); }
            return total;
        };
              size_t len = size_fn(obj.header);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.header = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v; };
              auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              size_t len = size_fn(obj.id);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v; };
              auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              size_t len = size_fn(obj.client_id);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.client_id = deser(slice);
              offset += len;
            }
            return obj;

    }
    std::string PositionArray_to_string(std::array<float, 3> arr) {
        std::ostringstream oss;
            oss << "{";
            auto conversion = [](const float &v) { return std::to_string(v); };
        
            for (size_t i = 0; i < arr.size(); ++i) {
                oss << conversion(arr[i]);
                if (i + 1 < arr.size())
                    oss << ", ";
            }
        
            oss << "}";
            return oss.str();

    }
    std::array<float, 3> string_to_PositionArray(std::string &input) {
        std::string trimmed = input;
            if (!trimmed.empty() && trimmed.front() == '{' && trimmed.back() == '}') {
                trimmed = trimmed.substr(1, trimmed.size() - 2);
            }
        
            std::array<float, 3> result{};
            std::regex element_re(R"(-?\d+(?:\.\d+)?)");
            auto begin = std::sregex_iterator(trimmed.begin(), trimmed.end(), element_re);
            auto end = std::sregex_iterator();
        
            size_t idx = 0;
            for (auto it = begin; it != end && idx < 3; ++it, ++idx) {
                try {
                    auto conversion = [](const std::string &s) { return std::stof(s); };
                    result[idx] = conversion(it->str());
                } catch (...) {
                    // Ignore malformed elements
                }
            }
            return result;

    }
    std::vector<uint8_t> serialize_PositionArray(std::array<float, 3> arr) {
        std::vector<uint8_t> buffer;
            auto element_serializer = [](const float &v) {   std::vector<uint8_t> buf(sizeof(float));   std::memcpy(buf.data(), &v, sizeof(float));   return buf; };
            if (!arr.empty()) {
                size_t elem_size = sizeof(float);
                buffer.resize(buffer.size() + arr.size() * elem_size);
                std::memcpy(buffer.data(), arr.data(), arr.size() * elem_size);
            }
            return buffer;

    }
    size_t size_when_serialized_PositionArray(std::array<float, 3> arr) {
        size_t total_size = 0;
            if (!arr.empty()) {
                total_size += arr.size() * [](const float &v) { return sizeof(float); }(arr[0]);
            }
            return total_size;

    }
    std::array<float, 3> deserialize_PositionArray(std::vector<uint8_t> buffer) {
        std::array<float, 3> result{};
            auto element_deserializer = [](const std::vector<uint8_t> &buf) {   float v;   std::memcpy(&v, buf.data(), sizeof(float));   return v; };
        
            size_t offset = 0;
            size_t elem_size = sizeof(float);
            if (buffer.size() < 3 * elem_size) return result;
            for (size_t i = 0; i < 3; ++i) {
                std::vector<uint8_t> elem_buf(buffer.begin() + offset, buffer.begin() + offset + elem_size);
                result[i] = element_deserializer(elem_buf);
                offset += elem_size;
            }
            return result;

    }
    std::string GameUpdatePositionsPacket_to_string(GameUpdatePositionsPacket obj) {
        std::ostringstream oss;
            oss << "{";
            { auto conv = [=](const PacketHeader& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [=](PacketType value) -> std::string {
            switch(value) {
                case PacketType::UNIQUE_CLIENT_ID: return "PacketType::UNIQUE_CLIENT_ID";
                case PacketType::GAME_UPDATE_POSITIONS: return "PacketType::GAME_UPDATE_POSITIONS";
                case PacketType::GAME_UPDATE_ONE_TIME_EVENTS: return "PacketType::GAME_UPDATE_ONE_TIME_EVENTS";
                case PacketType::KEYBOARD_MOUSE_UPDATE: return "PacketType::KEYBOARD_MOUSE_UPDATE";
                default: return "<unknown PacketType>";
            }
        };
              oss << "type=" << conv(obj.type); }
            oss << ", ";
            { auto conv = [](const uint32_t &v) { return std::to_string(v); };
              oss << "size_of_data_without_header=" << conv(obj.size_of_data_without_header); }
            oss << "}";
            return oss.str();
        };
              oss << "header=" << conv(obj.header); }
            oss << ", ";
            { auto conv = [](const unsigned int &v) { return std::to_string(v); };
              oss << "id=" << conv(obj.id); }
            oss << ", ";
            { auto conv = [=](const std::vector<PositionArray>& vec) -> std::string {
            std::ostringstream oss;
            oss << "{";
            auto conversion = [=](const std::array<float, 3>& arr) -> std::string {
            std::ostringstream oss;
            oss << "{";
            auto conversion = [](const float &v) { return std::to_string(v); };
        
            for (size_t i = 0; i < arr.size(); ++i) {
                oss << conversion(arr[i]);
                if (i + 1 < arr.size())
                    oss << ", ";
            }
        
            oss << "}";
            return oss.str();
        };
        
            for (size_t i = 0; i < vec.size(); ++i) {
                oss << conversion(vec[i]);
                if (i + 1 < vec.size())
                    oss << ", ";
            }
        
            oss << "}";
            return oss.str();
        };
              oss << "positions=" << conv(obj.positions); }
            oss << "}";
            return oss.str();

    }
    GameUpdatePositionsPacket string_to_GameUpdatePositionsPacket(std::string &s) {
        GameUpdatePositionsPacket obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> PacketHeader {
            PacketHeader obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> PacketType {
            if (s == "PacketType::UNIQUE_CLIENT_ID") return PacketType::UNIQUE_CLIENT_ID;
            if (s == "PacketType::GAME_UPDATE_POSITIONS") return PacketType::GAME_UPDATE_POSITIONS;
            if (s == "PacketType::GAME_UPDATE_ONE_TIME_EVENTS") return PacketType::GAME_UPDATE_ONE_TIME_EVENTS;
            if (s == "PacketType::KEYBOARD_MOUSE_UPDATE") return PacketType::KEYBOARD_MOUSE_UPDATE;
            return static_cast<PacketType>(0); // default fallback
        };
                    obj.type = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<uint32_t>(std::stoul(s)); };
                    obj.size_of_data_without_header = conv(value_str);
                }
            }
            return obj;
        };
                    obj.header = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<unsigned int>(std::stoul(s)); };
                    obj.id = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &input) -> std::vector<PositionArray> {
            std::string trimmed = input;
            if (!trimmed.empty() && trimmed.front() == '{' && trimmed.back() == '}') {
                trimmed = trimmed.substr(1, trimmed.size() - 2);
            }
        
            std::vector<PositionArray> result;
            std::regex element_re(R"(.*)");
            auto begin = std::sregex_iterator(trimmed.begin(), trimmed.end(), element_re);
            auto end = std::sregex_iterator();
        
            for (auto it = begin; it != end; ++it) {
                try {
                    auto conversion = [=](const std::string &input) -> std::array<float, 3> {
            std::string trimmed = input;
            if (!trimmed.empty() && trimmed.front() == '{' && trimmed.back() == '}') {
                trimmed = trimmed.substr(1, trimmed.size() - 2);
            }
        
            std::array<float, 3> result{};
            std::regex element_re(R"(-?\d+(?:\.\d+)?)");
            auto begin = std::sregex_iterator(trimmed.begin(), trimmed.end(), element_re);
            auto end = std::sregex_iterator();
        
            size_t idx = 0;
            for (auto it = begin; it != end && idx < 3; ++it, ++idx) {
                try {
                    auto conversion = [](const std::string &s) { return std::stof(s); };
                    result[idx] = conversion(it->str());
                } catch (...) {
                    // Ignore malformed elements
                }
            }
            return result;
        };
                    result.push_back(conversion(it->str()));
                } catch (...) {
                    // Ignore malformed elements
                }
            }
            return result;
        };
                    obj.positions = conv(value_str);
                }
            }
            return obj;

    }
    std::vector<uint8_t> serialize_GameUpdatePositionsPacket(GameUpdatePositionsPacket obj) {
        std::vector<uint8_t> buffer;
            { auto ser = [=](const PacketHeader& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [=](PacketType value) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer(sizeof(uint8_t));
            uint8_t raw = static_cast<uint8_t>(value);
            std::memcpy(buffer.data(), &raw, sizeof(uint8_t));
            return buffer;
        };
              auto bytes = ser(obj.type);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const uint32_t &v) {   std::vector<uint8_t> buf(sizeof(uint32_t));   std::memcpy(buf.data(), &v, sizeof(uint32_t));   return buf; };
              auto bytes = ser(obj.size_of_data_without_header);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.header);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const unsigned int &v) {   std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf; };
              auto bytes = ser(obj.id);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const std::vector<PositionArray>& vec) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            size_t count = vec.size();
            buffer.resize(sizeof(size_t));
            std::memcpy(buffer.data(), &count, sizeof(size_t));
        
            auto element_serializer = [=](const std::array<float, 3>& arr) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            auto element_serializer = [](const float &v) {   std::vector<uint8_t> buf(sizeof(float));   std::memcpy(buf.data(), &v, sizeof(float));   return buf; };
            if (!arr.empty()) {
                size_t elem_size = sizeof(float);
                buffer.resize(buffer.size() + arr.size() * elem_size);
                std::memcpy(buffer.data(), arr.data(), arr.size() * elem_size);
            }
            return buffer;
        };
            if (!vec.empty()) {
                size_t elem_size = sizeof(PositionArray);
                buffer.resize(buffer.size() + vec.size() * elem_size);
                std::memcpy(buffer.data() + sizeof(size_t), vec.data(), vec.size() * elem_size);
            }
            return buffer;
        };
              auto bytes = ser(obj.positions);
              size_t len = bytes.size();
              buffer.resize(buffer.size() + sizeof(size_t));
              std::memcpy(buffer.data() + buffer.size() - sizeof(size_t), &len, sizeof(size_t));
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;

    }
    size_t size_when_serialized_GameUpdatePositionsPacket(GameUpdatePositionsPacket obj) {
        size_t total = 0;
            { auto size_fn = [=](const PacketHeader& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [=](const PacketType &obj) -> size_t {
            return sizeof(uint8_t);
        };
              total += size_fn(obj.type); }
            { auto size_fn = [](const uint32_t &v) { return sizeof(uint32_t); };
              total += size_fn(obj.size_of_data_without_header); }
            return total;
        };
              total += size_fn(obj.header); }
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id); }
            { auto size_fn = [=](const std::vector<PositionArray>& vec) -> size_t {
            size_t total_size = sizeof(size_t); // space for storing count
            if (!vec.empty()) {
                total_size += vec.size() * [=](const std::array<float, 3>& arr) -> size_t {
            size_t total_size = 0;
            if (!arr.empty()) {
                total_size += arr.size() * [](const float &v) { return sizeof(float); }(arr[0]);
            }
            return total_size;
        }(vec[0]);
            }
            return total_size;
        };
              total += sizeof(size_t); // length prefix
              total += size_fn(obj.positions); }
            return total;

    }
    GameUpdatePositionsPacket deserialize_GameUpdatePositionsPacket(std::vector<uint8_t> &buffer) {
        GameUpdatePositionsPacket obj;
            size_t offset = 0;
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> PacketHeader {
            PacketHeader obj;
            size_t offset = 0;
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> PacketType {
            if (buffer.size() < sizeof(uint8_t)) return static_cast<PacketType>(0);
            uint8_t raw = 0;
            std::memcpy(&raw, buffer.data(), sizeof(uint8_t));
            return static_cast<PacketType>(raw);
        };
              auto size_fn = [=](const PacketType &obj) -> size_t {
            return sizeof(uint8_t);
        };
              size_t len = size_fn(obj.type);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.type = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   uint32_t v;   std::memcpy(&v, buf.data(), sizeof(uint32_t));   return v; };
              auto size_fn = [](const uint32_t &v) { return sizeof(uint32_t); };
              size_t len = size_fn(obj.size_of_data_without_header);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.size_of_data_without_header = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const PacketHeader& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [=](const PacketType &obj) -> size_t {
            return sizeof(uint8_t);
        };
              total += size_fn(obj.type); }
            { auto size_fn = [](const uint32_t &v) { return sizeof(uint32_t); };
              total += size_fn(obj.size_of_data_without_header); }
            return total;
        };
              size_t len = size_fn(obj.header);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.header = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v; };
              auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              size_t len = size_fn(obj.id);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t>& buffer) -> std::vector<PositionArray> {
            std::vector<PositionArray> result;
            if (buffer.size() < sizeof(size_t)) return result;
            size_t count;
            std::memcpy(&count, buffer.data(), sizeof(size_t));
        
            size_t offset = sizeof(size_t);
            auto element_deserializer = [=](const std::vector<uint8_t>& buffer) -> std::array<float, 3> {
            std::array<float, 3> result{};
            auto element_deserializer = [](const std::vector<uint8_t> &buf) {   float v;   std::memcpy(&v, buf.data(), sizeof(float));   return v; };
        
            size_t offset = 0;
            size_t elem_size = sizeof(float);
            if (buffer.size() < 3 * elem_size) return result;
            for (size_t i = 0; i < 3; ++i) {
                std::vector<uint8_t> elem_buf(buffer.begin() + offset, buffer.begin() + offset + elem_size);
                result[i] = element_deserializer(elem_buf);
                offset += elem_size;
            }
            return result;
        };
            size_t elem_size = sizeof(PositionArray);
            if (offset + count * elem_size > buffer.size()) return result; // safety check
            for (size_t i = 0; i < count; ++i) {
                std::vector<uint8_t> elem_buf(buffer.begin() + offset, buffer.begin() + offset + elem_size);
                PositionArray elem = element_deserializer(elem_buf);
                result.push_back(elem);
                offset += elem_size;
            }
            return result;
        };
              if (offset + sizeof(size_t) > buffer.size()) return obj;
              size_t len = 0;
              std::memcpy(&len, buffer.data() + offset, sizeof(size_t));
              offset += sizeof(size_t);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.positions = deser(slice);
              offset += len;
            }
            return obj;

    }
    std::string MouseKeyboardUpdate_to_string(MouseKeyboardUpdate obj) {
        std::ostringstream oss;
            oss << "{";
            { auto conv = [](const bool &v) { return std::to_string(v); };
              oss << "fire_pressed=" << conv(obj.fire_pressed); }
            oss << ", ";
            { auto conv = [](const bool &v) { return std::to_string(v); };
              oss << "forward_pressed=" << conv(obj.forward_pressed); }
            oss << "}";
            return oss.str();

    }
    MouseKeyboardUpdate string_to_MouseKeyboardUpdate(std::string &s) {
        MouseKeyboardUpdate obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true" || s == "1"; };
                    obj.fire_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true" || s == "1"; };
                    obj.forward_pressed = conv(value_str);
                }
            }
            return obj;

    }
    std::vector<uint8_t> serialize_MouseKeyboardUpdate(MouseKeyboardUpdate obj) {
        std::vector<uint8_t> buffer;
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.fire_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.forward_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;

    }
    size_t size_when_serialized_MouseKeyboardUpdate(MouseKeyboardUpdate obj) {
        size_t total = 0;
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.fire_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.forward_pressed); }
            return total;

    }
    MouseKeyboardUpdate deserialize_MouseKeyboardUpdate(std::vector<uint8_t> &buffer) {
        MouseKeyboardUpdate obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.fire_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.fire_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.forward_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.forward_pressed = deser(slice);
              offset += len;
            }
            return obj;

    }
    std::string MouseKeyboardUpdatePacket_to_string(MouseKeyboardUpdatePacket obj) {
        std::ostringstream oss;
            oss << "{";
            { auto conv = [=](const PacketHeader& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [=](PacketType value) -> std::string {
            switch(value) {
                case PacketType::UNIQUE_CLIENT_ID: return "PacketType::UNIQUE_CLIENT_ID";
                case PacketType::GAME_UPDATE_POSITIONS: return "PacketType::GAME_UPDATE_POSITIONS";
                case PacketType::GAME_UPDATE_ONE_TIME_EVENTS: return "PacketType::GAME_UPDATE_ONE_TIME_EVENTS";
                case PacketType::KEYBOARD_MOUSE_UPDATE: return "PacketType::KEYBOARD_MOUSE_UPDATE";
                default: return "<unknown PacketType>";
            }
        };
              oss << "type=" << conv(obj.type); }
            oss << ", ";
            { auto conv = [](const uint32_t &v) { return std::to_string(v); };
              oss << "size_of_data_without_header=" << conv(obj.size_of_data_without_header); }
            oss << "}";
            return oss.str();
        };
              oss << "header=" << conv(obj.header); }
            oss << ", ";
            { auto conv = [](const unsigned int &v) { return std::to_string(v); };
              oss << "id=" << conv(obj.id); }
            oss << ", ";
            { auto conv = [=](const MouseKeyboardUpdate& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const bool &v) { return std::to_string(v); };
              oss << "fire_pressed=" << conv(obj.fire_pressed); }
            oss << ", ";
            { auto conv = [](const bool &v) { return std::to_string(v); };
              oss << "forward_pressed=" << conv(obj.forward_pressed); }
            oss << "}";
            return oss.str();
        };
              oss << "mku=" << conv(obj.mku); }
            oss << "}";
            return oss.str();

    }
    MouseKeyboardUpdatePacket string_to_MouseKeyboardUpdatePacket(std::string &s) {
        MouseKeyboardUpdatePacket obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> PacketHeader {
            PacketHeader obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> PacketType {
            if (s == "PacketType::UNIQUE_CLIENT_ID") return PacketType::UNIQUE_CLIENT_ID;
            if (s == "PacketType::GAME_UPDATE_POSITIONS") return PacketType::GAME_UPDATE_POSITIONS;
            if (s == "PacketType::GAME_UPDATE_ONE_TIME_EVENTS") return PacketType::GAME_UPDATE_ONE_TIME_EVENTS;
            if (s == "PacketType::KEYBOARD_MOUSE_UPDATE") return PacketType::KEYBOARD_MOUSE_UPDATE;
            return static_cast<PacketType>(0); // default fallback
        };
                    obj.type = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<uint32_t>(std::stoul(s)); };
                    obj.size_of_data_without_header = conv(value_str);
                }
            }
            return obj;
        };
                    obj.header = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<unsigned int>(std::stoul(s)); };
                    obj.id = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> MouseKeyboardUpdate {
            MouseKeyboardUpdate obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true" || s == "1"; };
                    obj.fire_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true" || s == "1"; };
                    obj.forward_pressed = conv(value_str);
                }
            }
            return obj;
        };
                    obj.mku = conv(value_str);
                }
            }
            return obj;

    }
    std::vector<uint8_t> serialize_MouseKeyboardUpdatePacket(MouseKeyboardUpdatePacket obj) {
        std::vector<uint8_t> buffer;
            { auto ser = [=](const PacketHeader& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [=](PacketType value) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer(sizeof(uint8_t));
            uint8_t raw = static_cast<uint8_t>(value);
            std::memcpy(buffer.data(), &raw, sizeof(uint8_t));
            return buffer;
        };
              auto bytes = ser(obj.type);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const uint32_t &v) {   std::vector<uint8_t> buf(sizeof(uint32_t));   std::memcpy(buf.data(), &v, sizeof(uint32_t));   return buf; };
              auto bytes = ser(obj.size_of_data_without_header);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.header);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const unsigned int &v) {   std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf; };
              auto bytes = ser(obj.id);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const MouseKeyboardUpdate& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.fire_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.forward_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.mku);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;

    }
    size_t size_when_serialized_MouseKeyboardUpdatePacket(MouseKeyboardUpdatePacket obj) {
        size_t total = 0;
            { auto size_fn = [=](const PacketHeader& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [=](const PacketType &obj) -> size_t {
            return sizeof(uint8_t);
        };
              total += size_fn(obj.type); }
            { auto size_fn = [](const uint32_t &v) { return sizeof(uint32_t); };
              total += size_fn(obj.size_of_data_without_header); }
            return total;
        };
              total += size_fn(obj.header); }
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id); }
            { auto size_fn = [=](const MouseKeyboardUpdate& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.fire_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.forward_pressed); }
            return total;
        };
              total += size_fn(obj.mku); }
            return total;

    }
    MouseKeyboardUpdatePacket deserialize_MouseKeyboardUpdatePacket(std::vector<uint8_t> &buffer) {
        MouseKeyboardUpdatePacket obj;
            size_t offset = 0;
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> PacketHeader {
            PacketHeader obj;
            size_t offset = 0;
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> PacketType {
            if (buffer.size() < sizeof(uint8_t)) return static_cast<PacketType>(0);
            uint8_t raw = 0;
            std::memcpy(&raw, buffer.data(), sizeof(uint8_t));
            return static_cast<PacketType>(raw);
        };
              auto size_fn = [=](const PacketType &obj) -> size_t {
            return sizeof(uint8_t);
        };
              size_t len = size_fn(obj.type);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.type = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   uint32_t v;   std::memcpy(&v, buf.data(), sizeof(uint32_t));   return v; };
              auto size_fn = [](const uint32_t &v) { return sizeof(uint32_t); };
              size_t len = size_fn(obj.size_of_data_without_header);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.size_of_data_without_header = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const PacketHeader& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [=](const PacketType &obj) -> size_t {
            return sizeof(uint8_t);
        };
              total += size_fn(obj.type); }
            { auto size_fn = [](const uint32_t &v) { return sizeof(uint32_t); };
              total += size_fn(obj.size_of_data_without_header); }
            return total;
        };
              size_t len = size_fn(obj.header);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.header = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v; };
              auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              size_t len = size_fn(obj.id);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> MouseKeyboardUpdate {
            MouseKeyboardUpdate obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.fire_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.fire_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.forward_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.forward_pressed = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const MouseKeyboardUpdate& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.fire_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.forward_pressed); }
            return total;
        };
              size_t len = size_fn(obj.mku);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.mku = deser(slice);
              offset += len;
            }
            return obj;

    }
};



} // namespace meta_program

#endif // META_PROGRAM_HPP
