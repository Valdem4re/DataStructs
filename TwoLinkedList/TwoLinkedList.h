#pragma once

#include "../Exceptions/Exceptions.h"
#include "../OneLinkedList/OneLinkedList.h"
#include <memory>

/*
The difference between a OneLinkedList and TwoLinkedList is that a ListObject for TwoLinkedList has a pointer to the previous element,
this is implemented in ListObject.h and uses with special directive TWO_LINKED_LIST.

This class only contains some minor optimizations for some methods
*/
template<typename T>
class TwoLinkedList : public OneLinkedList<T> {
    public:

    void insert(const size_t idx, const T& data) override;

    void insert(const size_t idx, const ListObject<T>& data) override;

    void erase(const size_t idx) override;
};

template<typename T>
void TwoLinkedList<T>::insert(const size_t idx, const T& data) {
    if (idx > this->size_) 
        throw LinkedListIndexError("Invalid element index.");

    auto newObj = std::make_shared<ListObject<T>>(data);

    if(idx == 0) {
        newObj->set_next(this->head_);
        if (this->head_) {
            this->head_->set_prev(newObj); 
        }
        this->head_ = newObj;
    }
    else {
        if (idx > this->size_ / 2) {
            auto currObj = this->tail_;
            for (size_t i = this->size_; i > idx && currObj; --i) {
                currObj = currObj->get_prev();
            }
            newObj->set_next(currObj->get_next());
            newObj->set_prev(currObj); 
            if (currObj->get_next()) {
                currObj->get_next()->set_prev(newObj);
            }
            currObj->set_next(newObj);
        }
        else {
            auto currObj = this->head_;
            for (size_t i = 0; i < idx - 1 && currObj; ++i) {
                currObj = currObj->get_next();
            }
            newObj->set_next(currObj->get_next());
            newObj->set_prev(currObj); 
            if (currObj->get_next()) {
                currObj->get_next()->set_prev(newObj);
            }
            currObj->set_next(newObj);
        }
    }
    ++this->size_;
}

template<typename T>
void TwoLinkedList<T>::insert(const size_t idx, const ListObject<T>& data) {
    insert(idx, data.get_data());
}

template<typename T>
void TwoLinkedList<T>::erase(const size_t idx) {
    if (idx >= this->size_)  
        throw LinkedListIndexError("Invalid element index.");

    if (idx == 0) {  
        auto newHead = this->head_->get_next();
        if (newHead) {
            newHead->set_prev(nullptr); 
        } 
        else {
            this->tail_ = nullptr;  
        }
        this->head_ = newHead;
    }
    else if (idx == this->size_ - 1) {  
        auto newTail = this->tail_->get_prev();
        if (newTail) {
            newTail->set_next(nullptr);  
        }
        this->tail_ = newTail;
    } 
    else {  
        if (idx > this->size_ / 2) {  
            auto currObj = this->tail_;
            for (size_t i = this->size_ - 1; i > idx && currObj; --i) {
                currObj = currObj->get_prev();
            }
            auto objToDelete = currObj->get_next();
            currObj->set_next(objToDelete->get_next());
            if (objToDelete->get_next()) {
                objToDelete->get_next()->set_prev(currObj);  
            }
        }
        else {  
            auto currObj = this->head_;
            for (size_t i = 0; i < idx - 1 && currObj; ++i) {
                currObj = currObj->get_next();
            }
            auto objToDelete = currObj->get_next();
            currObj->set_next(objToDelete->get_next());
            if (objToDelete->get_next()) {
                objToDelete->get_next()->set_prev(currObj);  
            }
        }
    }
    --this->size_;
}
