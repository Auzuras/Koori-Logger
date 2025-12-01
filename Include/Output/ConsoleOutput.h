#ifndef KOORI_LOGGER_CONSOLEOUTPUT_H
#define KOORI_LOGGER_CONSOLEOUTPUT_H

#include <Output/ALogOutput.h>

class ConsoleOutput : public ALogOutput
{
public:
    ConsoleOutput() = default;
    ~ConsoleOutput() override;

    void WriteLog(const Log& _log) override;
};

#endif //KOORI_LOGGER_CONSOLEOUTPUT_H
