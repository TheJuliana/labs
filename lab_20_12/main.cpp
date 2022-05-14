/*
Лабораторная работа №12
«Умные указатели»

Создайте класс Преподаватель и класс Студент.
В классе Преподаватель предусмотрите поле, которое будет содержать указатели на всех студентов,
относящихся к данному преподавателю. В классе Студент предусмотрите поле,
которое будет указывать на преподавателя, у которого данный студент обучается.
Используйте умные указатели. Проследите, чтобы деструкторы всех классов отрабатывали штатно.
Примите меры, если это не так.
*/


#include <iostream>
#include <map>
#include "Teacher.hpp"

int main() {
    auto John{std::make_shared<Student>("John")};
    auto Ben{std::make_shared<Student>("John")};
    auto MrSmith{std::make_shared<Teacher>("Mr.Smith")};

    MrSmith->addStudent(John);
    MrSmith->addStudent(Ben);
    MrSmith->getStudents();
    /*std::map<std::string , std::string> university;
    university[John->getName()] = MrSmith->getName();
    university[Ben->getName()] = MrSmith->getName();

    for (auto it = university.begin(); it != university.end(); ++it) {
        std::cout << it->first << " " << it->second << '\n';
    }*/


    return 0;
}
