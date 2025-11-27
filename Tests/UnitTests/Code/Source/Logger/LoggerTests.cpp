#include <gtest/gtest.h>

#include <Logger.h>
#include <Utils/LoggerTime.h>

class LoggerTest : public testing::Test {};

TEST(LoggerTest, Date)
{
    LogTime time = LogTime::GetLocalTime();
    std::cout << +time.day << " " << +time.month << " " << +time.year << std::endl;
}