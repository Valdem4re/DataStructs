#include <iostream>
#include "OneLinkedList/OneLinkedList.h"
#include "ListObject/ListObject.h"
#include <cassert>


int main() {
    // Тестирование конструктора с параметрами
    ListObject<int> obj1(10);
    assert(obj1.get_data() == 10);
    assert(obj1.get_next() == nullptr);

    // Тестирование конструктора с указателем на следующий элемент
    auto nextObj = std::make_shared<ListObject<int>>(20);
    ListObject<int> obj2(30, nextObj);
    assert(obj2.get_data() == 30);
    assert(obj2.get_next() == nextObj);

    // Тестирование конструктора копирования
    ListObject<int> obj3 = obj2;
    assert(obj3.get_data() == 30);
    assert(obj3.get_next() == nextObj);

    // Тестирование конструктора перемещения
    ListObject<int> obj4 = std::move(obj2);
    assert(obj4.get_data() == 30);
    assert(obj4.get_next() == nextObj);
    assert(obj2.get_next() == nullptr); // obj2 должен быть "пустым" после перемещения

    // Тестирование оператора присваивания копирования
    ListObject<int> obj5(40);
    obj5 = obj3;
    assert(obj5.get_data() == 30);
    assert(obj5.get_next() == nextObj);

    // Тестирование оператора присваивания перемещения
    ListObject<int> obj6(50);
    obj6 = std::move(obj3);
    assert(obj6.get_data() == 30);
    assert(obj6.get_next() == nextObj);
    assert(obj3.get_next() == nullptr); // obj3 должен быть "пустым" после перемещения

    // Тестирование методов сеттеров и геттеров prev, если включена опция TWO_LINKED_LIST
    #ifdef TWO_LINKED_LIST
    auto prevObj = std::make_shared<ListObject<int>>(60);
    ListObject<int> obj7(70, nextObj, prevObj);
    assert(obj7.get_data() == 70);
    assert(obj7.get_next() == nextObj);
    assert(obj7.get_prev() == prevObj);

    obj7.set_prev(nullptr);
    assert(obj7.get_prev() == nullptr);
    #endif

    std::cout << "ListObject: All tests passed!" << std::endl;

    OneLinkedList<int> list1;
    assert(list1.size() == 0);
    assert(list1.get_head() == nullptr);

    // Тестирование push_back и pop_back
    list1.push_back(10);
    assert(list1.size() == 1);
    assert(list1.get_head()->get_data() == 10);

    list1.push_back(20);
    assert(list1.size() == 2);
    assert(list1.get_head()->get_next()->get_data() == 20);

    list1.pop_back();
    assert(list1.size() == 1);
    assert(list1.get_head()->get_data() == 10);

    list1.pop_back();
    assert(list1.size() == 0);
    assert(list1.get_head() == nullptr);

    // Тестирование push_front и pop_front
    list1.push_front(30);
    assert(list1.size() == 1);
    assert(list1.get_head()->get_data() == 30);

    list1.push_front(40);
    assert(list1.size() == 2);
    assert(list1.get_head()->get_data() == 40);
    assert(list1.get_head()->get_next()->get_data() == 30);

    list1.pop_front();
    assert(list1.size() == 1);
    assert(list1.get_head()->get_data() == 30);

    list1.pop_front();
    assert(list1.size() == 0);
    assert(list1.get_head() == nullptr);

    // Тестирование оператора присваивания копирования
    OneLinkedList<int> list2;
    list2.push_back(50);
    list2.push_back(60);

    OneLinkedList<int> list3 = list2;
    assert(list3.size() == 2);
    assert(list3.get_head()->get_data() == 50);
    assert(list3.get_head()->get_next()->get_data() == 60);

    // Тестирование оператора присваивания перемещения
    OneLinkedList<int> list4 = std::move(list2);
    assert(list4.size() == 2);
    assert(list4.get_head()->get_data() == 50);
    assert(list4.get_head()->get_next()->get_data() == 60);
    assert(list2.size() == 0);
    assert(list2.get_head() == nullptr);

    // Тестирование оператора присваивания копирования
    OneLinkedList<int> list5;
    list5.push_back(70);
    list5.push_back(80);

    OneLinkedList<int> list6;
    list6 = list5;
    assert(list6.size() == 2);
    assert(list6.get_head()->get_data() == 70);
    assert(list6.get_head()->get_next()->get_data() == 80);

    // Тестирование метода [] для доступа и модификации элементов
    list6[0] = 90;
    list6[1] = 100;
    assert(list6[0] == 90);
    assert(list6[1] == 100);

    // Проверка на недопустимые индексы
    try {
        list6[2] = 110;
        assert(false); // Ожидаем, что это приведет к исключению
    } catch (const std::exception &e) {
        // Ожидаем исключение
    }

    std::cout << "OneLinkedList: All tests passed!" << std::endl;

    return 0;
}