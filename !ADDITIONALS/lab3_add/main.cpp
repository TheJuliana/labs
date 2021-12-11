#include <iostream>
#include "Functions.hpp"
using std::cin;
using std::endl;
using std::cout;

int main() {
    int seq[1000];
    int x = 0;
    fn::Read(seq, x);

    fn::Replace(seq, x);

    fn::Output(seq, x);
}
