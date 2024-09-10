#include "ListObject.h"

// #ifndef TWO_LINKED_LIST
// template<typename T>
// ListObject<T>::ListObject(T data, std::shared_ptr<ListObject<T>> next)
//     : data_(data), next_(next) {}
// #else
// template<typename T>
// ListObject<T>::ListObject(T data, std::shared_ptr<ListObject<T>> next, std::shared_ptr<ListObject<T>> prev)
//     : data_(data), next_(next), prev_(prev) {}
// #endif

// template<typename T>
// ListObject<T>::ListObject(const ListObject<T>& other)
//     : data_(other.data_), next_(other.next_)
// #ifdef TWO_LINKED_LIST
//     , prev_(other.prev_)
// #endif
// {}

// template<typename T>
// ListObject<T>& ListObject<T>::operator=(const ListObject<T>& other) {
//     if (this != &other) {
//         data_ = other.data_;
//         next_ = other.next_;
//         #ifdef TWO_LINKED_LIST
//         prev_ = other.prev_;
//         #endif
//     }
//     return *this;
// }

// template<typename T>
// ListObject<T>::ListObject(ListObject<T>&& other) noexcept
//     : data_(std::move(other.data_)), next_(std::move(other.next_))
// #ifdef TWO_LINKED_LIST
//     , prev_(std::move(other.prev_))
// #endif
// {}