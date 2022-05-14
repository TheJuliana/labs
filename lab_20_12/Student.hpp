#pragma once
#include <iostream>
#include <memory>
#include <string>
#include "Teacher.hpp"

class Teacher;

class Student {
    std::string m_name;
    std::weak_ptr<Teacher> m_teacher;
public:
    Student(const std::string& name) {
        m_name = name;
        std::cout << m_name << " created\n";
    }
    ~Student() {
        std::cout << m_name << " destroyed\n";
    }
    std::string getName() {
        return m_name;
    }
};


