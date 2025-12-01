#ifndef KOORI_LOGGER_LOGGER_H
#define KOORI_LOGGER_LOGGER_H

#include <Logging/Log.h>
#include <Output/ALogOutput.h>

#include <vector>

class Logger
{
public:
    Logger() = default;
    virtual ~Logger() = default;

    void RegisterLog(const Log& _log);

    template <typename T>
    ALogOutput* AddLogOuput()
    {
        ALogOutput* output = new T();
        m_LogOutputs.push_back(output);
        return output;
    }

    void RemoveLogOuput(ALogOutput* _output);

private:
    std::vector<ALogOutput*> m_LogOutputs{};

};

#endif //KOORI_LOGGER_LOGGER_H
