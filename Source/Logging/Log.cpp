#include <Logging/Log.h>

Log::Log(const LogSeverity _severity, std::string _channel, std::wstring _message, std::wstring _details, std::string _fileName, std::string _functionName, const uint32_t _lineNumber, const LogTime& _time)
    : severity(_severity), channel(_channel), message(_message), details(_details), fileName(_fileName), functionName(_functionName), lineNumber(_lineNumber), time(_time)
{
}

std::wstring Log::ToWString() const
{
    std::wstring result = L"";
    std::wstring channelName(channel.begin(), channel.end());
    std::wstring function(functionName.begin(), functionName.end());
    std::wstring file(fileName.begin(), fileName.end());

    /*
     * Create a string in the following format
     *
     * [dd/mm/yyyy - hh/mm/ss] | Severity - Channel
     * {file:line - function} Main message
     * Details: details (optional)
     */

    result += L"[" + std::to_wstring(time.day) + L"/" + std::to_wstring(time.month) + L"/" + std::to_wstring(time.year);
    result += L" - " + std::to_wstring(time.hour) + L":" + std::to_wstring(time.minute) + L":" + std::to_wstring(time.second) + L"]";
    result += L" | " + LogSeverityToWString(severity) + L" - " ;
    result += channelName + L'\n';
    result += L'{' + file + L':' + std::to_wstring(lineNumber) + L" - " + function + L"} " +  message + L'\n';

    if (!details.empty())
        result += L"Details: " + details + L'\n';

    result += L'\n';

    return result;
}