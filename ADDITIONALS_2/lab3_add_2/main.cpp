/*Задача №3
«Двусвязный циклический список»

Реализуйте двусвязный циклический список,
 предусмотрите в нем функции добавления элемента,
 вставки, удаления, обхода списка в обоих направлениях.

При выполнении задачи опирайтесь на лекцию 19 про односвязный список,
 а также на справочные ресурсы, например:
https://prog-cpp.ru/data-dcs/
Будьте готовы объяснить вашу реализацию.*/

#include "functions.hpp"

int main() {
    dl::List* head = new dl::List;
    head->next = nullptr;
    head->prev = nullptr;
    dl::CreateList(head);

    dl::Add(head, 7);
    std::cout << "------------" << std::endl;
    dl::PrintList(head);

    dl::DeleteElem(head, 4);
    std::cout << "------------" << std::endl;
    dl::PrintReverse(head);

    dl::Clear(head);
    delete head;
    return 0;
}
