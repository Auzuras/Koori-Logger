#ifndef KOORI_LOGGER_FUNCTION_H
#define KOORI_LOGGER_FUNCTION_H

#if defined(_MSC_VER)

	/*
	 * MSVC (Microsoft) Version of the KOORI_FUNCTION MACRO
	 * Return the name of the function where this macro is called
	 */
	#define KOORI_FUNCTION __FUNCSIG__

#elif defined(__GNUG__)

	/*
	 * GNUG Version of the KOORI_FUNCTION MACRO
	 * Return the name of the function where this macro is called
	 */
	#define KOORI_FUNCTION __PRETTY_FUNCTION__

#else

	/*
	 * Default Version of the KOORI_FUNCTION MACRO
	 * Return the name of the function where this macro is called
	 */
	#define	KOORI_FUNCTION __FUNCTION__ 

#endif

#endif //KOORI_LOGGER_FUNCTION_H