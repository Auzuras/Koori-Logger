#include <Logging/Log.h>

Log::Log(LogSeverity severity, std::string _channel, std::wstring _message, std::wstring _fileName, std::string _functionName, uint32_t _lineNumber, LogTime _time)
    : severity(severity), channel(_channel), message(_message), fileName(_fileName), functionName(_functionName), lineNumber(_lineNumber), time(_time)
{
}

std::wstring Log::ToWString()
{
    return L"Test";
}