#include <gtest/gtest.h>

#include <Logger.h>
#include <Output/ConsoleOutput.h>
#include <Output/FileOutput.h>
#include <Macros/Function.h>
#include <Macros/File.h>

class LoggerTest : public testing::Test {};

TEST(LoggerTest, Test)
{
    Logger logger{};

    ALogOutput* cOut = logger.AddLogOuput<ConsoleOutput>();
    ALogOutput* fOut = logger.AddLogOuput<FileOutput>();

    Log log(LogSeverity::KL_DEBUG, L"Animation", L"Animation graph started", L"", KOORI_FILE, KOORI_FUNCTION, __LINE__, LogTime::GetLocalTime());
    logger.RegisterLog(log);

    log = Log(LogSeverity::KL_ERROR, L"Vulkan", L"Swap chain error", L"Lot of errors", KOORI_FILE, KOORI_FUNCTION, __LINE__, LogTime::GetLocalTime());
    logger.RegisterLog(log);

    logger.RemoveLogOuput(fOut);
    logger.RemoveLogOuput(cOut);
}