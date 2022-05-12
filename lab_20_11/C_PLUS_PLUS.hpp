#pragma once
#include "Languages.hpp"

class C_PLUS_PLUS : public Languages {
private:
public:
    C_PLUS_PLUS() : Languages() {

        std::cout << "C_PLUS_PLUS constructor" << std::endl;
        m_extension = "cpp";
    };
    virtual ~C_PLUS_PLUS() {
        std::cout << "C_PLUS_PLUS class: destructor" << std::endl;
    };
    std::string someRelatedThing() override {
        std::cout << "C_PLUS_PLUS class: someRelatedThing function" << std::endl;
        std::string code = "c++_code." + m_extension;
        return code;
    }
};


