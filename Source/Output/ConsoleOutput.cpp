#include <Output/ConsoleOutput.h>
#include <Output/ConsoleColor.h>

#include <iostream>

void ConsoleOutput::WriteLog(const Log& _log)
{
    ConsoleColor color(ConsoleColor::Color::KL_COLOR_BLACK);
    color.SetColor();
    std::wcout << _log.ToWString();
    color.ResetColor();
}
