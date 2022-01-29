#include <iostream>
/*Вариант 7.
Даны числа a и b. Рассчитать их наибольший общий делитель.*/

int GreatestCommonDivisor(int a, int b) {
    if (b == 0) {return a;}; //терминирующее условие
    return GreatestCommonDivisor(b, a % b);

};
int main() {
    int a, b;
    std::cout << "Enter two numbers: ";
    std::cin >> a >> b;
    std::cout << GreatestCommonDivisor(a, b) << std::endl;
}
