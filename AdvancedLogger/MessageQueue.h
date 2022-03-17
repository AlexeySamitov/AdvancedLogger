#pragma once
#include <queue>
#include <condition_variable>
#include <variant>
#include "Message.h"

class MessageQueue
{
public:
    void Push(Message message) {
        {
            std::lock_guard<std::mutex> lock(m_mutex);

            m_queue.push(std::move(message));
        }

        m_event.notify_one();
    }

    template <class _Rep, class _Period>
    std::queue<Message> WaitAndPopAll(const std::chrono::duration<_Rep, _Period>& delay) {
        std::queue<Message> sendqueue;
        {
            std::unique_lock<std::mutex> lock(m_mutex);
            m_event.wait_for(lock, delay);
            sendqueue = std::move(m_queue);
        }
        return sendqueue;
    }

private:
    std::condition_variable m_event;
    std::queue<Message> m_queue;
    std::mutex m_mutex;
};
