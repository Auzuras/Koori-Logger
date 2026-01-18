#ifndef KOORI_LOGGER_EXCEPTION_H
#define KOORI_LOGGER_EXCEPTION_H

class Exception
{
public:
    Exception() = default;
    virtual ~Exception() = default;

    [[nodiscard]] virtual std::wstring GetMessage() const = 0;
};

#endif //KOORI_LOGGER_EXCEPTION_H