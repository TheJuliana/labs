#pragma once
#include "Languages.hpp"
#include "Java.hpp"
#include "C_PLUS_PLUS.hpp"
#include "PHP.hpp"
#include <exception>

std::string generateCode(std::string& inputLanguage) {
    Languages *lang;
    if (inputLanguage == "C++") {
        lang = new C_PLUS_PLUS();
        return lang->someRelatedThing();
    } else if (inputLanguage == "Java") {
        lang = new Java();
        return lang->someRelatedThing();
    } else if (inputLanguage == "PHP") {
        lang = new PHP();
        return lang->someRelatedThing();
    } else {
        throw std::logic_error("WRONG");
    };

}



