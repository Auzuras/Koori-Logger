#include <Logging/Log.h>

#include <format>
#include <utility>

#include <windows.h>

Log::Log(const LogSeverity _severity, LogChannel& _channel, std::wstring& _message, std::wstring& _details, std::string& _fileName, std::string& _functionName, const uint32_t _lineNumber, const LogTime& _time)
    : severity(_severity), channel(_channel), message(std::move(_message)), details(std::move(_details)), fileName(std::move(_fileName)), functionName(std::move(_functionName)), lineNumber(_lineNumber), time(_time)
{
}

Log::Log(const LogSeverity _severity, LogChannel& _channel, std::wstring&& _message, std::wstring&& _details, std::string&& _fileName, std::string&& _functionName, const uint32_t _lineNumber, const LogTime& _time)
    : severity(_severity), channel(_channel), message(std::move(_message)), details(std::move(_details)), fileName(std::move(_fileName)), functionName(std::move(_functionName)), lineNumber(_lineNumber), time(_time)
{
}

std::wstring Log::ToWString() const
{
    const std::wstring function(functionName.begin(), functionName.end());
    const std::wstring file(fileName.begin(), fileName.end());

    /**
     * Create a string in the following format
     *
     * [dd/mm/yyyy - hh:mm:ss] [SEVERITY] - [file:line function] 
     * [Channel]: Main message
     * Details: details (optional)
     */

    std::wstring result = time.ToWString();

    result += std::format(L" [{}] ", LogSeverityToWString(severity));
    result += std::format(L"[{}:{} - {}]\n", file, std::to_wstring(lineNumber), function);
    result += std::format(L"[{}]: {}\n", channel.GetFullName(), message);

    if (!details.empty())
        result += L"Details: " + details + L'\n';

    result += L'\n';

    return result;
}