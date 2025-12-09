#ifndef KOORI_LOGGER_LOGSEVERITY_H
#define KOORI_LOGGER_LOGSEVERITY_H

#include <cstdint>
#include <string>

enum class LogSeverity : uint32_t
{
    KL_TRACE        = 0x1 << 0x0,
    KL_DEBUG        = 0x1 << 0x1,
    KL_WARNING      = 0x1 << 0x2,
    KL_ERROR        = 0x1 << 0x3,
    KL_SUCCESS      = 0x1 << 0x4,
    KL_FAIL         = 0x1 << 0x5,
    KL_LOADING      = 0x1 << 0x6,
    KL_PROCESSING   = 0x1 << 0x7,
    KL_FATAL        = 0x1 << 0x8
};

static inline std::wstring LogSeverityToWString(LogSeverity severity)
{
    switch (severity)
    {
        case LogSeverity::KL_TRACE: default:
            return L"TRACE";
        case LogSeverity::KL_DEBUG:
            return L"DEBUG";
        case LogSeverity::KL_WARNING:
            return L"WARNING";
        case LogSeverity::KL_ERROR:
            return L"ERROR";
        case LogSeverity::KL_SUCCESS:
            return L"SUCCESS";
        case LogSeverity::KL_FAIL:
            return L"FAIL";
        case LogSeverity::KL_LOADING:
            return L"LOADING";
        case LogSeverity::KL_PROCESSING:
            return L"PROCESSING";
        case LogSeverity::KL_FATAL:
            return L"FATAL";
    }
}

#endif //KOORI_LOGGER_LOGSEVERITY_H
