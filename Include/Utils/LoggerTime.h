#ifndef KOORI_LOGGER_LOGGERTIME_H
#define KOORI_LOGGER_LOGGERTIME_H

#include <cstdint>
#include <string>

struct tm;

struct LogTime
{
    uint8_t day = 0u;
    uint8_t month = 0u;
    uint16_t year = 0u;

    uint8_t hour = 0u;
    uint8_t minute = 0u;
    uint8_t second = 0u;

    LogTime(const tm& _time);

    static LogTime GetLocalTime();

    [[nodiscard]] std::wstring ToWString() const;
};

#endif //KOORI_LOGGER_LOGGERTIME_H