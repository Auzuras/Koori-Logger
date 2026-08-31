#ifndef KOORI_LOGGER_LOG_MACRO_H
#define KOORI_LOGGER_LOG_MACRO_H

#include <Macros/MacroCommon.h>

#include <Logger.h>

#include <Logging/Log.h>

#include <Macros/File.h>
#include <Macros/Function.h>
#include <Macros/Line.h>

#include <Macros/Channel.h>

/**
 * The "overloaded" log macro is inspired by the following example:
 * https://stackoverflow.com/questions/11761703/overloading-macro-on-number-of-arguments
 */

/**
 * @brief __KOORI_LOG_FOUR_PARAMS Macro, complete version of the macro with four parameters
 * 
 * @param _level Level of the log
 * @param _channel Channel of the log
 * @param _message Message of the log
 * @param _details Details of the log
 */
#define __KOORI_LOG_FOUR_PARAMS(_level, _channel, _message, _details) G_DEFAULT_LOGGER->Logging(Log(_level, _channel, _message, _details, KOORI_FILE, KOORI_FUNCTION, KOORI_LINE, LogTime::GetLocalTime()));

/**
 * @brief __KOORI_LOG_FOUR_PARAMS Macro, three parameters version of the macro
 *
 * @param _level Level of the log
 * @param _channel Channel of the log
 * @param _message Message of the log
 */
#define __KOORI_LOG_THREE_PARAMS(_level, _channel, _message) __KOORI_LOG_FOUR_PARAMS(_level, _channel, _message, L"")

/**
 * @brief __KOORI_LOG_FOUR_PARAMS Macro, two parameters version of the macro
 *
 * @param _level Level of the log
 * @param _message Message of the log
 */
#define __KOORI_LOG_TWO_PARAMS(_level, _message) __KOORI_LOG_THREE_PARAMS(_level, Default, _message)

/**
 * @brief __KOORI_LOG_FOUR_PARAMS Macro, one parameter version of the macro
 *
 * @param _message Message of the log
 */
#define __KOORI_LOG_ONE_PARAM(_message) __KOORI_LOG_TWO_PARAMS(LogSeverity::KL_TRACE, _message)

/**
 * @brief Variadic KOORI_LOG MACRO, allows to write a custom message with modifiers
 * 
 * @param _level Level of the log
 * @param _channel Channel of the log
 * @param _message Message of the log
 * @param _details Details of the log
 * 
 * You can use this macro the following ways:
 * 
 * KOORI_LOG(_message)
 * 
 * KOORI_LOG(_level, _message)
 * 
 * KOORI_LOG(_level, channel, _message)
 * 
 * KOORI_LOG(_level, channel, _message, _details)
 */
#define KOORI_LOG(...) __KOORI_COMBINE(__KOORI_VARIADIC_FOUR_PARAMS(__VA_ARGS__, __KOORI_LOG_FOUR_PARAMS, __KOORI_LOG_THREE_PARAMS, __KOORI_LOG_TWO_PARAMS, __KOORI_LOG_ONE_PARAM)(__VA_ARGS__))

 /**
  * __KOORI_BASE_LOG_INTERNAL Macro - Simplification for DEBUG level
  * @param _severity Severity of the log
  * @param _channel Channel of the log
  * @param _message Message of the log
  * @param _details Details of the log
  */
#define __KOORI_BASE_LOG_INTERNAL(_severity, _channel, _message, _details) G_DEFAULT_LOGGER->Logging(Log(_severity, _channel, _message, _details, KOORI_FILE, KOORI_FUNCTION, KOORI_LINE, LogTime::GetLocalTime()))

 /**
  * KOORI_DEBUG Macro - Simplification for DEBUG level
  * @param _channel Channel of the log
  * @param _message Message of the log
  * @param _details Details of the log
  */
#define KOORI_TRACE(_channel, _message, _details) __KOORI_BASE_LOG_INTERNAL(LogSeverity::KL_TRACE, _channel, _message, _details)

/**
 * KOORI_DEBUG Macro - Simplification for DEBUG level
 * @param _channel Channel of the log
 * @param _message Message of the log
 * @param _details Details of the log
 */
#define KOORI_DEBUG(_channel, _message, _details) __KOORI_BASE_LOG_INTERNAL(LogSeverity::KL_DEBUG, _channel, _message, _details)

 /**
  * KOORI_DEBUG Macro - Simplification for DEBUG level
  * @param _channel Channel of the log
  * @param _message Message of the log
  * @param _details Details of the log
  */
#define KOORI_INFO(_channel, _message, _details) __KOORI_BASE_LOG_INTERNAL(LogSeverity::KL_INFO, _channel, _message, _details)

/**
 * KOORI_WARN Macro - Simplification for WARN level
 * @param _channel Channel of the log
 * @param _message Message of the log
 * @param _details Details of the log
 */
#define KOORI_WARN(_channel, _message, _details) __KOORI_BASE_LOG_INTERNAL(LogSeverity::KL_WARNING, _channel, _message, _details)

/**
 * KOORI_ERROR Macro - Simplification for ERROR level
 * @param _channel Channel of the log
 * @param _message Message of the log
 * @param _details Details of the log
 */
#define KOORI_ERROR(_channel, _message, _details) __KOORI_BASE_LOG_INTERNAL(LogSeverity::KL_ERROR, _channel, _message, _details)

/**
 * KOORI_FATAL Macro - Simplification for FATAL level
 * @param _channel Channel of the log
 * @param _message Message of the log
 * @param _details Details of the log
 */
#define KOORI_FATAL(_channel, _message, _details) __KOORI_BASE_LOG_INTERNAL(LogSeverity::KL_FATAL, _channel, _message, _details)

#endif //KOORI_LOGGER_LOG_MACRO_H