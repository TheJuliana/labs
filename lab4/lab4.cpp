// lab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
using std::cin;
using std::endl;
using std::cout;


int main()
{
    setlocale(LC_ALL, "Rus");

    std::ifstream in("input.txt");
    int n;
    in >> n;
    const int N = 100;
    bool ch = false;
    int mas[N];
    for (int i = 0; i < N - 1; i++) {
        in >> mas[i];
    } 
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mas[i] != mas[j]) {
                if (mas[i] < mas[j]) {
                    std::swap(mas[i], mas[j]);
                }
            }
            else {
                ch = true;
            } 
        }
        if (ch == false) { 
            cout << mas[i] << endl; 
        }
        else {
            cout << "Есть равные числа" << endl;
            break;
        }
    }

}

