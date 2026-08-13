#ifndef KOORI_LOGGER_LOGGER_TIME_H
#define KOORI_LOGGER_LOGGER_TIME_H

#include <cstdint>
#include <string>

#define __KOORI_LOGGER_DAY_BIT_SHIFT 0
#define __KOORI_LOGGER_MONTH_BIT_SHIFT 5
#define __KOORI_LOGGER_YEAR_BIT_SHIFT 9

#define __KOORI_LOGGER_WRITE_DAY(_date, _day) \
    (_date | (_day   << __KOORI_LOGGER_DAY_BIT_SHIFT))

#define __KOORI_LOGGER_WRITE_MONTH(_date, _month) \
    (_date | (_month << __KOORI_LOGGER_MONTH_BIT_SHIFT))

#define __KOORI_LOGGER_WRITE_YEAR(_date, _year) \
    (_date | (_year << __KOORI_LOGGER_YEAR_BIT_SHIFT))

///

#define __KOORI_LOGGER_READ_DAY(_date) \
    ((_date >> __KOORI_LOGGER_DAY_BIT_SHIFT) & 0x1F)

#define __KOORI_LOGGER_READ_MONTH(_date) \
    ((_date >> __KOORI_LOGGER_MONTH_BIT_SHIFT) & 0xF)

#define __KOORI_LOGGER_READ_YEAR(_date) \
    (_date >> __KOORI_LOGGER_YEAR_BIT_SHIFT)

////

#define __KOORI_LOGGER_HOUR_BIT_SHIFT 0
#define __KOORI_LOGGER_MINUTE_BIT_SHIFT 4
#define __KOORI_LOGGER_SECOND_BIT_SHIFT 10

#define __KOORI_LOGGER_WRITE_HOUR(_time, _hour) \
    (_time | (_hour   << __KOORI_LOGGER_HOUR_BIT_SHIFT))

#define __KOORI_LOGGER_WRITE_MINUTE(_time, _minute) \
    (_time | (_minute << __KOORI_LOGGER_MINUTE_BIT_SHIFT))

#define __KOORI_LOGGER_WRITE_SECOND(_time, _second) \
    (_time | (_second << __KOORI_LOGGER_SECOND_BIT_SHIFT))

///

#define __KOORI_LOGGER_READ_HOUR(_time) \
    ((_time >> __KOORI_LOGGER_HOUR_BIT_SHIFT) & 0xF)

#define __KOORI_LOGGER_READ_MINUTE(_time) \
    ((_time >> __KOORI_LOGGER_MINUTE_BIT_SHIFT) & 0x3F)

#define __KOORI_LOGGER_READ_SECOND(_time) \
    (_time >> __KOORI_LOGGER_SECOND_BIT_SHIFT)

struct tm;

struct LogTime
{
    uint32_t date = 0u;
    uint16_t ltime = 0u;
    bool isPM = false;

    LogTime(const tm& _time);

    static LogTime GetLocalTime();

    [[nodiscard]] std::wstring ToWString() const;
};

#endif //KOORI_LOGGER_LOGGER_TIME_H