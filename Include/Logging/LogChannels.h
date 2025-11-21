#ifndef KOORI_LOGGER_LOGCHANNELS_H
#define KOORI_LOGGER_LOGCHANNELS_H

#include <cstdint>

enum class Channel : uint32_t
{
    Default     = 0x1 << 0x0,
    Warning     = 0x1 << 0x1,
    Error       = 0x1 << 0x2,
    Fatal       = 0x1 << 0x3
};

class LogChannel
{
public:
    LogChannel() = default;
};

#endif //KOORI_LOGGER_LOGCHANNELS_H