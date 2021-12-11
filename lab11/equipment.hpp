#pragma once
#include <string>
namespace eqp {
    class Modules {
    public:
        Modules(int address, std::string name, bool data);
        ~Modules();
        void Poll();
        void Print();

    private:
        std::string m_name;
        int m_address;
        bool m_data;
    };
}


