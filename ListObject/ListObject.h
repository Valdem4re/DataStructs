#pragma once
#include <memory>

template<typename T>
class ListObject {
public:
    //--------------------CONSTRUCTORS------------------------
    #ifndef TWO_LINKED_LIST
        ListObject(T data = T(), std::shared_ptr<ListObject<T>> next = nullptr);
    #else
        ListObject(T data = T(),
                   std::shared_ptr<ListObject<T>> next = nullptr,
                   std::shared_ptr<ListObject<T>> prev = nullptr);
    #endif

    ListObject(const ListObject<T>& other);

    ListObject& operator=(const ListObject<T>& other);

    ListObject(ListObject<T>&& other) noexcept;

    //---------------------------------------------------------

    //---------------------METHODS-----------------------------

    const T& get_data(void) const { return data_; }

    void set_data(T data) { data_ = data; } 

    std::shared_ptr<ListObject<T>> get_next() const { return next_; }

    void set_next(const std::shared_ptr<ListObject<T>> next) { next_ = next; };

    #ifdef TWO_LINKED_LIST
        std::shared_ptr<ListObject<T>> get_prev() const { return prev_; }
    #endif

private:
    T data_{T()};
    std::shared_ptr<ListObject<T>> next_{nullptr};

    #ifdef TWO_LINKED_LIST
    std::shared_ptr<ListObject<T>> prev_{nullptr};
    #endif
};


#ifndef TWO_LINKED_LIST
template<typename T>
ListObject<T>::ListObject(T data, std::shared_ptr<ListObject<T>> next)
    : data_(data), next_(next) {}
#else

template<typename T>
ListObject<T>::ListObject(T data, std::shared_ptr<ListObject<T>> next, std::shared_ptr<ListObject<T>> prev)
    : data_(data), next_(next), prev_(prev) {}
#endif


template<typename T>
ListObject<T>::ListObject(const ListObject<T>& other)
    : data_(other.data_), next_(other.next_)
#ifdef TWO_LINKED_LIST
    , prev_(other.prev_)
#endif
{}


template<typename T>
ListObject<T>& ListObject<T>::operator=(const ListObject<T>& other) {
    if (this != &other) {
        data_ = other.data_;
        next_ = other.next_;
        #ifdef TWO_LINKED_LIST
        prev_ = other.prev_;
        #endif
    }
    return *this;
}


template<typename T>
ListObject<T>::ListObject(ListObject<T>&& other) noexcept
    : data_(std::move(other.data_)), next_(std::move(other.next_))
#ifdef TWO_LINKED_LIST
    , prev_(std::move(other.prev_))
#endif
{}
