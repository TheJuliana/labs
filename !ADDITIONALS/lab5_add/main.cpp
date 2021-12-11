/*Вариант-7.
Дана последовательность натуральных чисел {Aj}j=1...n (n<=10000).
        Удалить из последовательности числа, содержащие цифру 9,
        а среди оставшихся продублировать числа, содержащие хотя бы пару одинаковых цифр.*/


#include <iostream>
#include "functions.hpp"
using std::cin;
using std::endl;
using std::cout;

int main() {

    int n;
    int mas[1000];

    fn::Read(mas, n);

    for (int i = 0; i < n; i++) {
        if (fn::Nine(mas[i])) {
        mas[i] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        if (fn::Duplication(mas[i])) {
            fn::ToRight(mas, i, mas[i], n);
        }
    }

    fn::Output(mas, n);

    return 0;
}
