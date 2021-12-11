#include "functions.hpp"
#include <iostream>

namespace fn {
    void Read(int mas[1000], int& n) {
        std::cout << "Enter N:" << std::endl;
        std::cin >> n;
        std::cout << "Enter sequence:" << std::endl;
        for (int i =0; i < n; i++) {
            std::cin >> mas[i];
        }
    }

    bool Nine(int x) {
        int numb = x;
        while (numb > 0) {
            if (numb % 10 == 9) {
                return true;
            }
            numb /= 10;
        }
        return false;
    }

    bool Duplication(int x) {
        bool arr[10]={false};
        int num = x;
        while( num > 0 ){
            int d = num%10;
            if( arr[d] ){
                return true;
            }
            arr[d] = true;
            num /= 10;
        }
        return false;
    }

    void ToRight(int mas[1000], int& i, int x, int& n) {
        for(int k=n-1; k >=i; k--) {
            mas[k+1] = mas[k];
        }
        n++;
        i++;
    }

    void Output(int mas[1000], int n) {
        std::cout << "Final sequence: " << std::endl;
        for (int i =0; i < n; i++) {
            if (mas[i] != 0) {
                std::cout << mas[i] << " ";
            }
        }
    }
}