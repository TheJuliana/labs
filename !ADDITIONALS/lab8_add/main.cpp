#include <iostream>
#include "parallelogram.hpp"
int main() {
    int width, height, angle;
    std::cout <<"Enter the length, width and "
                "angle between the adjacent sides"
                " of the parallelogram" << std::endl;
    std::cin >> width >> height >> angle;
    shapes::Parallelogram parallelogram(width, height, angle);
    std::cout << "S of your parallelogram =  " << parallelogram.Square() << std::endl;
    std::cout << "P of your parallelogram =  " << parallelogram.Perimeter() << std::endl;

    return 0;
}
