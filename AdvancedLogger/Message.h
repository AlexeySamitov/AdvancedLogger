#pragma once
#include <variant>
#include <string>

class Message { 
    using supported_types = std::variant<int, double, std::string>;
public:
    Message(const supported_types& body): m_body(body){}

    Message(const Message&) = delete;
    Message& operator=(const Message&) = delete;
    Message(Message&&) = default;
    Message& operator=(Message&&) = default;

    std::string Get() const {
        return ToString(m_body);
    }
private:
    struct AnyGet {
        std::string operator()(int value) { return std::to_string(value); }
        std::string operator()(double value) { return std::to_string(value); }
        std::string operator()(const std::string& value) { return value; }
    };

    std::string ToString(const supported_types& input) const {
        return std::visit(AnyGet{}, input);
    }

    supported_types m_body;
};