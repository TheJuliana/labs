/*
Лабораторная работа №10
«Поворот изображения»

Воспользуйтесь кодом, который рассматривали на лекции, и осуществите поворот изображения на произвольный угол.
В полученном изображении будут присутствовать артефакты. Они возникают из-за ошибок округления.
Ваша задача заключается в том, чтобы эти артефакты убрать.

*/


#include "BMP.hpp"

using namespace bmp;
int main() {
    try {
        bmp::BMP test_pmp(2000, 2000);
        test_pmp.Fill({0, 0, 255});
        test_pmp.Rotate(acos(-1)/2);
        std::string fileout = "../test.bmp";
        test_pmp.WriteOut(fileout);
        return 0;
    } catch (std::logic_error& e) {
        std::cerr << e.what() << std::endl;
    }
}
