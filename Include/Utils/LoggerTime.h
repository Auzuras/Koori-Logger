#ifndef KOORI_LOGGER_LOGGERTIME_H
#define KOORI_LOGGER_LOGGERTIME_H

#include <cstdint>

struct tm;

struct LogTime
{
    uint8_t day;
    uint8_t month;
    uint8_t year;

    uint8_t hour;
    uint8_t minute;
    uint8_t second;

    LogTime(const tm& _time);

    static LogTime GetLocalTime();
};

#endif //KOORI_LOGGER_LOGGERTIME_H