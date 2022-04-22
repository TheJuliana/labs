
#include "BMP.hpp"

namespace bmp {

    void BMP::WriteIn(const std::string& filename) {
        // Чтение файла
        std::ifstream in(filename, std::ios::binary);
        BMPHEADER bmpHeader;
        // Считать 14 байтов побайтово и заполнить структуру BMPHEADER
        in.read(reinterpret_cast<char*>(&bmpHeader), sizeof(BMPHEADER));

        if (!m_pixels.empty()) {
            m_pixels.erase(m_pixels.begin(), m_pixels.end());
        }

        BMPINFO bmpInfo;
        in.read(reinterpret_cast<char*>(&bmpInfo), sizeof(BMPINFO));// открыть файл для бинарного чтения

        m_width = bmpInfo.Width;
        m_height = bmpInfo.Height;

        for (int i = 0; i < m_height; i++) {
            m_pixels.emplace_back();
            for (int j = 0; j < m_width; j++) {
                m_pixels[i].emplace_back(Pixel{0, 0, 0});
            }
        }


        for (int i = 0; i < bmpInfo.Height; i++) {
            for (int j = 0; j < bmpInfo.Width; j++) {
                in.read(reinterpret_cast<char *>(&m_pixels[i][j]), sizeof(Pixel)); }

            if((3 * bmpInfo.Width) % 4 != 0) {
                for (int j = 0; j < 4 - (3 * bmpInfo.Width) % 4; j++) {
                    char c;
                    in.read(&c, 1);
                }
            }
        }

        for (int i = 0; i < m_height; i++) {
            m_coordinates.emplace_back();
            for (int j = 0; j < m_width; j++) {
                m_coordinates[i].emplace_back(math::Vec2d{{0, 0}});
            }
        }

        for (int i = 0; i < m_height; i++) {
            for (int j = 0; j < m_width; j++) {
                m_coordinates[i][j].set(0, 0, j);
                m_coordinates[i][j].set(1, 0, i);
            }
        }
    }

    void BMP::WriteOut(const std::string& filename) {
        if (m_width == 0 || m_height == 0) {
            throw std::logic_error("Zero height or width");
        };

        // Записать файл
        std::ofstream out(filename, std::ios::binary);

        // Формирование заголовка
        BMPHEADER bmpHeader_new;
        bmpHeader_new.Type = 0x4D42; // Тип данных BMP
        bmpHeader_new.Size = 14 + 40 + (3 * m_width * m_height);
        if (m_width % 4 != 0) {
            bmpHeader_new.Size += (4 - (3 * m_width) % 4) * m_height; }
        bmpHeader_new.OffBits = 54;
        bmpHeader_new.Reserved1 = 0;
        bmpHeader_new.Reserved2 = 0;

        out.write(reinterpret_cast<char*>(&bmpHeader_new), sizeof(BMPHEADER));

        // Формирование информации об изображении
        BMPINFO bmpInfo_new;
        bmpInfo_new.BitCount = 24;
        bmpInfo_new.ClrImportant = 0;
        bmpInfo_new.ClrUsed = 0;
        bmpInfo_new.Compression = 0;
        bmpInfo_new.Height = m_height;
        bmpInfo_new.Planes = 1;
        bmpInfo_new.Size = 40;
        bmpInfo_new.SizeImage = bmpHeader_new.Size - 54;
        bmpInfo_new.Width = m_width;
        bmpInfo_new.XPelsPerMeter = 0;
        bmpInfo_new.YPelsPerMeter = 0;

        out.write(reinterpret_cast<char*>(&bmpInfo_new), sizeof(BMPINFO));

        // Записать пиксели
        for (int i = 0; i < bmpInfo_new.Height; i++) {
            for (int j = 0; j < bmpInfo_new.Width; j++) {
                out.write(reinterpret_cast<char *>(&m_pixels[i][j]), sizeof(Pixel));
            }

            if ((3 * bmpInfo_new.Width) % 4 != 0) {
                for (int j = 0; j < 4 - (3 * bmpInfo_new.Width) % 4; j++) {
                    char c = 0;
                    out.write(&c, 1);
                }
            }
        }
    }

