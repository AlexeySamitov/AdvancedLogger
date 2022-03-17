#include "pch.h"
#include "../AdvancedLogger/FileLogger.h"
#include <filesystem>

TEST(FileLoggerTests, RequredThat_FileLogger_Throws_WhenInitializeWithInvalidPath) {
    EXPECT_THROW(FileLogger("***"), std::runtime_error);
}

TEST(FileLoggerTests, RequredThat_FileLogger_Creates_LogFile_WhenInitialized) {
    const auto path = "file.log";

    {
        FileLogger logger(path);
    }

    std::filesystem::exists(path);
}

TEST(FileLoggerTests, RequredThat_FileLogger_WritesMessageToFile_WhenMessageAdded) {
    const auto path = "file.log";
    const auto message = "some message to test";

    {
        FileLogger logger(path);

        logger << message;
    }

    std::ifstream file;
    file.open(path);
    std::string buff;
    std::getline(file, buff);

    EXPECT_EQ(buff, message);
}
