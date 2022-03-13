#pragma once
#include <iostream>
#include <vector>
const int N = 1000000;

namespace fn{
    void CreateMas(std::vector<std::vector<int>> &mas);
    void PrintMas(std::vector<std::vector<int>> &mas);
    int Medium(int a, int b);
    int BinarySearch(std::vector<std::vector<int>> mas, int l, int n, int k);
    void QuickSort(int a, int b, std::vector<std::vector<int>> &mas);
}