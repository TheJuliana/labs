/*
Лабораторная работа №5
«Бинарное дерево поиска»
Дана последовательность операций «добавить вершину»,
«удалить вершину» и «найти ключ» над бинарным деревом поиска.
Выполнить эти операции.

Вход
Во входном файле записана последовательность команд вида “+x” или “-x” или “?x” или “E”.
 Здесь x – натуральное число не более 10^9.
 Команда "+x" означает "добавить в дерево число x",
 команда "-x" означает "удалить из дерева число x",
 команда "?x" - "найти в дереве слово x".
 Команда "E" означает "завершить операции с деревом".
 Каждая команда записана в отдельной строке, начиная с первой позиции, и не содержит пробелов.

Выход
В выходной файл запишите результаты выполнения команд "?x" в том порядке,
 в котором они присутствуют во входном файле.
 Если слово найдено, записать в файл его глубину в дереве, в противном случае - символ 'n'.
*/
#include "functions.hpp"

int main() {
    tr::Elem* root = nullptr;

    std::ifstream in("..//input.txt");
    std::ofstream out("..//output.txt");

    std::string command;

    while (getline(in, command)) {
        std::cout << command << std::endl;
        char ch = command[0];
        command.erase(command.begin());
        //std::cout << "!" << command << std::endl;
        if (command.size() > 0) {
            int numb = stoi(command);
            if (ch == '+') {
                tr::TreeInsert(root, numb);
            } else if (ch == '-') {
                tr::TreeDelete(root, numb);
            } else { //если '?'
                if (tr::TreeSearch(root, numb) == nullptr) {
                    out << "n";
                } else {
                    out << tr::FindDepth(root, numb);
                }
            }
        } else if (ch == 'E') { //если 'E'
            break;
        }
    }
    in.close();
    std::cout << "---------" << std::endl;
    tr::TreePass(root);

    return 0;
}