    void BMP::PinkFilter() {
        for (int i = 0; i < m_height; i++) {
            for (int j = 0; j < m_width; j++) {

                m_pixels[i][j].r = 255;
                if (m_pixels[i][j].b + 50 < 255) { m_pixels[i][j].b += 50; }
            }
        }
    }

    BMP::BMP() {
        m_width = 0;
        m_height = 0;
    }
    BMP::BMP(int width, int height) {
        m_width = width;
        m_height = height;

        for (int i = 0; i < m_height; i++) {
            for (int j = 0; j < m_width; j++) {
                m_pixels.emplace_back();
                m_pixels[i].emplace_back(Pixel{0,0,0});
            }
        }

        for (int i = 0; i < m_height; i++) {
            m_coordinates.emplace_back();
            for (int j = 0; j < m_width; j++) {
                m_coordinates[i].emplace_back(math::Vec2d{{0, 0}});
            }
        }

        for (int i = 0; i < m_height; i++) {
            for (int j = 0; j < m_width; j++) {
                m_coordinates[i][j].set(0, 0, j);
                m_coordinates[i][j].set(1, 0, i);
            }
        }

    }

    void BMP::Fill(Pixel pixel) {
        for (int i = 0; i < m_height; i++) {
            for (int j = 0; j < m_width; j++) {
                m_pixels[i][j] = pixel;
            }
        }
    }

    BMP::BMP(const BMP &bmp) {
        if (!m_pixels.empty()) {
            m_pixels.erase(m_pixels.begin(), m_pixels.end());
        }

        m_width = bmp.m_width;
        m_height = bmp.m_height;

        for (int i = 0; i < m_height; i++) {
            m_pixels.emplace_back();
            for (int j = 0; j < m_width; j++) {
                m_pixels[i].emplace_back(Pixel{0, 0, 0});
            }
        }

        for (int  i = 0; i < m_height; i++) {
            for (int j = 0; j < m_width; j++) {
                m_pixels[i][j] = bmp.m_pixels[i][j];
            }
        }

        for (int i = 0; i < m_height; i++) {
            m_coordinates.emplace_back();
            for (int j = 0; j < m_width; j++) {
                m_coordinates[i].emplace_back(math::Vec2d{{0, 0}});
            }
        }

        for (int i = 0; i < m_height; i++) {
            for (int j = 0; j < m_width; j++) {
                m_coordinates[i][j].set(0, 0, j);
                m_coordinates[i][j].set(1, 0, i);
            }
        }
    }

    BMP &BMP::operator=(const BMP &bmp) {
        if (!m_pixels.empty()) {
            m_pixels.erase(m_pixels.begin(), m_pixels.end());
        }

        m_width = bmp.m_width;
        m_height = bmp.m_height;

        for (int i = 0; i < m_height; i++) {
            m_pixels.emplace_back();
            for (int j = 0; j < m_width; j++) {
                m_pixels[i].emplace_back(Pixel{0, 0, 0});
            }
        }

        for (int  i = 0; i < m_height; i++) {
            for (int j = 0; j < m_width; j++) {
                m_pixels[i][j] = bmp.m_pixels[i][j];
            }
        }

        for (int i = 0; i < m_height; i++) {
            m_coordinates.emplace_back();
            for (int j = 0; j < m_width; j++) {
                m_coordinates[i].emplace_back(math::Vec2d{{0, 0}});
            }
        }

        for (int i = 0; i < m_height; i++) {
            for (int j = 0; j < m_width; j++) {
                m_coordinates[i][j].set(0, 0, j);
                m_coordinates[i][j].set(1, 0, i);
            }
        }

        return *this;
    }

