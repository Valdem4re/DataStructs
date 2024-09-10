#pragma once

#include "../Exceptions/LinkedListIndexError.h"
#include "../ListObject/ListObject.h"
#include <memory>

template <typename T> 
class OneLinkedList {
public:
    OneLinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}

    OneLinkedList(const OneLinkedList &other)
        : head_(other.head_), tail_(other.tail_) {
        auto currObj = other.head_;
        while (currObj) {
        push_back(currObj->get_data());
        currObj = currObj->get_next();
        }
        size_ = 1;
    }

    OneLinkedList(OneLinkedList<T> &&other) noexcept
        : head_(std::move(other.head_)), tail_(std::move(other.tail_)) {
        other.head_ = nullptr;
        other.tail_ = nullptr;
        size_ = 1;
    }

    OneLinkedList<T> &operator=(const OneLinkedList<T> &other) {
        if (this != &other) {
        clear();
        auto currObj = other.head_;
        while (currObj) {
            push_back(currObj->get_data());
            currObj = currObj->get_next();
        }
        }
        size_ = other.size_;
        return *this;
    }

    OneLinkedList<T> &operator=(OneLinkedList<T> &&other) noexcept {
        if (this != &other) {
        clear();
        head_ = std::move(other.head_);
        tail_ = std::move(other.tail_);
        other.head_ = nullptr;
        other.tail_ = nullptr;
        }
        size_ = other.size_;
        return *this;
    }

    virtual ~OneLinkedList() { clear(); }

    std::shared_ptr<ListObject<T>> get_head() const { return head_; }

    int size() const { return size_; }

    void push_back(T const &data);
    void push_back(const ListObject<T> &data);

    void push_front(const ListObject<T> &obj);
    void push_front(T const &data);

    void pop_back();
    void pop_front();

    private:
    std::shared_ptr<ListObject<T>> head_;
    std::shared_ptr<ListObject<T>> tail_;
    int size_;

    void clear() {
        while (head_)
        pop_front();
    }

    class Item{
        int index_{0};
        std::shared_ptr<OneLinkedList<T>> current_{nullptr};
        
        public:

        Item(OneLinkedList<T> *ptr, int index = 0) : current_(ptr), index_(index) {}

        operator T() const {
            if(index_ >= current_->size() || index_ < 0)
                throw LinkedListIndexError("Invalid element index.");
            auto currObj = current_->get_head();
            for (int i = 0; i < index_ && currObj; ++i) {
                currObj = currObj->get_next();
            }
            return currObj->get_data();
        }

        T operator=(const T value) {
            if(index_ >= current_->size() || index_ < 0)
                throw LinkedListIndexError("Invalid element index.");
            auto currObj = current_->get_head();
            for (int i = 0; i < index_ && currObj; ++i) {
                currObj = currObj->get_next();
            }
            currObj->set_data(value);
            return value;
        }
    };
    public:

    Item operator[](const int i) {
        return Item(this, i);
    }
};

// Implementation
template <typename T> void OneLinkedList<T>::push_back(T const &data) {
    auto newObj = std::make_shared<ListObject<T>>(data);
    if (tail_) {
        tail_->set_next(newObj);
    } else {
        head_ = newObj;
    }
    tail_ = newObj;
    size_++;
}

template <typename T>
void OneLinkedList<T>::push_back(const ListObject<T> &data) {
    auto newObj = std::make_shared<ListObject<T>>(data);
    if (tail_) {
        tail_->set_next(newObj);
    } else {
        head_ = newObj;
    }
    tail_ = newObj;
    size_++;
}

template <typename T>
void OneLinkedList<T>::push_front(const ListObject<T> &data) {
    auto newObj = std::make_shared<ListObject<T>>(data, head_);
    if (!tail_) {
        tail_ = newObj;
    }
    head_ = newObj;
    size_++;
}

template <typename T> void OneLinkedList<T>::push_front(T const &data) {
    auto newObj = std::make_shared<ListObject<T>>(data, head_);
    if (!tail_) {
        tail_ = newObj;
    }
    head_ = newObj;
    size_++;
}

template <typename T> void OneLinkedList<T>::pop_back() {
    if (!head_)
        return;

    if (head_ == tail_) {
        head_ = tail_ = nullptr;
        return;
    }

    auto currObj = head_;
    while (currObj->get_next() != tail_) {
        currObj = currObj->get_next();
    }

    currObj->set_next(nullptr);
    tail_ = currObj;
    size_--;
}

template <typename T> 
void OneLinkedList<T>::pop_front() {
    if (!head_)
        return;
    if (head_ == tail_) {
        head_ = tail_ = nullptr;
        return;
    }
    head_ = head_->get_next();
    size_--;
}
