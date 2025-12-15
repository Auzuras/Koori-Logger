#ifndef KOORI_LOGGER_FILE_H
#define KOORI_LOGGER_FILE_H

#if defined(__GNUG__)

	/*
	 * GNUG Version of the KOORI_FILE MACRO
	 * Return the name of the file where this macro is called
	 */
	#define KOORI_FILE __FILE_NAME__

#else

	/*
	 * Global Version of the KOORI_FILE MACRO
	 * Return the name of the file where this macro is called
	 */
	#define	KOORI_FILE FileFromPath(__FILE__) 

#endif

/**
 * Retrieve the name of the file from a complete path
 * Remove all // \\ in the path
 * @param _filePath Path of the file
 * @return The name of the file contained in the given path
 */
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