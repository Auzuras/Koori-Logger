#ifndef KOORI_LOGGER_ASSERT_H
#define KOORI_LOGGER_ASSERT_H

#include <Macros/Break.h>
#include <Macros/Exit.h>
#include <Macros/String.h>

/**
 * KOORI_CHECK Macro - Will break the program in debug configuration if the expression is evaluated to false
 * @param _expr Expression to verify
 */
#define KOORI_CHECK(_expr)																										\
	if (!_expr)																													\
	{																															\
		KOORI_WARN(L"Debug", KOORI_TEXT_WFORMAT(Check failed: "{}" expression is invalid!, KOORI_TEXT_WFORMAT(_expr)), L"");	\
		KOORI_BREAK();																											\
	}																															\

/**
 * KOORI_ASSERT Macro - Will break and then stop the program in debug configuration if the expression is evaluated to false
 * @param _expr Expression to verify
 */
#define KOORI_ASSERT(_expr)																										\
	if (!_expr)																													\
	{																															\
		KOORI_FATAL(L"Debug", KOORI_TEXT_WFORMAT(Assert failed: "{}" expression is invalid!, KOORI_TEXT_WFORMAT(_expr)), L"");	\
		KOORI_BREAK();																											\
		KOORI_EXIT();																											\
	}																															\

/**
 * KOORI_ENSURE Macro - Will break and then stop the programm in every configuration if the expression is evaluated to false
 * @param _expr Expression to verify
 */
#define KOORI_ENSURE(_expr)																										\
	if (!_expr)																													\
	{																															\
		KOORI_FATAL(L"Debug", KOORI_TEXT_WFORMAT(Ensure failed: "{}" expression is invalid!, KOORI_TEXT_WFORMAT(_expr)), L"");	\
		KOORI_BREAK();																											\
		KOORI_EXIT();																											\
	}																															\

#endif //KOORI_LOGGER_ASSERT_H