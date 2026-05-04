#ifndef KOORI_LOGGER_CONSOLE_COLOR_H
#define KOORI_LOGGER_CONSOLE_COLOR_H

	enum class ConsoleColor : uint8_t
	{
	    KL_COLOR_BLACK    =		0x1E,
								
	    KL_COLOR_RED      =		0x0,
	    KL_COLOR_GREEN    =		0x1,
	    KL_COLOR_YELLOW   =		0x2,
	    KL_COLOR_BLUE     =		0x3,
	    KL_COLOR_MAGENTA  =		0x4,
	    KL_COLOR_CYAN     =		0x5,
	    //KL_COLOR_GRAY     =		,
	
	    KL_COLOR_WHITE    =		0x25,
	
		KL_COLOR_DARK	  = 0x1E,
		KL_COLOR_LIGHT	  = 0x5A,
		
		KL_COLOR_FOREGROUND,
		KL_COLOR_BACKGROUND,
	};

#endif //KOORI_LOGGER_CONSOLE_COLOR_H