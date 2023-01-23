#pragma once

#define KS_CMD_PING                 0
#define KS_CMD_ECHO                 1
#define KS_CMD_DOWNLINK_BEGIN       2
#define KS_CMD_DOWNLINK_PART        3 // From satellite, sending part of a file/buffer
#define KS_CMD_DOWNLINK_FETCH       4 // From groundstation, request specific parts of a file/buffer
#define KS_CMD_DOWNLINK_CONTINUE    5 // From groundstation, after you've received successfully x packets
