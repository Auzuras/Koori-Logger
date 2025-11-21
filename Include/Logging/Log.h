#ifndef KOORI_LOGGER_LOG_H
#define KOORI_LOGGER_LOG_H

#include <string>

#include <Logging/LogChannels.h>

class Log
{
public:
    Log() = default;
    ~Log() = default;

    std::wstring message = L"Hello World!";
    Channel channel = Channel::Default;
};

#endif //KOORI_LOGGER_LOG_H