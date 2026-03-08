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

    KOORI_TRACE(L"Game", L"Player is jumping", L"");

    KOORI_DEBUG(L"Game", L"Player position is: -18 5 157", L"");

    KOORI_INFO(L"Engine/Animation", L"Animation graph started", L"");

    KOORI_WARN(L"Engine", L"Config.ini is not loaded!", L"");

    KOORI_ERROR(L"Engine/Graphics/Vulkan", L"Swap chain error", L"Lot of errors");

    KOORI_FATAL(L"Engine/Graphics/Vulkan", L"No vulkand device found", L"Failed to find a suitable device!");

    KOORI_LOG(L"Loading Sponza.fbx");

    KOORI_LOG(LogSeverity::KL_INFO, L"Loading Sponza.fbx");

    KOORI_LOG(LogSeverity::KL_INFO, L"Engine/Resources", L"Loading Sponza.fbx");

    KOORI_LOG(LogSeverity::KL_INFO, L"Engine/Resources", L"Loading Sponza.fbx", L"Loading first submesh");

    G_DEFAULT_LOGGER->Assert(true == true);

    G_DEFAULT_LOGGER->RemoveLogOutput(fileOut);
    G_DEFAULT_LOGGER->RemoveLogOutput(consoleOut);
}