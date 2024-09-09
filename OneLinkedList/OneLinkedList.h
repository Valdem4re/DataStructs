#pragma once
#include "../ListObject/ListObject.h"
#include "../Exceptions/LinkedListIndexError.h"

template<typename T>
class OneLinkedList{
    public:

    OneLinkedList() : head_(nullptr), tail_(nullptr), size_(0) {};

    OneLinkedList(T data);

    OneLinkedList(ListObject<T>& obj);

    void push_back(const T& data);

    void push_back(const ListObject<T>& data);


    int size(void) const {return size_;}

    private:

    std::shared_ptr<ListObject<T>> head_{nullptr};
    std::shared_ptr<ListObject<T>> tail_{nullptr};
    int size_{0};



    class Item{
        public:

        Item(std::unique_ptr<OneLinkedList<T>> curr = nullptr, int idx = 0) : 
        current_(std::make_unique(curr)), index_(idx) {}

        operator T() const {
            if (current_->index < 0 || current_->index > current_->size())
                throw LinkedListIndexError("Invalid element index.");
        }

        T operator=(const T val) {
            if (current_->index < 0 || current_->index > current_->size())
                throw LinkedListIndexError("Invalid element index.");
        }

        private:
        std::unique_ptr<OneLinkedList<T>> current_{nullptr};
        int index_{0};
    };
};