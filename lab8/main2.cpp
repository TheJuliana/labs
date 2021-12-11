//Дана целочисленная матрица{ Aij }i = 1..n, j = 1..m(n, m <= 100).
//Найти строку с наибольшей суммой элементов и увеличить все элементы этой строки на 1.

#include <iostream>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    std::ifstream in("input.txt");
    int max = 0;

    int n, m;
    in >> n >> m;


    int** mas = new int* [n];
    int* sum = new int[n];
    for (int i = 0; i < n; i++) {
        mas[i] = new int[m];
    }

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



    for (int i = 0; i < n; i++) {
        delete[] mas[i];
    }
    delete[] sum;
    delete[] mas;

    return 0;

}


