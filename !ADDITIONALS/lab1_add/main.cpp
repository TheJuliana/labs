/* Задача №1
«Грузоперевозки»

Ограничение по времени 2 сек.
Ограничение по памяти 256 Мб

Судоходная компания предлагает два вида транспорта для перевозки сыпучих грузов. 
Грузовик первого типа может перевезти Q1 тонн груза за одну поездку. 
Разовая поездка стоит P1, и цена не зависит от уровня загрузки транспортного средства. 
Для грузовика второго типа эти значения равны Q2 и P2 соответственно.

Найдите минимальную стоимость перевозки A тонн груза. */


#include <iostream>
#include <cmath>
#include <chrono>
using namespace std;
int main() {
    // Q1 т. - количество тонн груза за одну поездку первого типа
    //P1 - цена поездки первого типа
    //Q2 - количество тонн груза за одну поездку второго типа
    //P2 - цена поездки второго типа
    //A - количество тонн груза всего
    int Q1, P1, Q2, P2, A;
    cin >> Q1 >> P1 >> Q2 >> P2 >> A;

    //проверка условия
    if ((Q1 >= 1000) || (P1 >= 1000) || (Q2 >= 1000) || (P2 >= 1000) || (A >= 1000)) {
        cout << "Invalid input data format" << endl;
        return 0;
    }

    //проверка времени программы
    auto begin = chrono::steady_clock::now();

    int val1 = P1/Q1; //цена за одну тонну
    int val2 = P2/Q2;
    int sum = 0;
    int n;
    float rem;
    if (val1 < val2) {
        n = A/Q1;
        rem = A%Q1;
        sum = n*P1;
        if ((rem < Q2) && (P2 < P1)) {
            sum += P2;
        } else if ((rem > Q2) && (P2 < P1)) {
            sum += ceil(rem/Q2)*P2;
        } else if ((rem < Q1) && (P1 < P2)) {
            sum += P1;
        } else {
            sum += ceil(rem/Q1)*P1;
        }
    } else {
        n = A/Q2;
        rem = A%Q2;
        sum = n*P2;
        if ((rem < Q1) && (P1 < P2)) {
            sum += P1;
        } else if ((rem > Q1) && (P1 < P2)) {
            sum += ceil(rem/Q1)*P1;
        } else if ((rem < Q2) && (P2 < P1)) {
            sum += P2;
        } else {
            sum += ceil(rem/Q2)*P2;
        }
    }
    cout << sum << endl;

    auto end = chrono::steady_clock::now();
    auto elapsed_ms = chrono::duration_cast<chrono::milliseconds>(end - begin);

    cout << "Runtime: " << elapsed_ms.count() << endl;

    return 0;
}
