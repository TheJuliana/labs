#pragma once
#include <iostream>
#include <vector>
#include "Timer.hpp"
const int N=10000;
const int M=1000;

namespace fn {
    struct T_List {
        T_List* next;
        int number;
    };

    void DeleteMas(std::vector<int>& mas);
    void CreateMas(std::vector<int>& mas);
    void PrintMas(std::vector<int>& mas);

    void Add(T_List* head, int number);
    void CreateList(T_List* head);
    void Print(T_List* head);
    void Delete(T_List* head);
    void Clear(T_List* head);
}

