#include "ks_packet_parser.h"

namespace kronos {

    static uint32_t s_NextPacketId = 0;

    void EncodePacket(Packet& dest, uint8_t flags, uint16_t command, const uint8_t* payload, uint8_t payloadSize) {
        dest = {
            .Header = {
                .Magic = KSP_MAGIC,
                .PacketId = s_NextPacketId++,
                .PacketFlags = flags,
                .CommandId = command,
                .CheckSum = 0,
                .PayloadSize = payloadSize
            },
            .Payload = {}
        };
        memcpy(dest.Payload, payload, payloadSize);
        dest.Header.CheckSum = CRC32((uint8_t*) &dest, sizeof(dest.Header) + dest.Header.PayloadSize);
    }

    int32_t ValidatePacketHeader(const PacketHeader& header) {
        if (header.Magic != KSP_MAGIC)
            return -1;
        return (int32_t) header.PayloadSize;
    }

    bool ValidatePacket(Packet& packet) {
        uint32_t crc = packet.Header.CheckSum;
        packet.Header.CheckSum = 0;

        uint32_t packetCrc = CRC32((uint8_t*) &packet, sizeof(packet.Header) + packet.Header.PayloadSize);
        packet.Header.CheckSum = crc;
        if (packetCrc != crc)
            return false;

        return true;
    }

}