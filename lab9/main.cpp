/*Вариант 7.
Создайте 3 круга разных цветов и размеров.
Перемещайте их из исходного положения вниз до конца экрана с разной скоростью.
При достижении конца экрана остановите фигуры.*/


#include <iostream>
#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>

int main() {
    using namespace std::chrono_literals;

    sf::Image icon;
    icon.loadFromFile("../images/circle.png");
    sf::RenderWindow window(sf::VideoMode(800, 600), L"Кружочки");
    window.setIcon(720,720, icon.getPixelsPtr());

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::CircleShape shape1(90.0);
    float w1 = 90; float l1 = 90;
    shape1.setOrigin(w1, l1);
    shape1.setOutlineThickness(-10);
    shape1.setOutlineColor(sf::Color(255, 20, 147));
    shape1.setPointCount(100);
    shape1.setFillColor(sf::Color::Transparent);

    sf::CircleShape shape2(150.0);
    float  w2 = 150; float l2 = 150;
    shape2.setOrigin(w2, l2);
    shape2.setFillColor(sf::Color::White);
    sf::Texture texture;
    texture.loadFromFile("..images/earth.png");
    shape2.setTexture(&texture);
    shape2.setTextureRect(sf::IntRect(10, 10, 1600, 1600));

    sf::CircleShape shape3(120.0);
    float w3 = 120; float l3 = 120;
    shape3.setOrigin(w3, l3);
    shape3.setFillColor(sf::Color::Blue);

    float x1 = 150, y1 = 0;
    shape1.setPosition(x1, y1);
    float x2 = 300, y2 = 0;
    shape2.setPosition(x2, y2);
    float x3 = 600, y3 = 0;
    shape3.setPosition(x3, y3);

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        y1 += 3;
        y2 += 2;
        y3 += 4;

        if (y1 > 600)
            y1 = 600;
        if (y2 > 600)
            y2 = 600;
        if (y3 > 600)
            y3 = 600;

        shape1.setPosition(x1, y1);
        shape2.setPosition(x2, y2);
        shape3.setPosition(x3, y3);

        window.clear();

        window.draw(shape2);
        window.draw(shape1);
        window.draw(shape3);

        window.display();

        std::this_thread::sleep_for(20ms);
    }

    return 0;
}
