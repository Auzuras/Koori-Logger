#ifndef KOORI_LOGGER_CONSOLEOUTPUT_H
#define KOORI_LOGGER_CONSOLEOUTPUT_H

#include <Output/ILogOutput.h>

class ConsoleOutput : public ILogOutput
{
public:
    ConsoleOutput() = default;
    ~ConsoleOutput() override;

    void WriteLog(const Log& _log) override;
};

#endif //KOORI_LOGGER_CONSOLEOUTPUT_H
