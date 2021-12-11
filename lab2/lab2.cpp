// lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using std::cout;
using std::cin;
using std::endl;


int main()
{
    setlocale(LC_ALL, "Rus");
    int A, B, C;
    cout << "Введите три натуральных числа через пробел" << endl;
    cin >> A >> B >> C;
    if ((A % B == 0) && (B > C)) {
        cout << A / B + C << endl;
    }
    else if ((A % B == 0) && (B < C)) {
        cout << A / B - C << endl;
    }
    else {
        cout << (A + B) * C << endl;
    }

    int N;
    cout << "Введите номер дня недели" << endl;
    cin >> N;
    switch (N) {
    case 1: cout << "Понедельник" << endl;
        break;
    case 2: cout << "Вторник" << endl;
        break;
    case 3: cout << "Среда" << endl;
        break;
    case 4: cout << "Четверг" << endl;
        break;
    case 5: cout << "Пятница" << endl;
        break;
    case 6: cout << "Суббота" << endl;
        break;
    case 7: cout << "Воскресенье" << endl;
        break;
    default: cout << "В неделе всего 7 дней" << endl;
    }

    return 0;
}
