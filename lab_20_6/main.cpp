/*Лабораторная работа №6
«Алгоритмы и структуры данных»

Вариант 2.
Подобрать структуру для хранения данных, над которой будут осуществляться операции поиска.
Добавление и удаление не предусмотрены.*/

#include "functions.hpp"

int main() {
    std::vector<std::vector<int>> mas;
    fn::CreateMas(mas);
    //fn::PrintMas(mas);

    fn::QuickSort(0, N-1, mas);
    //std::cout << "After sort" << std::endl;
    //fn::PrintMas(mas);
    int elem;
    std::cout << "Enter id:" << std::endl;
    std::cin >> elem;
    int j = fn::BinarySearch(mas, 0, N-1, elem);
    if (j != -1) {
        std::cout << "Found:\n" << "Id: " << mas[j][0] << " Serial number: " << mas[j][1] << std::endl;
    } else {
        std::cout << "Nothing found" << std::endl;
    }
    return 0;
}
