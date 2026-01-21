#ifndef KOORI_LOGGER_BREAK_H
#define KOORI_LOGGER_BREAK_H

#if defined(_MSC_VER)
	
	/*
	 * MSVC Version of the KOORI_BREAK MACRO
	 * Insert a breakpoint at the position of the macro
	 */
	#define KOORI_BREAK() __debugbreak()

#elif defined(__GNUG__)

	/*
	 * GNUG / CLANG Version of the KOORI_BREAK MACRO
	 * Insert a breakpoint at the position of the macro
	 */
	#define KOORI_BREAK() __builtin_trap()

#else

	#include <signal.h>

	/*
	 * General Version of the KOORI_BREAK MACRO
	 * Insert a breakpoint at the position of the macro
	 */
	#define KOORI_BREAK() raise(SIGTRAP)

#endif

#endif //KOORI_LOGGER_BREAK_H