/*Реализуйте алгоритм быстрой сортировки по его псевдокоду.
Реализуйте алгоритм сортировки пузырьком из лекции 1.
Исследуйте при помощи класса Timer время выполнения на
разных объемах входных данных (n = 10, n = 100, n = 100 000, n = 1 000 000).
Объясните полученный результат.*/

#include "functions.hpp"
#include "Timer.hpp"

int main() {

    std::vector<int> set1;
    std::vector<int> set2;
    fn::RandVector(set1);
    fn::RandVector(set2);
    std::cout << "Vector before quicksort" << std::endl;
    fn::PrintSet(set1);
    Timer t1;
    fn::QuickSort(1, set1.size(), set1);
    std::cout << "Time elapsed: " << t1.elapsed() << '\n';
    std::cout << "After Quicksort" << std::endl;
    fn::PrintSet(set1);

    std::cout << "Vector before bubblesort" << std::endl;
    fn::PrintSet(set2);
    Timer t2;
    fn::BubbleSort(set2);
    std::cout << "Time elapsed: " << t2.elapsed() << '\n';
    std::cout << "After Bubblesort" << std::endl;
    fn::PrintSet(set2);
    return 0;
}
