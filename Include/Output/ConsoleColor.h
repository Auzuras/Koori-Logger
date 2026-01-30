#ifndef KOORI_LOGGER_CONSOLE_COLOR_H
#define KOORI_LOGGER_CONSOLE_COLOR_H

enum class ConsoleColor : uint32_t
{
    KL_BLACK    =   0x0,
    KL_RED      =   0x1,
    KL_GREEN    =   0x2,
    KL_YELLOW   =   0x3,
    KL_BLUE     =   0x4,
    KL_MAGENTA  =   0x5,
    KL_CYAN     =   0x6,
    KL_WHITE    =   0x7
};

enum class ConsoleColorType : uint32_t
{
    KL_DARK     =   0x1E,
    KL_LIGHT    =   0x5A
};

#endif //KOORI_LOGGER_CONSOLE_COLOR_H