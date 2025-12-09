#include <Logging/Log.h>
#include <format>

Log::Log(const LogSeverity _severity, std::wstring _channel, std::wstring _message, std::wstring _details, std::string _fileName, std::string _functionName, const uint32_t _lineNumber, const LogTime& _time)
    : severity(_severity), channel(_channel), message(_message), details(_details), fileName(_fileName), functionName(_functionName), lineNumber(_lineNumber), time(_time)
{
}

std::wstring Log::ToWString() const
{
    const std::wstring function(functionName.begin(), functionName.end());
    const std::wstring file(fileName.begin(), fileName.end());

    /*
     * Create a string in the following format
     *
     * [dd/mm/yyyy - hh:mm:ss] [SEVERITY] - [file:line function] 
     * [Channel]: Main message
     * Details: details (optional)
     */

    std::wstring result = L'[' + std::format(L"{:02}/{:02}/{:04}", time.day, time.month, time.year);
    result += L" - " + std::format(L"{:02}:{:02}:{:02}", time.hour, time.minute, time.second) + L"] ";
    result += L'[' + LogSeverityToWString(severity) + L"] ";
    result += L'[' + file + L':' + std::to_wstring(lineNumber) + L" - " + function + L"]\n";

    result += L'[' + channel + L"]: " + message + L'\n';

    if (!details.empty())
        result += L"Details: " + details + L'\n';

    result += L'\n';

    return result;
}