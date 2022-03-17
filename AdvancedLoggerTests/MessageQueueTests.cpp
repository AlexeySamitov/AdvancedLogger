#include "pch.h"
#include "../AdvancedLogger/MessageQueue.h"
#include "../AdvancedLogger/Message.h"
#include <chrono>

TEST(MessageQueueTests, RequredThat_Get_Returns_ReferenceMessage_WhenInitializeWithOneValue) {
    using namespace std::chrono_literals;

    std::string msg("test string");
    MessageQueue msg_queue;
    msg_queue.Push(Message(msg));
    auto result_msg = msg_queue.WaitAndPopAll(1ms);
    EXPECT_EQ(result_msg.front().Get(), msg);
}

TEST(MessageQueueTests, RequredThat_Get_Returns_TheSameNumberMessages_WhenInitializedWithMultipleValues) {
    using namespace std::chrono_literals;

    MessageQueue msg_queue;
    msg_queue.Push(Message("test string"));
    msg_queue.Push(Message(10));
    msg_queue.Push(Message(3.145));
    auto result_msg = msg_queue.WaitAndPopAll(1ms);
    EXPECT_EQ(result_msg.size(), 3);
}
