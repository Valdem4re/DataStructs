#pragma once

#include <memory>
#include "../ListObject/ListObject.h"
#include "../Exceptions/LinkedListIndexError.h"

template<typename T>
class OneLinkedList : public std::enable_shared_from_this<OneLinkedList<T>> {
public:
    OneLinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}

    explicit OneLinkedList(T data);

    explicit OneLinkedList(const ListObject<T>& obj);

    std::shared_ptr<ListObject<T>> get_head() const { return head_; }

    void push_back(T const& data);
    void push_back(const ListObject<T>& data);

    void push_front(const ListObject<T>& obj);
    void push_front(T const& data);

    void pop_back();
    void pop_front();

    int size() const { return size_; }

    class Item {
    public:
        Item(std::weak_ptr<OneLinkedList<T>> curr = std::weak_ptr<OneLinkedList<T>>(), int idx = 0)
            : current_(curr), index_(idx) {}

        operator T() const {
            auto current = current_.lock();
            if (!current || index_ < 0 || index_ >= current->size())
                throw LinkedListIndexError("Invalid element index.");

            std::shared_ptr<ListObject<T>> curr = current->head_;
            for (int i = 0; i < index_; ++i)
                curr = curr->get_next();
            return curr->get_data();
        }

        void operator=(const T& val) {
            auto current = current_.lock();
            if (!current || index_ < 0 || index_ >= current->size())
                throw LinkedListIndexError("Invalid element index.");

            std::shared_ptr<ListObject<T>> curr_obj = current->head_;
            for (int i = 0; i < index_; ++i)
                curr_obj = curr_obj->get_next();
            curr_obj->set_data(val);
        }

    private:
        std::weak_ptr<OneLinkedList<T>> current_;
        int index_;
    };

    Item operator[](int index) {
        if (index < 0 || index >= size_)
            throw LinkedListIndexError("Index out of bounds.");
        return Item(this->shared_from_this(), index);
    }

private:
    std::shared_ptr<ListObject<T>> head_;
    std::shared_ptr<ListObject<T>> tail_;
    int size_;

    void initialize_list(const std::shared_ptr<ListObject<T>>& obj);
};

// Implementation

template<typename T>
OneLinkedList<T>::OneLinkedList(T data) {
    head_ = std::make_shared<ListObject<T>>(data);
    tail_ = head_;
    size_ = 1;
}

template<typename T>
OneLinkedList<T>::OneLinkedList(const ListObject<T>& obj) {
    size_ = 1;
    head_ = std::make_shared<ListObject<T>>(obj);

    auto current = head_;
    while (current->get_next()) {
        current = current->get_next();
        ++size_;
    }
    tail_ = current;
}

template<typename T>
void OneLinkedList<T>::push_back(T const& data) {
    auto newObj = std::make_shared<ListObject<T>>(data);

    if (!head_) {
        initialize_list(newObj);
    } else {
        tail_->set_next(newObj);
        tail_ = newObj;
        ++size_;
    }
}

template<typename T>
void OneLinkedList<T>::push_back(const ListObject<T>& data) {
    auto newObj = std::make_shared<ListObject<T>>(data);

    if (!head_) {
        initialize_list(newObj);
    } else {
        tail_->set_next(newObj);
        tail_ = newObj;
        ++size_;
    }
}

template<typename T>
void OneLinkedList<T>::push_front(const ListObject<T>& obj) {
    auto newObj = std::make_shared<ListObject<T>>(obj);

    if (!head_) {
        initialize_list(newObj);
    } else {
        newObj->set_next(head_);
        head_ = newObj;
        ++size_;
    }
}

template<typename T>
void OneLinkedList<T>::push_front(T const& data) {
    auto newObj = std::make_shared<ListObject<T>>(data);

    if (!head_) {
        initialize_list(newObj);
    } else {
        newObj->set_next(head_);
        head_ = newObj;
        ++size_;
    }
}

template<typename T>
void OneLinkedList<T>::pop_back() {
    if (size_ == 0) return;

    if (size_ == 1) {
        head_.reset();
        tail_.reset();
    } else {
        auto currObj = head_;
        while (currObj->get_next() != tail_) {
            currObj = currObj->get_next();
        }
        currObj->set_next(nullptr);
        tail_ = currObj;
    }
    --size_;
}

template<typename T>
void OneLinkedList<T>::pop_front() {
    if (size_ == 0) return;

    if (size_ == 1) {
        head_.reset();
        tail_.reset();
    } else {
        head_ = head_->get_next();
    }
    --size_;
}

template<typename T>
void OneLinkedList<T>::initialize_list(const std::shared_ptr<ListObject<T>>& obj) {
    head_ = obj;
    tail_ = obj;
    size_ = 1;
}
