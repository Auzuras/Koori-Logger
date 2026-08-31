#ifndef KOORI_LOGGER_CHANNEL_H
#define KOORI_LOGGER_CHANNEL_H

#include <Logging/LogChannel.h>
#include <Macros/String.h>

#define KOORI_DECLARE_LOG_CHANNEL(_name) \
    inline LogChannel _name(KOORI_WSTRING(_name));

#define KOORI_DECLARE_LOG_CHANNEL_CHILD(_name, _parent) \
     inline LogChannel _name(KOORI_WSTRING(_name), &_parent);

KOORI_DECLARE_LOG_CHANNEL(Default);
KOORI_DECLARE_LOG_CHANNEL(Debug);

#endif //KOORI_LOGGER_CHANNEL_H