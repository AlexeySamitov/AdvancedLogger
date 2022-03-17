#include "pch.h"
#include "../AdvancedLogger/Message.h"

TEST(MessageTests, RequredThat_Get_NotThrow_WhenMessageCreatedWithString) {
    Message msg("string");
    EXPECT_NO_THROW(msg.Get());
}

TEST(MessageTests, RequredThat_Get_NotThrow_WhenMessageCreatedWithInt) {
    Message msg(10);
    EXPECT_NO_THROW(msg.Get());
}

TEST(MessageTests, RequredThat_Get_NotThrow_WhenMessageCreatedWithDouble) {
    Message msg(3.14);
    EXPECT_NO_THROW(msg.Get());
}
