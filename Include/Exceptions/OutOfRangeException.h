#ifndef KOORI_LOGGER_OUT_OF_RANGE_EXCEPTION_H
#define KOORI_LOGGER_OUT_OF_RANGE_EXCEPTION_H

#include <Exceptions/Exception.h>

class OutOfRangeException : public Exception
{
public:
    OutOfRangeException() = default;
    ~OutOfRangeException() override = default;
};

#endif //KOORI_LOGGER_OUT_OF_RANGE_EXCEPTION_H