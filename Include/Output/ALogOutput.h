#ifndef KOORI_LOGGER_ILOGOUTPUT_H
#define KOORI_LOGGER_ILOGOUTPUT_H

#include <Logging/Log.h>

class ALogOutput
{
public:
    ALogOutput() = default;
    virtual ~ALogOutput() = default;

    virtual void WriteLog(const Log& _log) = 0;
};

#endif //KOORI_LOGGER_ILOGOUTPUT_H