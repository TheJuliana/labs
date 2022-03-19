#pragma once

#include <iostream>
const int N = 10;

namespace dl {
    struct List {
        int data;
        List *next, *prev;
    };

    void CreateList(List* head);
    void Add(List* head, int data);
    void DeleteElem(List* head, int data);
    void PrintList(List* head);
    void PrintReverse(List* head);
    void Clear(List* head);

};