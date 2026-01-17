#ifndef KOORI_LOGGER_LOG_CHANNELS_H
#define KOORI_LOGGER_LOG_CHANNELS_H

#include <unordered_map>

class LogChannel
{
public:
    LogChannel() = default;

private:
    std::unordered_map<std::wstring, bool> m_Channels;
};

#endif //KOORI_LOGGER_LOG_CHANNELS_H