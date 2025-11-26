#include <gtest/gtest.h>

#include <Logger.h>
#include <Utils/LoggerTime.h>

class LoggerTest : public testing::Test {};

TEST(LoggerTest, Date)
{
    LogTime time = LogTime::GetLocalTime();
}