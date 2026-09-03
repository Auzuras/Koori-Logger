#ifndef KOORI_LOGGER_LOG_CHANNEL_H
#define KOORI_LOGGER_LOG_CHANNEL_H

#include <string>

class LogChannel
{
public:
    LogChannel() = default;
    LogChannel(std::wstring _name, LogChannel* _parent = nullptr);
    
    std::wstring GetName() const { return m_Name; }
    std::wstring GetFullName() const { return m_FullName; }

private:
    std::wstring m_Name = L"Default";
    std::wstring m_FullName = L"Default";
    LogChannel* m_Parent = nullptr;
};

#endif //KOORI_LOGGER_LOG_CHANNEL_H