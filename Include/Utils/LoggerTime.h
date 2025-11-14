#ifndef KOORI_LOGGER_LOGGERTIME_H
#define KOORI_LOGGER_LOGGERTIME_H

#include <cstdint>

struct LogTime
{
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
    uint16_t milliSecond;
    uint32_t microSecond;
    uint32_t nanoSecond;
};

#endif //KOORI_LOGGER_LOGGERTIME_H