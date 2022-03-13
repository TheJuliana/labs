#include "functions.hpp"

namespace fn{

    void CreateMas(std::vector<std::vector<int>> &mas) {
        for (int i = 0; i<N; i++) {
            std::vector<int> elem;
            int id = rand() % 10000 + 1;
            int number = rand() % 99999 + 10000;
            elem.push_back(id);
            elem.push_back(number);
            mas.push_back(elem);
        }
    }

    void PrintMas(std::vector<std::vector<int>> &mas) {
        for (auto& elem : mas) {
            for (auto& number : elem) {
                std::cout << number << " ";
            }
            std::cout << std::endl;
        };
        std::cout << std::endl;
    }


    int BinarySearch(std::vector<std::vector<int>> mas, int l, int n, int k) {
        if (k < mas[0][0]) {return -1;};
        if (k == mas[0][0]) {return 0;};
        if (k > mas[n][0]) {return -1;};
        int a = l;
        int b = n;
        while (a+1<b) {
            int c = (a+b)/2;
            if (k>mas[c][0]) {a = c;} else {b = c;};
        };
        if (mas[b][0] == k) {
            return b;
        } else {return -1;};
    }

    int Medium(int a, int b) {
        return ((rand()*rand())%(b-a+1))+a; //32767*32767=1 073 676 289 - необходимое максимально возможное число, так как max n = 1 000 000
    };

    void QuickSort(int a, int b, std::vector<std::vector<int>> &mas) {
        if (a>=b) {return;};
        int m = Medium(a, b);
        int k = mas[m][0];
        int l = a-1;
        int r = b+1;
        while(true) {
            do {l++;} while (mas[l][0]<k);
            do {r--;} while (mas[r][0]>k);
            if (l>=r) {break;}
            std::swap(mas[l][0], mas[r][0]);
        }
        r = l;
        l = l-1;
        QuickSort(a, l, mas);
        QuickSort(r, b, mas);
    }
}