/*
Лабораторная работа №9
«BMP»

Выполните рефакторинг кода, который был приведен на лекции. Что понимается под рефакторингом:

1.	Создание класса BMP.
2.	Определение методов чтения и записи изображения.
3.	Разбиение кода на дополнительные функции по вашему усмотрению.
4.	Переименование переменных по вашему усмотрению.
5.	Добавить 1 фильтр для изображения.
*/


#include "BMP.hpp"

using namespace bmp;
int main() {
    try {
        bmp::BMP test_pmp(1500, 2000);
        test_pmp.Fill({0, 255, 0});
        test_pmp.Rotate(acos(-1)/3);
        std::string fileout = "../test.bmp";
        test_pmp.WriteOut(fileout);
        return 0;
    } catch (std::logic_error& e) {
        std::cerr << e.what() << std::endl;
    }
}
