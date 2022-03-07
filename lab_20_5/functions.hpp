#pragma once
#include <iostream>
#include <fstream>
#include <cstring>

namespace tr{
    struct Elem {
        int numb;
        Elem* left;
        Elem* right;
        Elem* parent;
    };
    int FindDepth(Elem*& root, int numb);
    Elem* TreeMake(Elem* p, int numb);
    Elem* TreeSearch(Elem* x, int k);
    void TreeInsert(Elem*& root, int numb);
    void TreeDelete(Elem*& root, int numb);
    void TreePass(Elem* x);
}