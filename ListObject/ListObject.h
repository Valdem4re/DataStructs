#pragma once
#include <memory>

template<typename T>
class ListObject {
public:
        ListObject(T data, std::shared_ptr<ListObject<T>> next = nullptr)
            : data_(data), next_(next) {}

        ListObject(const ListObject<T>& other)
            : data_(other.data_), next_(other.next_) {}

        ListObject(ListObject<T>&& other) noexcept
            : data_(std::move(other.data_)), next_(std::move(other.next_)) {}

        ListObject<T>& operator=(const ListObject<T>& other) {
            if (this != &other) {
                data_ = other.data_;
                next_ = other.next_;
            }
            return *this;
        }

        ListObject<T>& operator=(ListObject<T>&& other) noexcept {
            if (this != &other) {
                data_ = std::move(other.data_);
                next_ = std::move(other.next_);
            }
            return *this;
        }
    #ifdef TWO_LINKED_LIST
        ListObject(T data,
         std::shared_ptr<ListObject<T>> next = nullptr,
         std::shared_ptr<ListObject<T>> prev = nullptr)
            : data_(data), next_(next), prev_(prev) {}

        ListObject(const ListObject<T>& other)
            : data_(other.data_), next_(other.next_), prev(other.prev_) {}

        ListObject(ListObject<T>&& other) noexcept
            : data_(std::move(other.data_)),
            next_(std::move(other.next_)),
            prev_(std::move(other.prev_))
            {}

        ListObject<T>& operator=(const ListObject<T>& other) {
            if (this != &other) {
                data_ = other.data_;
                next_ = other.next_;
                prev_ = other.prev_;
            }
            return *this;
        }

        ListObject<T>& operator=(ListObject<T>&& other) noexcept {
            if (this != &other) {
                data_ = std::move(other.data_);
                next_ = std::move(other.next_);
                prev_ = std::move(other.prev_);
            }
            return *this;
        }
    #endif

    ~ListObject() = default;

    //---------------------------------------------------------

    T get_data() const {
        return data_;
    }

    void set_data(T data) {data_ = data;} 

    std::shared_ptr<ListObject<T>> get_next() const {
        return next_;
    }

    void set_next(std::shared_ptr<ListObject<T>> next) {
        next_ = next;
    }

    #ifdef TWO_LINKED_LIST
        std::shared_ptr<ListObject<T>> get_prev() const {
            return prev_;
        }

        void set_prev(std::shared_ptr<ListObject<T>> prev) {
                prev_ = prev;
            }
    #endif

private:
    T data_{T()};
    std::shared_ptr<ListObject<T>> next_ {nullptr};

    #ifdef TWO_LINKED_LIST
        std::shared_ptr<ListObject<T>> prev_{nullptr};
    #endif
};


