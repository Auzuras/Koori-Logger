#include <gtest/gtest.h>

#include <Logger.h>
#include <Utils/LoggerTime.h>

class LoggerTest : public testing::Test {};

TEST(LoggerTest, Date)
{
    LogTime time = LogTime::GetLocalTime();
    std::cout << static_cast<int>(time.day) << " " << static_cast<int>(time.month) << " " << static_cast<int>(time.year) << std::endl;
}