#include "OneLinkedList.h"

// template<typename T>
// OneLinkedList<T>::OneLinkedList(T data) {
//     head_ = std::make_shared<ListObject<T>>(data);
//     tail_ = head_;
//     size_ = 1;
// }

// template<typename T>
// OneLinkedList<T>::OneLinkedList(const ListObject<T>& obj) {
//     size_ = 1;
//     head_ = std::make_shared<ListObject<T>>(obj);

//     auto current = head_;
//     while (current->get_next()) {
//         current = current->get_next();
//         ++size_;
//     }
//     tail_ = current;
// }

// template<typename T>
// void OneLinkedList<T>::push_back(T const& data) {
//     auto newObj = std::make_shared<ListObject<T>>(data);

//     if (!head_) {
//         initialize_list(newObj);
//     } else {
//         tail_->set_next(newObj);
//         tail_ = newObj;
//         ++size_;
//     }
// }

// template<typename T>
// void OneLinkedList<T>::push_back(const ListObject<T>& data) {
//     auto newObj = std::make_shared<ListObject<T>>(data);

//     if (!head_) {
//         initialize_list(newObj);
//     } else {
//         tail_->set_next(newObj);
//         tail_ = newObj;
//         ++size_;
//     }
// }

// template<typename T>
// void OneLinkedList<T>::push_front(const ListObject<T>& obj) {
//     auto newObj = std::make_shared<ListObject<T>>(obj);

//     if (!head_) {
//         initialize_list(newObj);
//     } else {
//         newObj->set_next(head_);
//         head_ = newObj;
//         ++size_;
//     }
// }

// template<typename T>
// void OneLinkedList<T>::push_front(T const& data) {
//     auto newObj = std::make_shared<ListObject<T>>(data);

//     if (!head_) {
//         initialize_list(newObj);
//     } else {
//         newObj->set_next(head_);
//         head_ = newObj;
//         ++size_;
//     }
// }

// template<typename T>
// void OneLinkedList<T>::pop_back() {
//     if (size_ == 0) return;

//     if (size_ == 1) {
//         head_.reset();
//         tail_.reset();
//     } else {
//         auto currObj = head_;
//         while (currObj->get_next() != tail_) {
//             currObj = currObj->get_next();
//         }
//         currObj->set_next(nullptr);
//         tail_ = currObj;
//     }
//     --size_;
// }

// template<typename T>
// void OneLinkedList<T>::pop_front() {
//     if (size_ == 0) return;

//     if (size_ == 1) {
//         head_.reset();
//         tail_.reset();
//     } else {
//         head_ = head_->get_next();
//     }
//     --size_;
// }