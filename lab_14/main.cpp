//Оцените сложность алгоритма в лучшем, среднем и худшем случае.
// Рассчитайте примерное время работы алгоритма. Запрограммируйте его.
// Определите реальное время работы (воспользуйтесь классом Timer
// https://ravesli.com/urok-129-tajming-koda-vremya-vypolneniya-programmy/) и сравните с расчетным.

//Ввод и вывод данных в расчете не учитывать. Считать, что 0 < N <= 10000.

//Вариант 7.
//Дана матрица N х N. Найдите наибольшую сумму элементов столбца.

#include "functions.hpp"
#include "Timer.hpp"

int main() {

    std::vector<std::vector<int>> matrix(N, std::vector<int> (N));
    fn::Read(matrix);
    Timer t;
    fn::maxSum(matrix);
    //fn::Output(matrix);
    std::cout << "Time elapsed: " << t.elapsed() << '\n';
    return 0;
}
