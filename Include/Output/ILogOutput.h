#ifndef KOORI_LOGGER_ILOGOUTPUT_H
#define KOORI_LOGGER_ILOGOUTPUT_H

#include <Logging/Log.h>

class ILogOutput
{
public:
    ILogOutput() = default;
    virtual ~ILogOutput() = default;

    virtual void WriteLog(const Log& _log) = 0;
};

#endif //KOORI_LOGGER_ILOGOUTPUT_H