#include "functions.hpp"

namespace fn{

    void Read(std::vector<std::vector<int>> &matrix) {

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                matrix[i][j] = rand();
            }
        }
    }

    void maxSum(std::vector<std::vector<int>>& matrix) {
        int maxSum;
        int sum;
        for (int i = 0; i < matrix.size(); i++) { //N
            for (int j = 0; j < matrix.size(); j++) { //N
                sum+=matrix[j][i]; //2
            }
            //--------------------------------------------
            if (maxSum < sum) { //1
                maxSum = sum; //1
            }
            //--------------------------------------------
            sum = 0; //1
            // Худший случай: Θ(N^2)
            // Средний случай: Θ(N^2)
            // Лучший случай: Θ(N^2)
        }
        std::cout << "Max sum: " << maxSum << std::endl;
    }

    void Output(std::vector<std::vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
}