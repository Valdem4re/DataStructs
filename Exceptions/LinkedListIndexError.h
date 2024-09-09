#pragma once
#include <exception>
#include <string>
class LinkedListIndexError : public std::exception {
    public:

    LinkedListIndexError(const std::string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }

    private:
    std::string message;
};