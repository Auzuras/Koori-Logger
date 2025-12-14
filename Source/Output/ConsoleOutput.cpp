#include <Output/ConsoleOutput.h>

#include <iostream>

void ConsoleOutput::WriteLog(const Log& _log)
{
    std::wcout << _log.ToWString();
}
