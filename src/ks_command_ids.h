#pragma once

#define KS_CMD_PING                 0
#define KS_CMD_TLE                  1
#define KS_CMD_ECHO                 2
#define KS_CMD_DOWNLINK_BEGIN       3
#define KS_CMD_DOWNLINK_PART        4 // From satellite, sending part of a file/buffer
#define KS_CMD_DOWNLINK_FETCH       5 // From groundstation, request specific parts of a file/buffer
#define KS_CMD_DOWNLINK_CONTINUE    6 // From groundstation, after you've received successfully x packets
#define KS_CMD_LIST_FILES           7
