#ifndef KOORI_LOGGER_LOGGER_H
#define KOORI_LOGGER_LOGGER_H

#include <Logging/Log.h>
#include <Output/ILogOutput.h>

#include <vector>

class Logger
{
public:
    Logger() = default;
    virtual ~Logger() = default;

    void RegisterLog(const Log& _log);

    template <typename T>
    ILogOutput* AddLogOuput()
    {
        ILogOutput* output = new T();
        m_LogOutputs.push_back(output);
        return output;
    }

    void RemoveLogOuput(ILogOutput* _output);

private:
    std::vector<ILogOutput*> m_LogOutputs{};

};

#endif //KOORI_LOGGER_LOGGER_H
