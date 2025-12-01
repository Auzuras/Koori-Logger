#include <gtest/gtest.h>

#include <Logger.h>
#include <Output/ConsoleOutput.h>

class LoggerTest : public testing::Test {};

TEST(LoggerTest, Test)
{
    Logger logger{};

    ILogOutput* cOut = logger.AddLogOuput<ConsoleOutput>();

    Log log(LogSeverity::KL_DEBUG, "test", L"IDK", L"", L"File", __func__, __LINE__, LogTime::GetLocalTime());
    logger.RegisterLog(log);

    log = Log(LogSeverity::KL_ERROR, "Vulkan", L"Swap chain error", L"Lot of errors", L"File", __func__, __LINE__, LogTime::GetLocalTime());
    logger.RegisterLog(log);

    logger.RemoveLogOuput(cOut);
}