#include "OneLinkedList.h"


template<typename T>
OneLinkedList<T>::OneLinkedList(T data) {
    head_ = std::make_shared<ListObject<T>>(data);
    tail_ = head_;
    size_ = 1;
}

template<typename T>
OneLinkedList<T>::OneLinkedList(ListObject<T>& obj) {
    size_ = 1;
    head_ = std::make_shared<ListObject<T>>(obj);
    std::shared_ptr<ListObject<T>> current = head_;
    while(current->get_next()){
        current = current->get_next();
        size_++;
    }
    tail_ = current;
}

template<typename T>
void OneLinkedList<T>::push_back(const T& data) {

    auto newObj = std::make_shared<ListObject<T>>(data);

    if(head_ == nullptr) {
        head_ = newObj;
        tail_ = newObj;
    }
    else {
        tail_->next_ = newObj;
        tail_ = newObj;
    }
}

template<typename T>
void OneLinkedList<T>::push_back(const ListObject<T>& data) {
    if(head_ == nullptr) {
        head_ = std::make_shared<ListObject<T>>(data);
        tail_ = head_;
    }
    else {
        tail_->next = data;
        tail_ = data;
    }
}