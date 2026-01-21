#include <gtest/gtest.h>

#include <Macros/LogMacro.h>
#include <Macros/Assert.h>

#include <Output/ConsoleOutput.h>
#include <Output/FileOutput.h>

class LoggerTest : public testing::Test {};

TEST(LoggerTest, Test)
{
    const ALogOutput* consoleOut = G_DEFAULT_LOGGER->AddLogOutput<ConsoleOutput>();
    const ALogOutput* fileOut = G_DEFAULT_LOGGER->AddLogOutput<FileOutput>();

    KOORI_LOG(L"Animation", L"Animation graph started", L"");

    KOORI_WARN(L"T", L"IDK", L"");

    KOORI_ERROR(L"Vulkan", L"Swap chain error", L"Lot of errors");

    G_DEFAULT_LOGGER->Assert();

    G_DEFAULT_LOGGER->RemoveLogOutput(fileOut);
    G_DEFAULT_LOGGER->RemoveLogOutput(consoleOut);
}