/*
Задача №4
«Стеганография»

Воспользуйтесь классом для работы с BMP-изображениями и зашифруйте произвольную текстовую информацию.
 -------------------------
 Для зашифровки будем использовать метод LSB(Least Significant Bit):
 Данный метод заключается в выделении наименее значимых
 бит изображения-контейнера с последующей их заменой на биты сообщения.
 Поскольку замене подвергаются лишь наименее значимые биты,
 разница между исходным изображением-контейнером и контейнером,
 содержащим скрытые данные невелика и обычно незаметна для человеческого глаза
*/

#include "BMP.hpp"
using namespace bmp;
int main() {
    BMP in(400, 400);
    in.Fill({222,222,222});

    std::string st = "HELLO";
    for (auto c: st) {
        std::cout << (int)c <<std::endl;
    }

    std::string otc;

    std::cout << "------ENCORDING-------" << std::endl;
    in.Encording(st);
    std::cout << "------DECORDING-------" << std::endl;
    in.Decording(otc);
    std::cout << otc << std::endl;
    return 0;
}
