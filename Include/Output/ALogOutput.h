#ifndef KOORI_LOGGER_ILOGOUTPUT_H
#define KOORI_LOGGER_ILOGOUTPUT_H

#include <Logging/Log.h>
#include <Logging/LogSeverity.h>
#include <Logging/LogChannels.h>

class ALogOutput
{
public:
    ALogOutput() = default;
    virtual ~ALogOutput() = default;

    virtual void WriteLog(const Log& _log) = 0;

protected:

    LogSeverity p_Severity = LogSeverity::KL_TRACE;
    LogChannel p_Channels;
};

#endif //KOORI_LOGGER_ILOGOUTPUT_H