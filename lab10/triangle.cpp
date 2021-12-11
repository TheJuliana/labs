#include "triangle.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

namespace tr {
    extern int height(720);
    extern int width(920);
    Triangle::Triangle(int x, int y, int r, int n, float velocity) {
        m_x = x;
        m_y = y;
        m_r = r;
        m_n = n;
        m_velocity = velocity;
        m_shape = new sf::CircleShape(m_r, m_n);
        m_shape->setOrigin(m_r, m_r);
        m_shape->setFillColor(sf::Color::Yellow);
        m_shape->setPosition(m_x, m_y)
    }
    Triangle::~Triangle() {
        delete m_shape;
    }
    sf::CircleShape* Triangle::Get() {
        return m_shape;
    }
    void Triangle::Move() {
        m_y += m_velocity;
        m_shape->setPosition(m_x, m_y);
        if (m_y > height) {
            m_y = height;
        }
    }
    void Triangle::SetY(int y) {
        m_y = y;
        m_shape->setPosition(m_x, m_y);
    }
    int Triangle::GetY() {
        return m_y;
    }
    void Triangle::SetVelocity(int velocity) {
        m_velocity = velocity;
    }
}