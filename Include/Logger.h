#ifndef KOORI_LOGGER_LOGGER_H
#define KOORI_LOGGER_LOGGER_H

#include <Logging/Log.h>

class Logger
{
public:
    Logger() = default;

    void Log(const Log& _log);
};

#endif //KOORI_LOGGER_LOGGER_H