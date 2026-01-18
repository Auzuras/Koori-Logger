#ifndef KOORI_LOGGER_ASSERT_H
#define KOORI_LOGGER_ASSERT_H

#include <Logger.h>

#define KOORI_ASSERT(_expr) if (_expr == true) G_DEFAULT_LOGGER->Assert();

#endif //KOORI_LOGGER_ASSERT_H