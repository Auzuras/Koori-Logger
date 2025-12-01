#include <Output/ConsoleOutput.h>

#include <iostream>

ConsoleOutput::~ConsoleOutput() {}

void ConsoleOutput::WriteLog(const Log& _log)
{
    std::wcout << _log.ToWString();
}
