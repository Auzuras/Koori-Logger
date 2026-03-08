#ifndef KOORI_LOGGER_LOG_SEVERITY_H
#define KOORI_LOGGER_LOG_SEVERITY_H

#include <cstdint>
#include <string>

enum class LogSeverity : uint32_t
{
    KL_TRACE        =   0x0,
    KL_DEBUG        =   0x1,
    KL_INFO         =   0x2,
    KL_WARNING      =   0x3,
    KL_ERROR        =   0x4,
    KL_FATAL        =   0x5
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
