#pragma once
#include <memory>

template<typename T>
class ListObject {
    public:

    //--------------------CONSTRUCTORS------------------------
    ListObject(T data = 0, std::shared_ptr<ListObject<T>>* next = nullptr);

    #ifndef TWO_LINKED_LIST
        ListObject(T data = 0,
            std::shared_ptr<ListObject<T>>* next = nullptr,
            std::shared_ptr<ListObject<T>> prev = nullptr
        );
    #endif
    
    ListObject(const ListObject<T>& other);

    ListObject& operator=(const ListObject<T>& other);

    ListObject(ListObject<T>&& other) noexcept;

    //---------------------------------------------------------

    //---------------------METHODS-----------------------------

    T get_data(void) const {return data_;}

    ListObject<T>& get_next() const {return next_;}

    #ifndef TWO_LINKED_LIST
        ListObject<T>& get_prev() const {return prev_;}
    #endif

    private:

    T data_{0};
    std::shared_ptr<ListObject<T>> next_{nullptr};

    #ifndef TWO_LINKED_LIST
    std::shared_ptr<ListObject<T>> prev_{nullptr};
    #endif
};