#pragma once

#include <cstdint>

#define KSP_BIT(x)              (0x1 << x)
#define KSP_MAGIC               0xA455
#define KSP_MAX_PAYLOAD_SIZE    41

namespace kronos {

    namespace PacketFlags {
        enum T : uint8_t {
            none = 0,
            eof = KSP_BIT(0),
            sched = KSP_BIT(1),
            ack = KSP_BIT(2)
        };
    };

    struct PacketHeader {
        uint16_t Magic;
        uint32_t PacketId;
        uint8_t PacketFlags;
        uint16_t CommandId;
        uint32_t CheckSum;
        uint8_t PayloadSize;
    } __attribute__((packed));

    struct Packet {
        PacketHeader Header;
        uint8_t Payload[KSP_MAX_PAYLOAD_SIZE];
    } __attribute__((packed));

}


