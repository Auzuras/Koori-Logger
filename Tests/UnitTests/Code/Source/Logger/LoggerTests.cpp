#include <gtest/gtest.h>

#include <Logger.h>

class LoggerTest : public testing::Test {};

TEST(LoggerTest, Logs)
{
    Logger log;
}