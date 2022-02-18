#pragma once
#include <iostream>
#include <vector>
#include <cstring>
#include <windows.h>
#include <math.h>
const int N = 10;
const int M = 2;

namespace fn {
    //2
    double f(double& x);
    double Bisection(double a, double b, double e);
    //1
    void CreateId(std::vector<std::vector<std::string>> & set);
    void CreateRequest(std::vector<std::string> & set);
    void PrintReq(std::vector<std::vector<std::string>>& set);
    int BinarySearch(std::vector<std::vector<std::string>> set, int l, int n, std::string k);
    int Medium(int a, int b, std::vector<std::vector<std::string>> & set);
    void QuickSort(int a, int b,std::vector<std::vector<std::string>> & set);
}
