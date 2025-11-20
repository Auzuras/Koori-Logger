
#ifndef KOORI_LOGGER_OUTOFRANGEEXCEPTION_H
#define KOORI_LOGGER_OUTOFRANGEEXCEPTION_H

#include <Exceptions/Exception.h>

class OutOfRangeException : public Exception
{
public:
    OutOfRangeException() = default;
    ~OutOfRangeException() override = default;
};

#endif //KOORI_LOGGER_OUTOFRANGEEXCEPTION_H