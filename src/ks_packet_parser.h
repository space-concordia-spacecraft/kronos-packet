#pragma once

#include "ks_crc.h"
#include "ks_packet.h"

#include <cstddef>
#include <algorithm>

extern void *memcpy(void *dest, const void * src, size_t n);

namespace kronos {

    void EncodePacket(Packet* dest, uint8_t flags, uint16_t command, const uint8_t* payload, uint32_t payloadSize);
    int32_t DecodePacket(const uint8_t* buffer, uint32_t size, Packet* dest);

}