#include "SomeFunctions.hpp"
#include <fstream>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

namespace func {

    void Read(int &n, int matrix[100][100]) {
        std::ifstream in(R"(C:\Users\Juliana\CLionProjects\lab6-7\input.txt)");
        in >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                in >> matrix[i][j];
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool MaxDiagonal(int n, int matrix[100][100]) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][i] >= matrix[i][j]) {
                    return true;
                } else return false;
            }
        }
        return false;
    }

    void Replacement(int n, int matrix[100][100]) {
        int prod = 1;
        for (int i = 0; i < n; i++) {
            for (i = 0; i < n; i++) {
                prod *= matrix[i][i];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][j] = prod;
                }
            }
        }
    }

    void Output(int n, int matrix[100][100]) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

}
