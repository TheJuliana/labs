// lab4.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    std::ifstream in("input.txt");
    setlocale(LC_ALL, "Rus");

    const int N = 1000;
    int mas[N];
    int firstDigit[N];
    int sums[N];
    int n;

    in >> n;

    for (int i = 0; i < n; i++) {
        in >> mas[i];
        sums[i] = 0;
        int x = mas[i];
        while (x>0) {
            firstDigit[i] = x % 10;
            sums[i] += x % 10;
            x /= 10;
        }
    }

    for(int i=0;i<n;i++)
        
        cout << mas[i] << " " << sums[i] << " " << firstDigit[i] << endl;
    cout << " " << endl;



    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
             if (sums[i] > sums[j] ||
                (sums[i] == sums[j] && firstDigit[i] > firstDigit[j]) ||
                (sums[i] == sums[j] && firstDigit[i] == firstDigit[j] && mas[i] > mas[j])) {
                    std::swap(mas[i], mas[j]);
                    std::swap(sums[i], sums[j]);
                    std::swap(firstDigit[i], firstDigit[j]);
            }
        }
        cout << mas[i] << " " << sums[i] << " " << firstDigit[i] << endl;
    }
 }




