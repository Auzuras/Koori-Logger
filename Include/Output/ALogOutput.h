#ifndef KOORI_LOGGER_ALOG_OUTPUT_H
#define KOORI_LOGGER_ALOG_OUTPUT_H

#include <Logging/Log.h>
#include <Logging/LogSeverity.h>
#include <Logging/LogChannel.h>

/**
 * Abstract base class for logging output
 */
class ALogOutput
{
public:

    /**
     * Default ALogOutput's constructor
     */
    ALogOutput() = default;

    /**
     * Default ALogOutput's destructor
     */
    virtual ~ALogOutput() = default;

    /**
     * Write a new log in the output
     * @param _log Reference of the log that should be written
     */
    virtual void WriteLog(const Log& _log) = 0;

    /**
     * Set the minimum severity of the log
     * @param _severity New severity of the log
     */
    void SetSeverity(const LogSeverity _severity) { p_Severity = _severity; }

    bool CanWriteLog(const Log& _log)
    {
        return _log.severity >= p_Severity;
    }

protected:

    /**
     * Minimal log severity of the output
     */
    LogSeverity p_Severity = LogSeverity::KL_TRACE;

    /**
     * List of the channels writting in the output
     */
    LogChannel p_Channels;
};

#endif //KOORI_LOGGER_ALOG_OUTPUT_H