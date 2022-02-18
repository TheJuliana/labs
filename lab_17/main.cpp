/*
Вариант 2
1.	Реализуйте алгоритм бинарного поиска, о котором шла речь на лекции.
Решите задачу выполнения M (0<M<10000) поисковых запросов над массивом из N (0<N<100000) элементов,
 используя проход по массиву циклом и бинарный поиск. Сравните время работы этих двух подходов.
2.	Найдите корень уравнения x^2 - 10 = 0 на отрезке [0; +беск] с точностью до 10^-4 с помощью бисекции.
*/

#include "functions.hpp"

int main() {
    std::cout << "1.BINARYSEARCH" << std::endl;
    //массив номеров паспорта и имен пользователей
    std::vector<std::vector<std::string>> users;
    std::vector<std::string> request;

    //заполнение массивов
    fn::CreateId(users);
    fn::CreateRequest(request);
    //массив до сортировки
    fn::PrintReq(users);
    //сортировка
    fn::QuickSort(0, N - 1, users);
    //массив после сортировки
    fn::PrintReq(users);

    for (int i = 0; i < M; i++) {
        std::cout << "Current request: " << request[i] << " ";
        int j = fn::BinarySearch(users, 0, N - 1, request[i]);
        if (j != -1) {
            std::cout << "Found: " << users[j][0] << " " << users[j][1]  << std::endl;
        } else {
            std::cout << "Nothing found" << std::endl;
        };
    }

    std::cout << "2.BISECTION:" << fn::Bisection(0, INT_MAX, 0.0001) << std::endl;
    return 0;
}