    void BMP::Rotate(double angle) {
        //1.Смещение центра координат
        math::Vec2d T({ {
                          {(double)(m_width / 2)},
                          {(double)(m_height / 2)}
                  } });

        for(int i=0;i<m_height;i++) {
            for (int j = 0; j < m_width; j++) {
                m_coordinates[i][j] = m_coordinates[i][j] - T;
            }
        }
        //2. Поворот
        math::Mat22d R({ {
                           {cos(angle), sin(angle)},
                           {-sin(angle), cos(angle)}
                   } });

        for (int i = 0; i < m_height; i++)
            for (int j = 0; j < m_width; j++)
            {
                m_coordinates[i][j] = R * m_coordinates[i][j];
                //std::cout << m_coordinates[i][j] << std::endl;
            }
        //3. Перенос цветов в новый массив пикселей
        int maxX = INT_MIN;
        int minX = INT_MAX;
        int maxY = INT_MIN;
        int minY = INT_MAX;
        for (int i = 0; i < m_height; i++) {
            for (int j = 0; j < m_width; j++) {
                if (maxX < m_coordinates[i][j].get(0, 0)) { maxX = m_coordinates[i][j].get(0, 0); }
                if (minX > m_coordinates[i][j].get(0, 0)) { minX = m_coordinates[i][j].get(0, 0); }
                if (maxY < m_coordinates[i][j].get(1, 0)) { maxY = m_coordinates[i][j].get(1, 0); }
                if (minY > m_coordinates[i][j].get(1, 0)) { minY = m_coordinates[i][j].get(1, 0); }
            }
        }

        //Позволит не выйти за границы массива из-за ошибок округления
        maxX++;
        minX--;
        maxY++;
        minY--;

        int width = maxX - minX;
        int height = maxY - minY;


        //Переход к новой системе координат
        math::Vec2d shift({ {
                              {(double)(width/2)},
                              {(double)(height/2)}
                      } });

        for (int i = 0; i < m_height; i++) {
            for (int j = 0; j < m_width; j++) {
                m_coordinates[i][j] = m_coordinates[i][j] + shift;
            }
        }
        //Создание нового массива
        std::vector<std::vector<Pixel>> new_pixels;
        for (int i = 0; i < height; i++) {
            new_pixels.emplace_back();
            for (int j = 0; j < width; j++) {
                new_pixels[i].emplace_back(Pixel{0, 0, 0});
            }
        }
        std::vector<std::vector<math::Vec2d>> new_coordinates;
        for (int i = 0; i < height; i++) {
            m_coordinates.emplace_back();
            for (int j = 0; j < width; j++) {
                m_coordinates[i].emplace_back(math::Vec2d{{0, 0}});
            }
        }

        //копирование цвета
        for (int i = 0; i < m_height; i++) {
            for (int j = 0; j < m_width; j++) {
                int x = (int) (m_coordinates[i][j].get(0, 0));
                int y = (int) (m_coordinates[i][j].get(1, 0));
                new_pixels[y][x] = m_pixels[i][j];
            }
        }
        //удаление старого массива
        m_pixels.erase(m_pixels.begin(), m_pixels.end());
        m_coordinates.erase(m_coordinates.begin(), m_coordinates.end());


        m_pixels = new_pixels;
        m_coordinates = new_coordinates;
        m_width = width;
        m_height = height;

        //Интерполяция
        BMP::Interpolation();

    }

