#include <gtest/gtest.h>

#include <Logger.h>
#include <Output/ConsoleOutput.h>
#include <Output/FileOutput.h>
#include <Macros/Function.h>
#include <Macros/File.h>
#include <Macros/Line.h>

class LoggerTest : public testing::Test {};

TEST(LoggerTest, Test)
{
    Logger logger{};

    const ALogOutput* consoleOut = logger.AddLogOutput<ConsoleOutput>();
    const ALogOutput* fileOut = logger.AddLogOutput<FileOutput>();

    Log log(LogSeverity::KL_DEBUG, L"Animation", L"Animation graph started", L"", KOORI_FILE, KOORI_FUNCTION, KOORI_LINE, LogTime::GetLocalTime());
    logger.Logging(log);

    log = Log(LogSeverity::KL_ERROR, L"Vulkan", L"Swap chain error", L"Lot of errors", KOORI_FILE, KOORI_FUNCTION, KOORI_LINE, LogTime::GetLocalTime());
    logger.Logging(log);

    logger.RemoveLogOutput(fileOut);
    logger.RemoveLogOutput(consoleOut);
}