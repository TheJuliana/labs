/*Создайте N (0<N<100) треугольников.
Перемещайте их из исходного положения вниз до конца экрана с разной скоростью.
При достижении конца экрана остановите фигуры.*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <chrono>
#include <thread>
#include "triangle.hpp"

using std::endl;
using std::cout;
using std::cin;

const int N = 40;

int main() {
    srand(time(0));

    sf::Texture texture;
    if (!texture.loadFromFile("../images/triangle.jpg")) {
        std::cout << "ERROR: not found skye.jpg" << std:: endl;
        return -1;
    }
    sf::Sprite background(texture);



    sf::RenderWindow window(sf::VideoMode(tr::width, tr::height), L"Fallen cheese");

    sf::Image icon;

    if (!icon.loadFromFile("../images/cheese.jpg")) {
        std::cout << "ERROR: not found icon cheese.jpg" << std:: endl;
        return -1;
    }
    window.setIcon(600, 600, icon.getPixelsPtr());

    std::vector<tr::Triangle*> triangles;
    for (int i = 0; i <= tr::width; i += tr::width / N)
        triangles.push_back(new tr::Triangle(i , 0, 25, 3, rand() % 5 + 4));

        while(window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
            for (const auto& triangle : triangles) {
                triangle ->Move();
                if (triangle->GetY() > tr::height) {
                    triangle->SetVelocity(rand() % 5 + 4);
                    triangle->SetY(0);

                }
            }
            window.clear();
            window.draw(background);
            for (const auto& triangle : triangles) {
                window.draw(*triangle->Get());
            }
            window.display();

            std::this_thread::sleep_for(std::chrono::milliseconds(40));
        }

        for (const auto& triangle : triangles) {
            delete triangle;
        }
        triangles.clear();

        return 0;

}
