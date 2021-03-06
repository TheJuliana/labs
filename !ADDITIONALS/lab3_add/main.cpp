/* Задача №3
«Функции»

При написании кода придерживайтесь рекомендаций, которые обсуждали на лекциях:
1.	Название функции соответствует тому, что она делает
2.	Одна задача - одна функция
3.	Разбитие на файлы
4.	Используйте пространства имен

Оформите ввод, вывод и обработку данных в виде функций и процедур (пример был дан в лекции)
    
Вариант 7.
Введите последовательность целых чисел длиной не более 1000. Замените все простые числа в диапазоне от -100 до 100 на 0.
*/


#include <iostream>
#include "Functions.hpp"
using std::cin;
using std::endl;
using std::cout;

int main() {
    int seq[1000];
    int x = 0;
    fn::Read(seq, x);

    fn::Replace(seq, x);

    fn::Output(seq, x);
}
