#include "parallelogram.hpp"
#include <cmath>

namespace shapes {
    Parallelogram::Parallelogram() = default;
    Parallelogram::Parallelogram(int width, int length, int angle) {
        _width = width;
        _length = length;
        _angle = angle;
        if (width <= 0) {
            std::cout << "This value cannot be negative, "
                         "it will become equal to 1" << std::endl;
            _width = 1;
        }
        if (length <= 0) {
            std::cout << "This value cannot be negative, "
                         "it will become equal to 1" << std::endl;
            _length = 1;
        }
    }

    Parallelogram::~Parallelogram() = default;

    double Parallelogram::Square() const {
        return _width * _length * sin(_angle * PI / 180);
    }

    int Parallelogram::Perimeter() const {
        return (_width * 2) + (_length * 2);
    }
}