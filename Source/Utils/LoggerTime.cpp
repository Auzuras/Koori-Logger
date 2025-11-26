#include <Utils/LoggerTime.h>

#include <time.h>

LogTime::LogTime(const tm& _time)
    :day(_time.tm_mday), month(_time.tm_mon + 1), year(_time.tm_year), hour(_time.tm_hour), minute(_time.tm_min), second(_time.tm_sec)
{}

LogTime LogTime::GetLocalTime()
{
    time_t now = time(0);
    struct tm* time = localtime(&now);
    return LogTime(*time);
}
