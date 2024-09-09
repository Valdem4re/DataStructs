#include "ListObject.h"

template<typename T>
ListObject<T>::ListObject(T data, std::shared_ptr<ListObject<T>>* next) : data_(data) {
        next_ = std::move(next);
}

#ifndef TWO_LINKED_LIST
template<typename T>
ListObject<T>::ListObject(T data,
 std::shared_ptr<ListObject<T>>* next,
 std::shared_ptr<ListObject<T>> prev) {
    data_ = data;
    next_ = std::move(next);
    prev_ = std::move(prev);
}
#endif

template<typename T>
ListObject<T>::ListObject(const ListObject<T>& other) {
    data_ = other.data_;
    next_ = other.next_ ? std::make_unique<ListObject<T>>(*other.next_) : nullptr;
    prev_ = other.prev_ ? std::make_unique<ListObject<T>>(*other.prev_) : nullptr;
}

template<typename T>
ListObject<T>& ListObject<T>::operator=(const ListObject<T>& other) {
    if(this != &other) {
        data_ = other.data_;
        delete next_;
        next_ = other.next_ ? std::make_unique<ListObject<T>>(other.next_) : nullptr;

        #ifndef TWO_LINKED_LIST
            delete prev_;
            prev_ = other.prev_ ? std::make_unique<ListObject<T>>(other.prev_) : nullptr;
        #endif
    }
    return *this;
}

template<typename T>
ListObject<T>::ListObject(ListObject<T>&& other) noexcept = default;