#include "ks_packet_parser.h"

namespace kronos {

    static uint32_t s_NextPacketId = 0;

    void EncodePacket(Packet* dest, uint8_t flags, uint16_t command, const uint8_t* payload, uint32_t payloadSize) {
        *dest = {
            .Header = {
                .PacketId = s_NextPacketId++,
                .PacketFlags = flags,
                .CommandId = command,
                .CheckSum = 0,
                .PayloadSize = payloadSize
            },
            .Payload = {}
        };
        memcpy(dest->Payload, payload, payloadSize);
        dest->Header.CheckSum = CRC32((uint8_t*)&dest, sizeof(dest->Header) + dest->Header.PayloadSize);
    }

    int32_t DecodePacket(Packet* dest, const uint8_t* buffer, uint32_t size) {
        *dest = {};
        memcpy(&dest->Header, buffer, std::min<uint32_t>(sizeof(dest->Header), size));
        memcpy(&dest->Payload, buffer + sizeof(dest->Header), std::min<uint32_t>(size - sizeof(dest->Header), dest->Header.PayloadSize));
        uint32_t packetSize = std::min<uint32_t>(sizeof(dest->Header) + dest->Header.PayloadSize, size);

        uint32_t crc = dest->Header.CheckSum;
        dest->Header.CheckSum = 0;

        uint32_t packetCrc = CRC32(buffer, packetSize);
        dest->Header.CheckSum = crc;
        if (packetCrc != crc)
            return -1;

        return (int32_t)packetSize;
    }

}