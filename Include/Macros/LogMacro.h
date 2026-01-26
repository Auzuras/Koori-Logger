#ifndef KOORI_LOGGER_LOG_MACRO_H
#define KOORI_LOGGER_LOG_MACRO_H

#include <Logger.h>

#include <Logging/Log.h>

#include <Macros/File.h>
#include <Macros/Function.h>
#include <Macros/Line.h>

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
#define __KOORI_LOG_TWO_PARAMS(_level, _message) __KOORI_LOG_THREE_PARAMS(_level, L"Default", _message)

/**
 * @brief __KOORI_LOG_FOUR_PARAMS Macro, one parameter version of the macro
 *
 * @param _message Message of the log
 */
#define __KOORI_LOG_ONE_PARAM(_message) __KOORI_LOG_TWO_PARAMS(LogSeverity::KL_DEBUG, _message)

/**
 * @brief __KOORI_COMBINE Combine macro
 * 
 * @param _x Combine the parameters value
 */
#define __KOORI_COMBINE(_x) _x

/**
 * @brief __KOORI_LOG_INTERNAL Macro, selects the correct macro according to the number of arguments
 *
 * @param _1 First variadic parameter
 * @param _2 Second variadic parameter
 * @param _3 Third variadic parameter
 * @param _4 Fourth variadic parameter
 * @param _name Name of the selected macro
 * @param ... Other parameters
 */
#define __KOORI_LOG_INTERNAL(_1, _2, _3, _4, _name, ...) _name

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
#define KOORI_LOG(...) __KOORI_COMBINE(__KOORI_LOG_INTERNAL(__VA_ARGS__, __KOORI_LOG_FOUR_PARAMS, __KOORI_LOG_THREE_PARAMS, __KOORI_LOG_TWO_PARAMS, __KOORI_LOG_ONE_PARAM)(__VA_ARGS__))

/**
 * KOORI_DEBUG Macro - Simplification for DEBUG level
 * @param _channel Channel of the log
 * @param _message Message of the log
 * @param _details Details of the log
 */
#define KOORI_DEBUG(_channel, _message, _details) G_DEFAULT_LOGGER->Logging(Log(LogSeverity::KL_DEBUG, _channel, _message, _details, KOORI_FILE, KOORI_FUNCTION, KOORI_LINE, LogTime::GetLocalTime()));

/**
 * KOORI_WARN Macro - Simplification for WARN level
 * @param _channel Channel of the log
 * @param _message Message of the log
 * @param _details Details of the log
 */
#define KOORI_WARN(_channel, _message, _details) G_DEFAULT_LOGGER->Logging(Log(LogSeverity::KL_WARNING, _channel, _message, _details, KOORI_FILE, KOORI_FUNCTION, KOORI_LINE, LogTime::GetLocalTime()));

/**
 * KOORI_ERROR Macro - Simplification for ERROR level
 * @param _channel Channel of the log
 * @param _message Message of the log
 * @param _details Details of the log
 */
#define KOORI_ERROR(_channel, _message, _details) G_DEFAULT_LOGGER->Logging(Log(LogSeverity::KL_ERROR, _channel, _message, _details, KOORI_FILE, KOORI_FUNCTION, KOORI_LINE, LogTime::GetLocalTime()));

/**
 * KOORI_FATAL Macro - Simplification for FATAL level
 * @param _channel Channel of the log
 * @param _message Message of the log
 * @param _details Details of the log
 */
#define KOORI_FATAL(_channel, _message, _details) G_DEFAULT_LOGGER->Logging(Log(LogSeverity::KL_FATAL, _channel, _message, _details, KOORI_FILE, KOORI_FUNCTION, KOORI_LINE, LogTime::GetLocalTime()));

#endif //KOORI_LOGGER_LOG_MACRO_H