#ifndef KOORI_LOGGER_LOGSEVERITY_H
#define KOORI_LOGGER_LOGSEVERITY_H

#include <cstdint>

enum class LogSeverity : uint32_t
{
    KL_DEFAULT      = 0x1 << 0x0,
    KL_TRACE        = 0x1 << 0x1,
    KL_DEBUG        = 0x1 << 0x2,
    KL_WARNING      = 0x1 << 0x3,
    KL_ERROR        = 0x1 << 0x4,
    KL_SUCCESS      = 0x1 << 0x5,
    KL_FAIL         = 0x1 << 0x6,
    KL_LOADING      = 0x1 << 0x7,
    KL_PROCESSING   = 0x1 << 0x8,
    KL_FATAL        = 0x1 << 0x9
};

#endif //KOORI_LOGGER_LOGSEVERITY_H