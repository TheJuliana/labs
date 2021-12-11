#pragma once
#include <iostream>
#define PI 3.14

namespace shapes {
    class Parallelogram {
    public:
        Parallelogram();
        ~Parallelogram();
        Parallelogram(int width, int length, int angle);
        double Square() const;
        int Perimeter() const;
    private:
        int _width{};
        int _length{};
        int _angle{};
    };

}