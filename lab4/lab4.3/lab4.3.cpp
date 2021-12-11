// lab 4.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    std::ifstream in("input.txt");
    const int M = 100;
    const int N = 100;
    int mas[N][M]; 
    int max = 0;

    int n, m;
    in >> n >> m;

    int sum[N];
    int numb = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            in >> mas[i][j];
        }
    }

     for (int i = 0; i < n; i++) {
        sum[i] = 0;
        for (int j = 0; j < m; j++) {
                sum[i] += mas[i][j];
        }
        if (sum[i] > max) {
            max = sum[i];
            numb = i;
        }
    }

    for (int j = 0; j < m; j++) {
        mas[numb][j]++;
    }
    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mas[i][j] << " ";
            
        }
        cout << endl;
    }

    return 0;

}
