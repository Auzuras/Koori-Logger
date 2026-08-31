#ifndef KOORI_LOGGER_LOGGER_H
#define KOORI_LOGGER_LOGGER_H

#include <memory>
#include <Logging/Log.h>
#include <Output/ALogOutput.h>

#include <vector>

/**
 * @brief Base Logger class (Not thread safe)
 */
class Logger
{
public:

    /**
     * @brief Default Logger's constructor
     */
    Logger();

    /**
     * @brief Default Logger's destructor
     */
    virtual ~Logger();

    /**
     * @brief Logging function printing a log message in each registered output of the logger
     * @param _log Log reference that should be printed
     */
    void Logging(const Log& _log) const;

    /**
     * @brief Add a new log output in the logger
     * @tparam T Type of the log output
     * @return A pointer on the created output
     */
    template <typename T>
    ALogOutput* AddLogOutput()
    {
        ALogOutput* output = new T();
        m_LogOutputs.emplace_back(output);
        return output;
    }

    /**
     * Remove a log output specified in parameter
     * @param _output Pointer on the log output that should be deleted
     */
    void RemoveLogOutput(const ALogOutput* _output);

    /**
     * @brief Register a new logger to the global pointer
     * @param _logger Logger to register
     */
    static void RegisterLogger(const std::shared_ptr<Logger>& _logger);

    /**
     * @brief Destroy the global logger pointer
     */
    static void ClearLogger();

private:

    /**
     * Remove all the log outputs registered
     */
    void RemoveAllLogOutputs();

    /**
     * @brief Vector of all the registered log outputs
     */
    std::vector<ALogOutput*> m_LogOutputs{};
};

/**
 * @brief Global logger pointer used inside all of the macros of the logger
 */
inline std::shared_ptr<Logger> G_DEFAULT_LOGGER = std::make_shared<Logger>();

#endif //KOORI_LOGGER_LOGGER_H
