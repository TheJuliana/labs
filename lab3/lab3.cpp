//Вариант-7. 
//Дана последовательность целых чисел {Aj}. 
//Hайти сумму чисел, делящихся на 3 или на 7, 
//наименьшее из таких чисел и номер
//этого числа в последовательности.

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    setlocale(LC_ALL, "Rus");

    int n;
    int min;
    int numb;
    numb = 1;
    min = INT_MAX;
    int sum;
    sum = 0;

    cout << "Введите количество чисел в последовательности: " << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    { 
        if (((i % 7 == 0) || (i % 3 == 0)) && i != 0) {
            sum += n;
            if (i < min) {
                min = i;
                numb += i;
            } 
        }
    }
    cout << "Сумма равна: " << sum << endl;
    cout << "Мин число: " << min << " Номер которого равен: " << numb;
}
