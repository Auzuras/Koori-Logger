#include <Logger.h>

void Logger::Logging(const Log& _log) const
{
    // Simply go through all the outputs and write the message
    for (ALogOutput* output : m_LogOutputs)
        output->WriteLog(_log);
}

void Logger::Assert() const
{
    throw;
}

void Logger::RemoveLogOutput(const ALogOutput* _output)
{
    // Go through each outputs

    size_t index = 0;
    for (const ALogOutput* currentOutput : m_LogOutputs)
    {
        ++index; // Increment the current index of the output

        if (currentOutput != _output)
            continue;

        // Erase the output from the list according to its index
        m_LogOutputs.erase(m_LogOutputs.begin() + (index - 1));

        delete _output;

        // Early exit
        return;
    }
}

void Logger::RegisterLogger(const std::shared_ptr<Logger>& _logger)
{
    G_DEFAULT_LOGGER = _logger;
}

void Logger::RemoveLogger()
{
    G_DEFAULT_LOGGER.reset();
    G_DEFAULT_LOGGER = nullptr;
}
