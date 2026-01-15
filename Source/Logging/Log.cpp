#include <Logging/Log.h>

#include <format>
#include <utility>

Log::Log(const LogSeverity _severity, std::wstring& _channel, std::wstring& _message, std::wstring& _details, std::string& _fileName, std::string& _functionName, const uint32_t _lineNumber, const LogTime& _time)
    : severity(_severity), channel(std::move(_channel)), message(std::move(_message)), details(std::move(_details)), fileName(std::move(_fileName)), functionName(std::move(_functionName)), lineNumber(_lineNumber), time(_time)
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
    result += L" [" + LogSeverityToWString(severity) + L"] ";
    result += L'[' + file + L':' + std::to_wstring(lineNumber) + L" - " + function + L"]\n";

    result += L'[' + channel + L"]: " + message + L'\n';

    if (!details.empty())
        result += L"Details: " + details + L'\n';

    result += L'\n';

    return result;
}