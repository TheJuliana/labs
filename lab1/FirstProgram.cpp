// FirstProgram1.cpp : Нахождение главной диагонали параллелепипеда
//

#include <iostream>
#include <Windows.h>
#include <cmath>


int main()
{
    setlocale(LC_ALL, "Russian");
    float a = 0;
    float b = 0;
    float c = 0;
    std::cout << "Введите длину, ширину и высоту параллелепипеда" << std::endl;
    std::cin >> a >> b >> c;
    std::cout << "Введенные числа: " << a << " " << b << " " << c << std::endl;
    float d = 0;
    d = pow((pow(a, 2) + pow(b, 2) + pow(c, 2)), 0.5);
    std::cout << "Диагональ равна: " << d << std::endl;
    return 0;
}
