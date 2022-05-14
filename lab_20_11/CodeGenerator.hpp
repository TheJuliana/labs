#pragma once
#include "Languages.hpp"
#include "Java.hpp"
#include "C_PLUS_PLUS.hpp"
#include "PHP.hpp"
#include <exception>
#include <memory>

std::string generateCode(std::string& inputLanguage) {
    std::unique_ptr<Languages> lang;
    if (inputLanguage == "C++") {
        lang = std::make_unique<C_PLUS_PLUS>(C_PLUS_PLUS());
        return lang->someRelatedThing();
    } else if (inputLanguage == "Java") {
        lang = std::make_unique<Java>(Java());
        return lang->someRelatedThing();
    } else if (inputLanguage == "PHP") {
        lang = std::make_unique<PHP>(PHP());
        return lang->someRelatedThing();
    } else {
        throw std::logic_error("WRONG");
    };

}



