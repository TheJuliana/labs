#include <fstream>
#include <iomanip>
#include "scene.hpp"

namespace mt
{
    Scene::Scene(int width, int height)
    {
        m_width = width;
        m_height = height;
        m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(m_width, m_height), "3D Engine");
        m_texture = std::make_unique<sf::Texture>();
        m_texture->create(m_width, m_height);
        m_sprite = std::make_unique<sf::Sprite>(*m_texture);

        Intrinsic intrinsic = { 960.0, 540.0, 960.0, 540.0 };
        Point position = { 467340.0, -60.0, 6063520.0 };
        Angles angles = { 0.0,1.8,0.0 };
        m_camera = std::make_unique<Camera>(m_width, m_height, intrinsic, position, angles);

        m_points = new Point[400000];

        // уход сферы
        /*double r = 1;
        for(double fi = 0; fi < 6.28; fi += 0.01)
            for (double teta = 0; teta < 1.57; teta += 0.01)
            {
                m_points[m_size].x = r * sin(teta) * cos(fi);
                m_points[m_size].y = r * sin(teta) * sin(fi) + 5;
                m_points[m_size].z = r * cos(teta);
                m_size++;
            }*/
    }
    Scene::~Scene()
    {
        if (m_points != nullptr)
            delete[] m_points;
    }

    void Scene::LifeCycle()
    {
        //std::cout << std::setprecision(3) << std::fixed;
        double y0 = 1;

        std::ifstream in("points.txt");
        if (!in.is_open()) {
            std::cerr << "File points.txt not found";
            return;
        }

        std::vector<Point> points;
        std::vector<Pixel> pixels;
        //double number;
        /*points.emplace_back();
        pixels.emplace_back();*/

        double x, y, z;
        int r,g,b;

        while (!in.eof()) {

           in >> x >> y >> z >> r >> g >> b;

           points.emplace_back(Point{x, y, z});
           pixels.emplace_back(Pixel{static_cast<uint8_t>(r), static_cast<uint8_t>(g), static_cast<uint8_t>(b), 255});

        }

        m_size = 0;
        for (int i = 0; i < points.size(); i++) {
            m_points[i].x = points[i].x;
            m_points[i].y = points[i].y;
            m_points[i].z = points[i].z;
            m_size++;
        }

        while (m_window->isOpen()) {

            sf::Event event;
            while (m_window->pollEvent(event))
                if (event.type == sf::Event::Closed)
                    m_window->close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                m_camera->dZ(0.1);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                m_camera->dZ(-0.1);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                m_camera->dX(-0.1);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                m_camera->dX(0.1);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                m_camera->dPitch(-0.02);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                m_camera->dPitch(0.02);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                m_camera->dRoll(-0.02);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                m_camera->dRoll(0.02);
            }

            /*y0 += 0.02;
            m_size = 0;
            double r = 1;
            for (double fi = 0; fi < 6.28; fi += 0.01)
                for (double teta = 0; teta < 1.57; teta += 0.01)
                {
                    m_points[m_size].x = r * sin(teta) * cos(fi);
                    m_points[m_size].y = r * sin(teta) * sin(fi) + y0;
                    m_points[m_size].z = r * cos(teta);
                    m_size++;
                }
*/
            //
            for (int i = 0; i < m_size; i++)
                m_camera->ProjectPoint(m_points[i], {pixels[i].r, pixels[i].g, pixels[i].b, 255});

            m_texture->update((uint8_t*)m_camera->Picture(), 1920, 1080, 0, 0);
            m_camera->Clear();

            m_window->clear();
            m_window->draw(*m_sprite);

            m_window->display();

        }
    }
}
