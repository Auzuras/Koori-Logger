#include <gtest/gtest.h>

#include <Logger.h>
#include <source_location>
#include <Logging/Log.h>
#include <Utils/LoggerTime.h>

class LoggerTest : public testing::Test {};

TEST(LoggerTest, Date)
{
    Log log(LogSeverity::KL_DEFAULT, "Vulkan", L"Vk Swap Chain successfully created", L"Omg the swap chain is good", L"file", __func__, __LINE__, LogTime::GetLocalTime());

    std::wstring v = log.ToWString();
    std::wcout << v << std::endl;

    log = Log(LogSeverity::KL_ERROR, "Vulkan", L"Vk Swap Chain crashed", L"", L"file", __func__, __LINE__, LogTime::GetLocalTime());
    v = log.ToWString();
    std::wcout << v << std::endl;

    log = Log(LogSeverity::KL_WARNING, "Animation", L"Animation started", L"Animation failed to read quaternion", L"file", __func__, __LINE__, LogTime::GetLocalTime());
    v = log.ToWString();
    std::wcout << v << std::endl;
}