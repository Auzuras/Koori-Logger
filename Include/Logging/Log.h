#ifndef KOORI_LOGGER_LOG_H
#define KOORI_LOGGER_LOG_H

#include <cstdint>
#include <string>

#include <Logging/LogSeverity.h>
#include <Utils/LoggerTime.h>

/**
 * Log class - Describes a message defined by a user
 */
class Log
{
public:

    /**
     * Main log class constructor
     * @param _severity Severity of the log
     * @param _channel Channel of the log
     * @param _message Message of the log
     * @param _details Details of the log
     * @param _fileName File of the log
     * @param _functionName Function of the log
     * @param _lineNumber Line of the log
     * @param _time Time of the log
     */
    Log(LogSeverity _severity, std::wstring& _channel, std::wstring& _message, std::wstring& _details, std::string& _fileName, std::string& _functionName, uint32_t _lineNumber, const LogTime& _time);

    /**
     * Default Log's destructor
     */
    ~Log() = default;

    /**
     * Format the class variables into a readable wstring
     * @return A wstring corresponding to the logging format
     */
    [[nodiscard]] std::wstring ToWString() const;

public:

    /**
     * Severity of the log
     */
    LogSeverity severity = LogSeverity::KL_TRACE;

    /**
     * Channel associated to the log
     */
    std::wstring channel = L"Default";

    /**
     * Main message of the log
     */
    std::wstring message = L"Hello World!";

    /**
     * Details of the log
     */
    std::wstring details = L"Some details";

    /**
     * File where the log is called
     */
    std::string fileName = "main.cpp";

    /**
     * Function where the log is called
     */
    std::string functionName = "main";

    /**
     * Line of the file where the log is called
     */
    uint32_t lineNumber = 0u;

    /**
     * Date and time of the log
     */
    LogTime time;
};

#endif //KOORI_LOGGER_LOG_H