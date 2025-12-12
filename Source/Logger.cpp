#include <Logger.h>

void Logger::RegisterLog(const Log& _log)
{
    for (ALogOutput* output : m_LogOutputs)
        output->WriteLog(_log);
}

void Logger::RemoveLogOutput(ALogOutput *_output)
{
    size_t index = 0;
    for (ALogOutput* output : m_LogOutputs)
    {
        ++index;
        if (output != _output)
            continue;

        m_LogOutputs.erase(m_LogOutputs.begin() + (index - 1));
        delete _output;
    }
}
