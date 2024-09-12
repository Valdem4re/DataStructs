#pragma once

#include <memory>

template<typename T>
class Array {

    

    private:

    std::shared_ptr<T> data_{nullptr};
    size_t size_{0};
};