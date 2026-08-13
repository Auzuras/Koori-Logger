#include <Utils/LoggerTime.h>

#include <format>

LogTime::LogTime(const tm& _time)
{
    const uint8_t m = 12u;

    date = __KOORI_LOGGER_WRITE_DAY(date, _time.tm_mday);
    date = __KOORI_LOGGER_WRITE_MONTH(date, _time.tm_mon + 1u);
    date = __KOORI_LOGGER_WRITE_YEAR(date, _time.tm_year - 100u);

    uint8_t hour = _time.tm_hour % m;
    if (hour == 0) hour = m;
    isPM = _time.tm_hour >= m;

    ltime = __KOORI_LOGGER_WRITE_HOUR(ltime, _time.tm_hour - m);
    ltime = __KOORI_LOGGER_WRITE_MINUTE(ltime, _time.tm_min);
    ltime = __KOORI_LOGGER_WRITE_SECOND(ltime, _time.tm_sec);
}

LogTime LogTime::GetLocalTime()
{
    const time_t now = time(nullptr);
    struct tm* time = localtime(&now);
    return {*time};
}

std::wstring LogTime::ToWString() const
{
    // TODO: Add different time format
    // TODO: Refactor a bit
    return std::format(
        L"[{:02}/{:02}/{:02} | {:02}:{:02}:{:02}]", 
        __KOORI_LOGGER_READ_YEAR(date), __KOORI_LOGGER_READ_MONTH(date), __KOORI_LOGGER_READ_DAY(date), 
        isPM ? __KOORI_LOGGER_READ_HOUR(ltime) + 12u : __KOORI_LOGGER_READ_HOUR(ltime), __KOORI_LOGGER_READ_MINUTE(ltime), __KOORI_LOGGER_READ_SECOND(ltime)
    );
}
