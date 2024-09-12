#pragma once
#include <exception>
#include <string>
class CustomException : public std::exception {
    public:

    CustomException(const std::string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }

    private:
    std::string message;
};


class LinkedListIndexError : public CustomException {
    public:

    LinkedListIndexError(const std::string& msg) : CustomException(msg) {}
};

class ListObjectError : public CustomException {
    public:
    ListObjectError(const std::string& msg) : CustomException(msg) {}
};