#include <gtest/gtest.h>

#include <Macros/LogMacro.h>
#include <Macros/Assert.h>
#include <Macros/Channel.h>

#include <Utils/LoggerTime.h>

#include <Output/ConsoleOutput.h>
#include <Output/FileOutput.h>

class LoggerTest : public testing::Test {};

#include <cassert>

KOORI_DECLARE_LOG_CHANNEL(Game);
KOORI_DECLARE_LOG_CHANNEL(Engine);
KOORI_DECLARE_LOG_CHANNEL_CHILD(Animation, Engine);
KOORI_DECLARE_LOG_CHANNEL_CHILD(Graphics, Engine);
KOORI_DECLARE_LOG_CHANNEL_CHILD(Vulkan, Graphics);
KOORI_DECLARE_LOG_CHANNEL_CHILD(Resources, Engine);

TEST(LoggerTest, Test)
{
    const ALogOutput* fileOut = G_DEFAULT_LOGGER->AddLogOutput<FileOutput>();

    KOORI_CHECK(true == false);
    KOORI_CHECK(true == false, L"The expression is incorect, human error");

    KOORI_TRACE(Game, L"Player is jumping", L"");

    KOORI_DEBUG(Game, L"Player position is: -18 5 157", L"");

    KOORI_INFO(Animation, L"Animation graph started", L"");

    KOORI_WARN(Engine, L"Config.ini is not loaded!", L"");

    KOORI_ERROR(Vulkan, L"Swap chain error", L"Lot of errors");

    KOORI_FATAL(Vulkan, L"No vulkan device found", L"Failed to find a suitable device!");

    KOORI_LOG(L"Loading Sponza.fbx");

    KOORI_LOG(LogSeverity::KL_INFO, L"Loading Sponza.fbx");

    KOORI_LOG(LogSeverity::KL_INFO, Resources, L"Loading Sponza.fbx");

    KOORI_LOG(LogSeverity::KL_INFO, Resources, L"Loading Sponza.fbx", L"Loading first submesh");

    G_DEFAULT_LOGGER->RemoveLogOutput(fileOut);
}