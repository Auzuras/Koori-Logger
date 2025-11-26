#ifndef KOORI_LOGGER_LOG_H
#define KOORI_LOGGER_LOG_H

#include <cstdint>
#include <string>

#include <Logging/LogSeverity.h>
#include <Utils/LoggerTime.h>

class Log
{
public:
    Log(LogSeverity severity, std::string _channel, std::wstring _message, std::wstring _fileName, std::string _functionName, uint32_t _lineNumber, LogTime _time);
    ~Log() = default;

    LogSeverity severity = LogSeverity::KL_TRACE;
    std::string channel = "Default";

    std::wstring message = L"Hello World!";
    std::wstring details = L"Some details";

    std::wstring fileName = L"main.cpp";
    std::string functionName = "main";
    uint32_t lineNumber = 0u;

    LogTime time;

    std::wstring ToWString();
};

#endif //KOORI_LOGGER_LOG_H