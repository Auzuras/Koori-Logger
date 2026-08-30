#ifndef KOORI_LOGGER_EXIT_H
#define KOORI_LOGGER_EXIT_H

#if defined(_MSC_VER)

/*
 * MSVC Version of the KOORI_BREAK MACRO
 * Insert a breakpoint at the position of the macro
 */
#define KOORI_EXIT() _Exit(EXIT_FAILURE)

#else

#include <unistd.h>

/*
 * General Version of the KOORI_BREAK MACRO
 * Insert a breakpoint at the position of the macro
 */
#define KOORI_EXIT() _exit(EXIT_FAILURE)

#endif

#endif //KOORI_LOGGER_EXIT_H