#include "functions.hpp"
namespace fn{
    int Medium(int a, int b, std::vector<int> & set) {
        return ((rand()*rand())%(b-a+1))+a; //32767*32767=1 073 676 289 - необходимое максимально возможное число, так как max n = 1 000 000
    };
    void QuickSort(int a, int b, std::vector<int> & set) {
        if (a>=b) {return;}
        int m = Medium(a, b, set);
        int k = set[m];
        int l = a-1;
        int r = b+1;
        while(true) {
            while (set[l]<k) {l++;}
            while (set[r]>k) {r--;}
            if (l>=r) {break;}
            std::swap(set[l], set[r]);
        }
        r = l;
        l = l-1;
        QuickSort(a, l, set);
        QuickSort(r, b, set);

    };
    void BubbleSort(std::vector<int> & set) {
        for (int i = 1; i < set.size(); i++)
        {
            if (set[i] >= set[i - 1])
                continue;
            int j = i - 1;
            while (j >= 0 && set[j] > set[j + 1])
            {
                std::swap(set[j], set[j + 1]);
                j--;
            }
        }
    }

    void PrintSet(std::vector<int> & set) {
        for (auto& i : set) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    void RandVector(std::vector<int> & set) {
        for (int i = 0; i < N; i++) {
            set.push_back(rand());
        }
    }

}