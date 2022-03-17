#pragma once
#include <string>
#include <fstream>
#include <thread>
#include <chrono>
#include "MessageQueue.h"

class FileLogger {
public:
    FileLogger(const std::string& path)
    {
        m_file.open(path);
        if (!m_file.is_open())
            throw std::runtime_error("Can't open file to log");

        m_thread = std::thread([&]() {
            using namespace std::chrono_literals;
            auto message_queue = m_message_queue.WaitAndPopAll(1ms);
            while (!message_queue.empty()) {
                auto message = std::move(message_queue.front());
                m_file << message.Get() << std::endl;
                message_queue.pop();
            }
        });
    }

    ~FileLogger() {
        m_thread.join();
        m_file.close();
    }

    template <class T>
    friend FileLogger& operator<< (FileLogger& logger, T value) {
        logger.m_message_queue.Push(Message(value));
        return logger;
    }

private: 
    std::ofstream m_file;
    std::thread m_thread;
    MessageQueue m_message_queue;
};
