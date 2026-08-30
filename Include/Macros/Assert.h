#ifndef KOORI_LOGGER_ASSERT_H
#define KOORI_LOGGER_ASSERT_H

#include <Macros/MacroCommon.h>

#include <Macros/Break.h>
#include <Macros/Exit.h>
#include <Macros/String.h>

/**
 * KOORI_CHECK Macro - Will break the program in debug configuration if the expression is evaluated to false
 * @param _expr Expression to verify
 */
#define __KOORI_CHECK(_expr, _details)																								\
	if (!_expr)																														\
	{																																\
		KOORI_WARN(L"Debug", KOORI_TEXT_WFORMAT(Check failed: "{}" expression is invalid!, KOORI_TEXT_WFORMAT(_expr)), _details);	\
		KOORI_BREAK();																												\
	}																																\

/**
 * KOORI_ASSERT Macro - Will break and then stop the program in debug configuration if the expression is evaluated to false
 * @param _expr Expression to verify
 */
#define __KOORI_ASSERT(_expr, _details)																								\
	if (!_expr)																														\
	{																																\
		KOORI_FATAL(L"Debug", KOORI_TEXT_WFORMAT(Assert failed: "{}" expression is invalid!, KOORI_TEXT_WFORMAT(_expr)), _details);	\
		KOORI_BREAK();																												\
		KOORI_EXIT();																												\
	}	

/**
 * KOORI_ENSURE Macro - Will break and then stop the programm in every configuration if the expression is evaluated to false
 * @param _expr Expression to verify
 */
#define __KOORI_ENSURE(_expr, _details)																								\
	if (!_expr)																														\
	{																																\
		KOORI_FATAL(L"Debug", KOORI_TEXT_WFORMAT(Ensure failed: "{}" expression is invalid!, KOORI_TEXT_WFORMAT(_expr)), _details);	\
		KOORI_BREAK();																												\
		KOORI_EXIT();																												\
	}																																\				

#define __KOORI_CHECK_TWO_PARAMS(_expr, _details) __KOORI_CHECK(_expr, _details)

#define __KOORI_CHECK_ONE_PARAM(_expr) __KOORI_CHECK_TWO_PARAMS(_expr, L"")

#define KOORI_CHECK(...) __KOORI_COMBINE(__KOORI_VARIADIC_TWO_PARAMS(__VA_ARGS__, __KOORI_CHECK_TWO_PARAMS, __KOORI_CHECK_ONE_PARAM)(__VA_ARGS__))

//

#define __KOORI_ASSERT_TWO_PARAMS(_expr, _details) __KOORI_ASSERT(_expr, _details)

#define __KOORI_ASSERT_ONE_PARAM(_expr) __KOORI_ASSERT_TWO_PARAMS(_expr, L"")

#define KOORI_ASSERT(...) __KOORI_COMBINE(__KOORI_VARIADIC_TWO_PARAMS(__VA_ARGS__, __KOORI_ASSERT_ONE_PARAM, __KOORI_ASSERT_TWO_PARAMS)(__VA_ARGS__))

//

#define __KOORI_ENSURE_TWO_PARAMS(_expr, _details) __KOORI_ENSURE(_expr, _details)

#define __KOORI_ENSURE_ONE_PARAM(_expr) __KOORI_ENSURE_TWO_PARAMS(_expr, L"")

#define KOORI_ENSURE(...) __KOORI_COMBINE(__KOORI_VARIADIC_TWO_PARAMS(__VA_ARGS__, __KOORI_ENSURE_ONE_PARAM, __KOORI_ENSURE_TWO_PARAMS)(__VA_ARGS__))

#endif //KOORI_LOGGER_ASSERT_H