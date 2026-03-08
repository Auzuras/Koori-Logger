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

    KOORI_DEBUG(L"Engine/Animation", L"Animation graph started", L"");

    KOORI_WARN(L"Engine", L"Config.ini is not loaded!", L"");

    KOORI_ERROR(L"Engine/Graphics/Vulkan", L"Swap chain error", L"Lot of errors");

    KOORI_LOG(L"Loading Sponza.fbx");

    KOORI_LOG(LogSeverity::KL_INFO, L"Loading Sponza.fbx");

    KOORI_LOG(LogSeverity::KL_INFO, L"Engine/Resources", L"Loading Sponza.fbx");

    KOORI_LOG(LogSeverity::KL_INFO, L"Engine/Resources", L"Loading Sponza.fbx", L"Loading first submesh");

    G_DEFAULT_LOGGER->Assert(false == true);

    G_DEFAULT_LOGGER->RemoveLogOutput(fileOut);
    G_DEFAULT_LOGGER->RemoveLogOutput(consoleOut);
}