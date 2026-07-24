#include <Utils/LoggerTime.h>

#include <format>

LogTime::LogTime(const tm& _time)
    :day(_time.tm_mday), month(_time.tm_mon + 1u), year(1900u + _time.tm_year), hour(_time.tm_hour), minute(_time.tm_min), second(_time.tm_sec)
{}

LogTime LogTime::GetLocalTime()
{
    const time_t now = time(nullptr);
    struct tm* time = localtime(&now);
    return {*time};
}

std::wstring LogTime::ToWString() const
{
    // TODO: Add different time format
    return std::format(L"[{:04}/{:02}/{:02} | {:02}:{:02}:{:02}]", year, month, day, hour, minute, second);
}
