#include <Output/ConsoleColor.h>

#include <iostream>
#include <windows.h>

ConsoleColor::ConsoleColor(Color _color, Intensity _intensity, Target _target, Attribute _attribute)
{

}

void ConsoleColor::SetColor()
{
	//std::cout << "\033[" << "0" << ";" << "91" << "m";
	//HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(hOut, 8 << 4);
}

void ConsoleColor::ResetColor()
{
	std::cout << "\033[0m";
}

bool ConsoleColor::CheckForANSISupport()
{
	return WIN_CheckForANSISupport();
}

bool ConsoleColor::WIN_CheckForANSISupport()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD dwMode = 0;

	if (GetConsoleMode(hOut, &dwMode))
		return dwMode & ENABLE_VIRTUAL_TERMINAL_PROCESSING;

	return false;
}