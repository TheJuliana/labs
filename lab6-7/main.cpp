//Вариант - 7.
//Дана целочисленная матрица{ Aij }i = 1...n; j = 1..n, n <= 100.
//Если все диагональные элементы матрицы являются наибольшими элементами своих строк,
//заменить элементы матрицы, содержащие цифру 0, на произведение диагональных элементов.

#include <iostream>
#include <fstream>
#include "SomeFunctions.hpp"
using std::cout;
using std::cin;
using std::endl;

int main()
{
    std::ifstream in("input.txt");
    setlocale(LC_ALL, "Rus");
    int n = 0;
    int matrix[100][100];
    func::Read(n, matrix);
    if (func::MaxDiagonal(n, matrix)) {
        func::Replacement(n, matrix);
        func::Output(n, matrix);
    }
    else {
        cout << "Матрица не подходит" << endl;
    }
    return 0;
}