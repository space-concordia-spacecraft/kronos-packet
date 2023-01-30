#pragma once

#include "ks_crc.h"
#include "ks_packet.h"
#include "ks_command_ids.h"

#include <cstddef>
#include <algorithm>

extern "C" {
void* memcpy(void* dest, const void* src, size_t n);
}

namespace kronos {

    void EncodePacket(Packet& dest, uint8_t flags, uint16_t command, const uint8_t* payload, uint8_t payloadSize);
    void EncodePacket(Packet& dest, uint32_t packetId, uint8_t flags, uint16_t command, const uint8_t* payload, uint8_t payloadSize);
    void EncodePacketPart(Packet& dest, uint8_t flags, uint16_t command, KspPacketIdxType part, const uint8_t* payload, uint8_t payloadSize);

    int32_t ValidatePacketHeader(const PacketHeader& header);
    bool ValidatePacket(Packet& packet);

    inline size_t GetPacketSize(const Packet& packet) {
        return packet.Header.PayloadSize + sizeof(packet.Header);
    }

    inline size_t GetPayloadSizePart(const Packet& packet) {
        return packet.Header.PayloadSize - sizeof(KspPacketIdxType);
    }
}