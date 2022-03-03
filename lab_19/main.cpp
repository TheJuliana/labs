/*
Лабораторная работа №4
Вариант 2.
Создайте односвязный список из 10000 целых чисел и реализуйте в нем операцию удаления элемента k.
 Если элементов, равных k несколько, удалите их все. Выполните M = 1000 запросов на удаление.
Реализуйте такую же операцию для массива. Сравните производительность.
*/
#include "functions.hpp"

int main() {
    fn::T_List* head = new fn::T_List;
    head->next = nullptr;
    fn::CreateList(head);
    //fn::Print(head);

    Timer t1;
    fn::Delete(head);
    std::cout << "Time elapsed: " << t1.elapsed() << '\n';

    //fn::Print(head);
    fn::Clear(head);
    delete head;

    std::vector<int> mas;
    fn::CreateMas(mas);
    //fn::PrintMas(mas);

    Timer t2;
    fn::DeleteMas(mas);
    std::cout << "Time elapsed: " << t2.elapsed() << '\n';

    //fn::PrintMas(mas);
    return 0;
}