    void BMP::Interpolation() {
        int width = m_width-1; // берем -1 потому что после поворота оно считает ширину и длину на 1 больше
        int height = m_height-1;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                    if (i != 0 && j !=0 && i != height && j != width) { // пиксели, расположенные не по краям
                        int k = 9; // количество заполненных пикселей вокруг + 1
                        int l = 9; // данный коэфициент берем для каждого цвета
                        int m = 9;
                        if (m_pixels[i+1][j].b == 0) {k--;}; //если ячейка пустая то её не берем в расчет
                        if (m_pixels[i][j+1].b == 0) {k--;}; //для правильного среднего арифметического
                        if (m_pixels[i+1][j+1].b == 0) {k--;};
                        if (m_pixels[i+1][j-1].b == 0) {k--;};
                        if (m_pixels[i-1][j+1].b == 0) {k--;};
                        if (m_pixels[i-1][j].b == 0) {k--;};
                        if (m_pixels[i][j-1].b == 0) {k--;};
                        if (m_pixels[i-1][j+1].b == 0) {k--;};
                        //
                        if (m_pixels[i+1][j].g == 0) {l--;};
                        if (m_pixels[i][j+1].g == 0) {l--;};
                        if (m_pixels[i+1][j+1].g == 0) {l--;};
                        if (m_pixels[i+1][j-1].g == 0) {l--;};
                        if (m_pixels[i-1][j+1].g == 0) {l--;};
                        if (m_pixels[i-1][j].g == 0) {l--;};
                        if (m_pixels[i][j-1].g == 0) {l--;};
                        if (m_pixels[i-1][j+1].g == 0) {l--;};
                        //
                        if (m_pixels[i+1][j].r == 0) {m--;};
                        if (m_pixels[i][j+1].r == 0) {m--;};
                        if (m_pixels[i+1][j+1].r == 0) {m--;};
                        if (m_pixels[i+1][j-1].r == 0) {m--;};
                        if (m_pixels[i-1][j+1].r == 0) {m--;};
                        if (m_pixels[i-1][j].r == 0) {m--;};
                        if (m_pixels[i][j-1].r == 0) {m--;};
                        if (m_pixels[i-1][j+1].r == 0) {m--;};
                        // рассчитываем среднее арифметическое соседних ячеек для каждого цвета
                        m_pixels[i][j].b = ((m_pixels[i+1][j].b + m_pixels[i][j+1].b + m_pixels[i+1][j+1].b + m_pixels[i-1][j].b + m_pixels[i][j-1].b + m_pixels[i-1][j-1].b + m_pixels[i-1][j+1].b + m_pixels[i+1][j-1].b)/k);
                        m_pixels[i][j].g = ((m_pixels[i+1][j].g + m_pixels[i][j+1].g + m_pixels[i+1][j+1].g + m_pixels[i-1][j].g + m_pixels[i][j-1].g + m_pixels[i-1][j-1].g + m_pixels[i-1][j+1].g + m_pixels[i+1][j-1].g)/l);
                        m_pixels[i][j].r = ((m_pixels[i+1][j].r + m_pixels[i][j+1].r + m_pixels[i+1][j+1].r + m_pixels[i-1][j].r + m_pixels[i][j-1].r + m_pixels[i-1][j-1].r + m_pixels[i-1][j+1].r + m_pixels[i+1][j-1].r)/m);
                    } else if (i == 0 && j ==0 ) { //для ячейки в левом верхнем углу
                        int k = 4;
                        int l = 4;
                        int m = 4;
                        if (m_pixels[i+1][j].b == 0) {k--;};
                        if (m_pixels[i][j+1].b == 0) {k--;};
                        if (m_pixels[i+1][j+1].b == 0) {k--;};
                        //
                        if (m_pixels[i+1][j].g == 0) {l--;};
                        if (m_pixels[i][j+1].g == 0) {l--;};
                        if (m_pixels[i+1][j+1].g == 0) {l--;};
                        //
                        if (m_pixels[i+1][j].b == 0) {m--;};
                        if (m_pixels[i][j+1].b == 0) {m--;};
                        if (m_pixels[i+1][j+1].b == 0) {m--;};

                        m_pixels[i][j].b = ((m_pixels[i+1][j].b + m_pixels[i][j+1].b + m_pixels[i+1][j+1].b)/k);
                        m_pixels[i][j].g = ((m_pixels[i+1][j].g + m_pixels[i][j+1].g + m_pixels[i+1][j+1].g)/l);
                        m_pixels[i][j].r = ((m_pixels[i+1][j].r + m_pixels[i][j+1].r + m_pixels[i+1][j+1].r)/m);
                    } else if (i == height && j == 0) { // для ячейки в левом нижнем углу
                        int k = 4;
                        int l = 4;
                        int m = 4;
                        if (m_pixels[i-1][j].b == 0) {k--;};
                        if (m_pixels[i-1][j+1].b == 0) {k--;};
                        if (m_pixels[i][j+1].b == 0) {k--;};
                        //
                        if (m_pixels[i-1][j].g == 0) {l--;};
                        if (m_pixels[i-1][j+1].g == 0) {l--;};
                        if (m_pixels[i][j+1].g == 0) {l--;};
                        //
                        if (m_pixels[i-1][j].r == 0) {m--;};
                        if (m_pixels[i-1][j+1].r == 0) {m--;};
                        if (m_pixels[i][j+1].r == 0) {m--;};

                        m_pixels[i][j].b = ((m_pixels[i-1][j].b + m_pixels[i-1][j+1].b + m_pixels[i][j+1].b)/k);
                        m_pixels[i][j].g = ((m_pixels[i-1][j].g + m_pixels[i-1][j+1].g + m_pixels[i][j+1].g)/l);
                        m_pixels[i][j].r = ((m_pixels[i-1][j].r + m_pixels[i-1][j+1].r + m_pixels[i][j+1].r)/m);
                    } else if (i == height && j != width  && j !=0) { // если нижний ряд не по краям
                        int k = 6;
                        int l = 6;
                        int m = 6;
                        if (m_pixels[i][j+1].b == 0) {k--;};
                        if (m_pixels[i][j-1].b  == 0) {k--;};
                        if (m_pixels[i-1][j].b  == 0) {k--;};
                        if (m_pixels[i-1][j+1].b == 0) {k--;};
                        if (m_pixels[i-1][j-1].b  == 0) {k--;};
                        //
                        if (m_pixels[i][j+1].g == 0) {l--;};
                        if (m_pixels[i][j-1].g  == 0) {l--;};
                        if (m_pixels[i-1][j].g  == 0) {l--;};
                        if (m_pixels[i-1][j+1].g == 0) {l--;};
                        if (m_pixels[i-1][j-1].g  == 0) {l--;};
                        //
                        if (m_pixels[i][j+1].r == 0) {m--;};
                        if (m_pixels[i][j-1].r  == 0) {m--;};
                        if (m_pixels[i-1][j].r  == 0) {m--;};
                        if (m_pixels[i-1][j+1].r == 0) {m--;};
                        if (m_pixels[i-1][j-1].r  == 0) {m--;};

                        m_pixels[i][j].b = ((m_pixels[i][j+1].b + m_pixels[i][j-1].b + m_pixels[i-1][j].b + m_pixels[i-1][j+1].b + m_pixels[i-1][j-1].b)/k);
                        m_pixels[i][j].g = ((m_pixels[i][j+1].g + m_pixels[i][j-1].g + m_pixels[i-1][j].g + m_pixels[i-1][j+1].g + m_pixels[i-1][j-1].g)/l);
                        m_pixels[i][j].r = ((m_pixels[i][j+1].r + m_pixels[i][j-1].r + m_pixels[i-1][j].r + m_pixels[i-1][j+1].r + m_pixels[i-1][j-1].r)/m);
                    } else if (i == height && j == width) { // ячейка в правом нижнем углу
                        int k = 4;
                        int l = 4;
                        int m = 4;
                        if (m_pixels[i-1][j].b == 0) {k--;};
                        if (m_pixels[i][j-1].b == 0) {k--;};
                        if (m_pixels[i-1][j-1].b == 0) {k--;};
                        //
                        if (m_pixels[i-1][j].g == 0) {l--;};
                        if (m_pixels[i][j-1].g == 0) {l--;};
                        if (m_pixels[i-1][j-1].g == 0) {l--;};
                        //
                        if (m_pixels[i-1][j].r == 0) {m--;};
                        if (m_pixels[i][j-1].r == 0) {m--;};
                        if (m_pixels[i-1][j-1].r == 0) {m--;};
                        m_pixels[i][j].b = ((m_pixels[i-1][j].b + m_pixels[i][j-1].b + m_pixels[i-1][j-1].b)/k);
                        m_pixels[i][j].g = ((m_pixels[i-1][j].g + m_pixels[i][j-1].g + m_pixels[i-1][j-1].g)/l);
                        m_pixels[i][j].r = ((m_pixels[i-1][j].r + m_pixels[i][j-1].r + m_pixels[i-1][j-1].r)/m);
                    } else if (j == width && i != 0 && i != height) { // крайний правый ряд пикселей кроме угловых
                        int k = 6;
                        int l = 6;
                        int m = 6;
                        if (m_pixels[i-1][j].b == 0) {k--;};
                        if (m_pixels[i+1][j].b == 0) {k--;};
                        if (m_pixels[i][j-1].b == 0) {k--;};
                        if (m_pixels[i+1][j-1].b == 0) {k--;};
                        if (m_pixels[i-1][j-1].b == 0) {k--;};
                        //
                        if (m_pixels[i-1][j].g == 0) {l--;};
                        if (m_pixels[i+1][j].g == 0) {l--;};
                        if (m_pixels[i][j-1].g == 0) {l--;};
                        if (m_pixels[i+1][j-1].g == 0) {l--;};
                        if (m_pixels[i-1][j-1].g == 0) {l--;};
                        //
                        if (m_pixels[i-1][j].r == 0) {m--;};
                        if (m_pixels[i+1][j].r == 0) {m--;};
                        if (m_pixels[i][j-1].r == 0) {m--;};
                        if (m_pixels[i+1][j-1].r == 0) {m--;};
                        if (m_pixels[i-1][j-1].r == 0) {m--;};
                        m_pixels[i][j].b = ((m_pixels[i-1][j].b + m_pixels[i+1][j].b + m_pixels[i][j-1].b + m_pixels[i+1][j-1].b + m_pixels[i-1][j-1].b)/k);
                        m_pixels[i][j].g = ((m_pixels[i-1][j].g + m_pixels[i+1][j].g + m_pixels[i][j-1].g + m_pixels[i+1][j-1].g + m_pixels[i-1][j-1].g)/l);
                        m_pixels[i][j].r = ((m_pixels[i-1][j].r + m_pixels[i+1][j].r + m_pixels[i][j-1].r + m_pixels[i+1][j-1].r + m_pixels[i-1][j-1].r)/m);
                    } else if (j == width && i == 0) { // верхний правый пиксель
                        int k = 4;
                        int l = 4;
                        int m = 4;
                        if (m_pixels[i][j-1].b == 0) {k--;};
                        if (m_pixels[i+1][j-1].b == 0) {k--;};
                        if (m_pixels[i+1][j].b == 0) {k--;};
                        //
                        if (m_pixels[i][j-1].g == 0) {l--;};
                        if (m_pixels[i+1][j-1].g == 0) {l--;};
                        if (m_pixels[i+1][j].g == 0) {l--;};
                        //
                        if (m_pixels[i][j-1].r == 0) {m--;};
                        if (m_pixels[i+1][j-1].r == 0) {m--;};
                        if (m_pixels[i+1][j].r == 0) {m--;};
                        m_pixels[i][j].b = ((m_pixels[i][j-1].b + m_pixels[i+1][j-1].b + m_pixels[i+1][j].b)/k);
                        m_pixels[i][j].g = ((m_pixels[i][j-1].g + m_pixels[i+1][j-1].g + m_pixels[i+1][j].g)/l);
                        m_pixels[i][j].r = ((m_pixels[i][j-1].r + m_pixels[i+1][j-1].r + m_pixels[i+1][j].r)/m);
                    } else if (i == 0 && j != 0 && j != width) { //верхний ряд пикселей кроме угловых
                        int k = 6;
                        int l = 6;
                        int m = 6;
                        if (m_pixels[i][j-1].b == 0) {k--;}
                        if (m_pixels[i][j+1].b == 0) {k--;}
                        if (m_pixels[i+1][j].b == 0) {k--;}
                        if ( m_pixels[i+1][j+1].b == 0) {k--;}
                        if (m_pixels[i+1][j-1].b == 0) {k--;}
                        //
                        if (m_pixels[i][j-1].g == 0) {l--;}
                        if (m_pixels[i][j+1].g == 0) {l--;}
                        if (m_pixels[i+1][j].g == 0) {l--;}
                        if ( m_pixels[i+1][j+1].g == 0) {l--;}
                        if (m_pixels[i+1][j-1].g == 0) {l--;}
                        //
                        if (m_pixels[i][j-1].r == 0) {m--;}
                        if (m_pixels[i][j+1].r == 0) {m--;}
                        if (m_pixels[i+1][j].r == 0) {m--;}
                        if ( m_pixels[i+1][j+1].r == 0) {m--;}
                        if (m_pixels[i+1][j-1].r == 0) {m--;}

                        m_pixels[i][j].b = ((m_pixels[i][j-1].b + m_pixels[i][j+1].b + m_pixels[i+1][j].b + m_pixels[i+1][j+1].b + m_pixels[i+1][j-1].b)/k);
                        m_pixels[i][j].g = ((m_pixels[i][j-1].g + m_pixels[i][j+1].g + m_pixels[i+1][j].g + m_pixels[i+1][j+1].g + m_pixels[i+1][j-1].g)/l);
                        m_pixels[i][j].r = ((m_pixels[i][j-1].r + m_pixels[i][j+1].r + m_pixels[i+1][j].r + m_pixels[i+1][j+1].r + m_pixels[i+1][j-1].r)/m);

                    }
            }
        }
    }


}