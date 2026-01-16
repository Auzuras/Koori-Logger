#ifndef KOORI_LOGGER_LOGMACRO_H
#define KOORI_LOGGER_LOGMACRO_H

#include <Logger.h>

#include <Logging/Log.h>

#include <Macros/File.h>
#include <Macros/Function.h>
#include <Macros/Line.h>

/**
 *
 * @param _channel
 * @param _message
 * @param _details
 */
#define KOORI_LOG(_channel, _message, _details) G_DEFAULT_LOGGER.Logging(Log(LogSeverity::KL_DEBUG, _channel, _message, _details, KOORI_FILE, KOORI_FUNCTION, KOORI_LINE, LogTime::GetLocalTime()));

/**
 *
 * @param _channel
 * @param _message
 * @param _details
 */
#define KOORI_WARN(_channel, _message, _details) G_DEFAULT_LOGGER.Logging(Log(LogSeverity::KL_WARNING, _channel, _message, _details, KOORI_FILE, KOORI_FUNCTION, KOORI_LINE, LogTime::GetLocalTime()));

/**
 *
 * @param _channel
 * @param _message
 * @param _details
 */
#define KOORI_ERROR(_channel, _message, _details) G_DEFAULT_LOGGER.Logging(Log(LogSeverity::KL_ERROR, _channel, _message, _details, KOORI_FILE, KOORI_FUNCTION, KOORI_LINE, LogTime::GetLocalTime()));

#endif //KOORI_LOGGER_LOGMACRO_H