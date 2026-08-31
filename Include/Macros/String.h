#ifndef KOORI_LOGGER_STRING_H
#define KOORI_LOGGER_STRING_H

#include <format>

#define KOORI_STRING(_expr) #_expr

#define __KOORI_WSTRING_IMPL(x) L#x

#define KOORI_WSTRING(x) __KOORI_WSTRING_IMPL(x)

#define KOORI_TEXT_WFORMAT(_expr, ...) std::format(KOORI_WSTRING(_expr), __VA_ARGS__)

#define KOORI_TEXT_FORMAT(_expr, ...) std::format(KOORI_STRING(_expr), __VA_ARGS__)

#endif //KOORI_LOGGER_STRING_H