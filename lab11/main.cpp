#include <iostream>
#include <vector>
#include "equipment.hpp"
using std::cin;
using std::endl;
using std::cout;
int main() {
    setlocale(LC_ALL, "RU");

    std::vector<eqp::Modules*> modules;

    eqp::Modules* module = new eqp::Modules(1, "Reallab NL16HV", false);
    modules.push_back(module);

    eqp::Modules* module1 = new eqp::Modules(2, "ЭНМВ-1-24", false);
    modules.push_back(module1);

    for(auto& module: modules) {
        module -> Poll();
        module -> Print();

    }

    for (auto & module : modules) {
        delete module;
    }
    return 0;
}
