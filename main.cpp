#include <iostream>
#include "OneLinkedList/OneLinkedList.h"

struct Complex{
    int re{0};
    int im{0};
    Complex(int r = 0, int i = 0) : re(r), im(i) {}

};

template<typename T>
using Object = ListObject<T>;


int main() {
    OneLinkedList<Complex> lst; // пустой односвязный список для хранения данных типа Complex (структура)

    lst.push_back(Complex {1, 2}); // добавление в конец списка
    lst.push_back(Complex {3, 4}); // добавление в конец спискf

    lst.push_front(Complex {-1, -2}); // добавление в начало списка
    lst.pop_back(); // удаление последнего элемента (если его нет, то ничего не делать)
    lst.pop_front(); // удаление первого элемента (если его нет, то ничего не делать)

    Complex d = lst[0];  // получение первого элемента по индексу
    lst[0] = Complex {5, 8}; // запись в первый элемент по индексу

    OneLinkedList<int> lst_int; // еще один односвязный список для хранения данных типа int

    lst_int.push_back(1); // добавление в конец списка
    lst_int.push_back(2);
    lst_int.push_back(3);

    int var = lst_int[1]; // чтение данных из второго элемента списка
    lst_int[2] = -5; // запись данных в третий элемент списка

    // перебор первого списка
    std::shared_ptr< Object<Complex> > ptr_lst = lst.get_head();
    while(ptr_lst) {
        Complex res = ptr_lst->get_data();
        std::cout << res.re << " " << res.im << std::endl;
        ptr_lst = ptr_lst->get_next();
    }

    // перебор второго списка
    std::shared_ptr< Object<int> > ptr_lst_int = lst_int.get_head();
    while(ptr_lst_int) {
        int a = ptr_lst_int->get_data();
        std::cout << a << std::endl;
        ptr_lst_int = ptr_lst_int->get_next();
    }
    return 0;
}