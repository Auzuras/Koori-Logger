#ifndef KOORI_LOGGER_LOG_H
#define KOORI_LOGGER_LOG_H

#include <cstdint>
#include <string>

#include <Logging/LogSeverity.h>
#include <Utils/LoggerTime.h>

class Log
{
public:
    Log(const LogSeverity _severity, std::string _channel, std::wstring _message, std::wstring _details, std::wstring _fileName, std::string _functionName, const uint32_t _lineNumber, const LogTime& _time);
    ~Log() = default;

    std::wstring ToWString() const;

    LogSeverity severity = LogSeverity::KL_TRACE;
    std::string channel = "Default";

    std::wstring message = L"Hello World!";
    std::wstring details = L"Some details";

    std::wstring fileName = L"main.cpp";
    std::string functionName = "main";
    uint32_t lineNumber = 0u;

    LogTime time;
};

#endif //KOORI_LOGGER_LOG_H