#ifndef KOORI_LOGGER_FILE_H
#define KOORI_LOGGER_FILE_H

#if defined(_MSC_VER)

	#define KOORI_FILE __FILE__

#elif defined(__GNUG__)

	#define KOORI_FILE __FILE_NAME__

#else

	#define	KOORI_FILE __FILE__ 

#endif

#endif //KOORI_LOGGER_FILE_H