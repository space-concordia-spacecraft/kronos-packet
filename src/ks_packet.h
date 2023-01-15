#pragma once

#include <cstdint>

#define KSP_BIT(x) (0x1 << x)

namespace kronos {

    namespace PacketFlags {
        enum T : uint8_t {
            More = KSP_BIT(0),
            Scheduled = KSP_BIT(1)
        };
    };

    struct PacketHeader {
        uint32_t PacketId;
        uint8_t PacketFlags;
        uint16_t CommandId;
        uint32_t CheckSum;
        uint32_t PayloadSize;
    } __attribute__((packed));

    struct Packet {
        PacketHeader Header;
        uint8_t Payload[40];
    } __attribute__((packed));

}


