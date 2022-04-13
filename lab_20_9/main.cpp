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
    // Чтение файла
    std::ifstream in("../in.bmp", std::ios::binary); // открыть файл для бинарного чтения
    // Записать файл
    std::ofstream out("../out.bmp", std::ios::binary);

    BMPHEADER bmpHeader;
    // Считать 14 байтов побайтово и заполнить структуру BMPHEADER
    in.read(reinterpret_cast<char*>(&bmpHeader), sizeof(BMPHEADER));

    BMPINFO bmpInfo;
    in.read(reinterpret_cast<char*>(&bmpInfo), sizeof(BMPINFO));

    std::vector<std::vector<Pixel>> pixels(bmpInfo.Height, std::vector<Pixel> (bmpInfo.Width));

    BMP::WriteIn(pixels, in, bmpInfo);

    BMP::PinkFilter(pixels, bmpInfo);

    BMP::WriteOut(pixels, out, bmpInfo);

}
