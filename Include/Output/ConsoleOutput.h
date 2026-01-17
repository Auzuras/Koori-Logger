#ifndef KOORI_LOGGER_CONSOLE_OUTPUT_H
#define KOORI_LOGGER_CONSOLE_OUTPUT_H

#include <Output/ALogOutput.h>

/**
 * Console Output override of the Log Output abstract class
 */
class ConsoleOutput : public ALogOutput
{
public:

    /**
     * Default ConsoleOutput's constructor
     */
    ConsoleOutput() = default;

    /**
     * Override of the ConsoleOutput destructor
     */
    ~ConsoleOutput() override = default;

    /**
     * Write a log in a console output
     * @param _log Reference of the log that should be written in the console
     */
    void WriteLog(const Log& _log) override;
};

#endif //KOORI_LOGGER_CONSOLE_OUTPUT_H
