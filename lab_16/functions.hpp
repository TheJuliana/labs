#pragma once
#include <iostream>
#include <vector>
const int N=10;
namespace fn {
    int Medium(int a, int b, std::vector<int> & set);
    void QuickSort(int a, int b, std::vector<int> & set); //<--Сложность: в лучшем и среднем случае O(N*logN), В худшем: O(N²)
    void BubbleSort(std::vector<int> & set); // <--Сложность: θ(N²)
    void PrintSet(std::vector<int> & set);   // Вывод: для маленького количества входных данных проще использовать bubblesort
    void RandVector(std::vector<int> & set); // а для больших - quicksort
}