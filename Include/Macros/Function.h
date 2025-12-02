#ifndef KOORI_LOGGER_FUNCTION_H
#define KOORI_LOGGER_FUNCTION_H

#if defined(_MSC_VER)

#define KOORI_FUNCTION __FUNCSIG__

#elif defined(__GNUG__)

#define KOORI_FUNCTION __PRETTY_FUNCTION__

#else

#define	KOORI_FUNCTION __FUNCTION__ 

#endif

#endif //KOORI_LOGGER_FUNCTION_H