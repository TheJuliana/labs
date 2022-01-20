#include "Functions.hpp"
#include <iostream>
#include <math.h>

namespace fn {
    void Read(int mas[1000], int& x) {
        std::cout << "Enter N:" << std::endl;
        std::cin >> x;
        std::cout << "Entered sequence:" << std::endl;
        for (int i = 0; i < x; i++) {
            std::cin >> mas[i];
        }
    }

    void Replace(int mas[1000], int n) {
        for (int i = 0; i < n; i++) {
            if (abs(mas[i]) <= 100) {
                bool d = false;
                for (int j = 2; j < sqrt(mas[i]); j++) {
                    if (mas[i] %  j == 0) {
                        d = true;
                        break;
                    }
                }
                if (!d) {
                    mas[i] = 0;
                }
            }
        }
    }

    void Output(int mas[1000], int n) {
        std::cout << "Final sequence:" << std::endl;
        for (int i = 0; i < n; i++) {
            std::cout << mas[i] << " ";
        }
        std::cout << std::endl;
    }
}
