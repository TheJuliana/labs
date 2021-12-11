#pragma once
#include <SFML/Graphics.hpp>
namespace tr {
    extern int height;
    extern int width;
    class Triangle{
    public:
        Triangle(int x, int y, int r, int n, float velocity);
        ~Triangle();
        sf::CircleShape* Get();
        void Move();
        void SetY(int y);
        int GetY();
        void SetVelocity(int velocity);

    private:
        int m_x, m_y, m_r, m_n;
        float m_velocity;
        sf::CircleShape* m_shape;
    };
}