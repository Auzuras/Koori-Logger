#ifndef KOORI_LOGGER_FILE_H
#define KOORI_LOGGER_FILE_H

#if defined(__GNUG__)

	#define KOORI_FILE __FILE_NAME__

#else

	#define	KOORI_FILE FileFromPath(__FILE__) 

#endif

static const char* FileFromPath(const char* _filePath)
{
	// strrchr returns the text with the last occurrence of a certain character
	const char* returnValue = strrchr(_filePath, '\\');

	if (returnValue)
		return &returnValue[1];

	// Do the same thing with a simple slash because the __FILE__ macro returns a different format
	// according to the compiler
	returnValue = strrchr(_filePath, '/');

	if (returnValue)
		return &returnValue[1];

	// Return the value from the second element because two backslash still exist
	return _filePath;
}

#endif //KOORI_LOGGER_FILE_H