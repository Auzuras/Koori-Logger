#include <Logger.h>

void Logger::Logging(const Log& _log) const
{
    for (ALogOutput* output : m_LogOutputs)
        output->WriteLog(_log);
}

void Logger::RemoveLogOutput(const ALogOutput* _output)
{
    size_t index = 0;
    for (const ALogOutput* currentOutput : m_LogOutputs)
    {
        ++index;
        if (currentOutput != _output)
            continue;

        m_LogOutputs.erase(m_LogOutputs.begin() + (index - 1));
        delete _output;
    }
}
