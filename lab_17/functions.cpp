#include "functions.hpp"

namespace fn {
    double f(double & x) {
        //x^2 - 10 = 0
        return pow(x, 2)-10;
    };
    double Bisection(double a, double b, double e) {
        double fa = f(a);
        double x;
        while (true) { //достигаем необходимой точности e
           x = (a+b)/2;
           if (abs(x-a)<e || abs(x-b)<e) {
               return x;
           } else if (f(x)*fa>0) {
               a = x;
           } else {
               b = x;
           }
        };
        return x;
    };
    std::string CreateName(std::string str) {
        //генерируем различные "имена"
        char a[15] = {
                'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o'
        };
        for (int i = 0; i < 10; i++) {
            str += a[(rand()%7+1)];
        };
        return str;
    }
    void CreateId(std::vector<std::vector<std::string>> & set) {
        int id = rand()%999+100; //генерируем различные номера паспортов
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 2; j++) {
                set.emplace_back(); //по другому не работает
                std::string name;
                if (j == 0) {
                    set[i].emplace_back(std::to_string(id)); //используем emplace_back чтобы сразу пометить всю строку
                } else { //если столбец с номерами паспортов то генерируем его, иначе генерируем имена
                    set[i].emplace_back(fn::CreateName(name));
                }
            }
            id = rand()%999+100;
        }
    }
    void CreateRequest(std::vector<std::string> & set) {
        for (int i = 0; i < M; i++) {
            //генерируем М рандомных запросов
            std::string requestId = std::to_string(rand()%999+100);
            set.emplace_back(requestId);
        }
    }
    void PrintReq(std::vector<std::vector<std::string>> & set){
        std::cout << "Current users:" << std::endl;
        for (auto & column : set) {
            for (auto & user : column) {
                std::cout << user << " "; //вывод массива
            }
            std::cout << std::endl;
        }
    }
    int BinarySearch(std::vector<std::vector<std::string>> set, int l, int n, std::string k) {
        if (k < set[0][0]) {return -1;};
        if (k == set[0][0]) {return 0;};
        if (k > set[n][0]) {return -1;};
        int a = l;
        int b = n;
        while (a+1<b) {
            int c = (a+b)/2;
            if (k>set[c][0]) {a = c;} else {b = c;};
        };
        if (set[b][0] == k) {
            return b;
        } else {return -1;};
    }

    int Medium(int a, int b, std::vector<std::vector<std::string>> & set) {
        return ((rand()*rand())%(b-a+1))+a; //32767*32767=1 073 676 289 - необходимое максимально возможное число, так как max n = 1 000 000
    };

    void QuickSort(int a, int b, std::vector<std::vector<std::string>> & set) {
        if (a>=b) {return;}
        int m = Medium(a, b, set);
        std::string k = set[m][0];
        int l = a-1;
        int r = b+1;
        while(true) {
            do {l++;} while (set[l][0]<k) ;
            do {r--;} while (set[r][0]>k) ;
            if (l>=r) {break;}
            std::swap(set[l][0], set[r][0]);
        }
        r = l;
        l = l-1;
        QuickSort(a, l, set);
        QuickSort(r, b, set);
    };
}