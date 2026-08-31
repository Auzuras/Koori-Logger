#ifndef KOORI_LOGGER_LOG_SEVERITY_H
#define KOORI_LOGGER_LOG_SEVERITY_H

#include <cstdint>
#include <string>
#include <Output/ConsoleColor.h>

enum class LogSeverity : uint8_t
{
    KL_TRACE        =   0u,
    KL_DEBUG        =   1u,
    KL_INFO         =   2u,
    KL_WARNING      =   3u,
    KL_ERROR        =   4u,
    KL_FATAL        =   5u
};

static inline std::wstring LogSeverityToWString(LogSeverity _severity)
{
    switch (_severity)
    {
    case LogSeverity::KL_TRACE: default:    return L"TRACE";
    case LogSeverity::KL_DEBUG:             return L"DEBUG";
    case LogSeverity::KL_INFO:              return L"INFO";
    case LogSeverity::KL_WARNING:           return L"WARNING";
    case LogSeverity::KL_ERROR:             return L"ERROR";
    case LogSeverity::KL_FATAL:             return L"FATAL";
    }
}

#endif //KOORI_LOGGER_LOG_SEVERITY_H
