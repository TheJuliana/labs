#include "equipment.hpp"
#include <string>
#include <random>
#include <iostream>

namespace eqp {
    Modules::Modules(int address, std::string name, bool data) {
        m_address = address;
        m_name = name;
        m_data = data;
    }
    Modules::~Modules() {}

    void Modules::Poll() {
        m_data = rand() % 2;
    }

    void Modules::Print() {
        std::cout << "Input port: " << m_address << " Module's name: " << m_name << "\n" << "Current state of the input: " << m_data << std::endl;
    }
}