//Ввести последовательность натуральных чисел{ Aj }j = 1...n(n <= 1000).
//Упорядочить последовательность по неубыванию суммы цифр числа,
//числа с одинаковыми суммами цифр дополнительно упорядочить по неубыванию
//наибольшей цифры числа, числа с одинаковыми суммами цифр и одинаковыми
//наибольшими цифрами дополнительно упорядочить по неубыванию самого числа.




#include <iostream>
#include <fstream>
#include <windows.h>

using std::cin;
using std::endl;
using std::cout;


int main()
{
    setlocale(LC_ALL, "Rus");

    int n;
    cin >> n;
    const int N = 100;
    int* mas = new int[n];
    int* sums = new int[n];
    int* maxDigit = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> mas[i];
        int x = mas[i];
        maxDigit[i] = 0;
        while (x > 0)
        {
            int d = x % 10;
            sums[i] += d;
            if (maxDigit[i] < d) {
                maxDigit[i] = d;
            }
            x /= 10;

        }

    }
    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((sums[i] > sums[j]) || ((sums[i] == sums[j]) &&
                                        ((maxDigit[i] > maxDigit[j]) ||
                                         (maxDigit[i] == maxDigit[j] && mas[i] < mas[j]))))
            {
                std::swap(mas[i], mas[j]);
                std::swap(maxDigit[i], maxDigit[j]);
                std::swap(sums[i], sums[j]);
            }
        }
    }

    cout << "Итог:" << endl;

    for (int i = 0; i < n; i++) {
        cout << mas[i] << endl;
    }

    delete[] mas;
    delete[] sums;
    delete[] maxDigit;

    return 0;
}



