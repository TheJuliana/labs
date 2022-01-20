#include "functions.hpp"

namespace fn{
    void Read(int &n, std::vector<int> &seq) {
        std::cin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            seq.push_back(x);
        }
    }
     bool Nine(int x) {
         int num = x;
         std::vector<int> digits;
         while (num > 0) {
             digits.push_back(num % 10);
             num /= 10;
         }
         for (auto& digit : digits) {
             if (digit == 9) {
                 return true;
             }
         }
         return false;
     }

     bool Doubl(int x) {
        int num = x;
        std::vector<bool> arr(10, false);
         while(num != 0){
             int d = num%10;
             if( arr[d] ){
                 return true;
             }
             arr.push_back(true);
             num /= 10;
         }
         return false;
    }

    void Output(std::vector<int> seq) {
        for (auto& num : seq) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}
