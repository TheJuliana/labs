
#include <bitset>
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
        m_size = bmpInfo.SizeImage*3;
        //m_size = m_width*m_height*3;

        for (int i = 0; i < m_height; i++) {
            m_pixels.emplace_back();
            for (int j = 0; j < m_width; j++) {
                m_pixels[i].emplace_back(Pixel{0, 0, 0, false});
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
        m_size = m_width*m_height*3;

        for (int i = 0; i < m_height; i++) {
            for (int j = 0; j < m_width; j++) {
                m_pixels.emplace_back();
                m_pixels[i].emplace_back(Pixel{0,0,0, false});
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
        m_size = m_width*m_height*3;

        for (int i = 0; i < m_height; i++) {
            m_pixels.emplace_back();
            for (int j = 0; j < m_width; j++) {
                m_pixels[i].emplace_back(Pixel{0, 0, 0, false});
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
        m_size = m_width*m_height*3;

        for (int i = 0; i < m_height; i++) {
            m_pixels.emplace_back();
            for (int j = 0; j < m_width; j++) {
                m_pixels[i].emplace_back(Pixel{0, 0, 0, false});
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
        m_size = m_width*m_height*3;

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

    void BMP::Encording(std::string &encodedText) {
        std::cout << "------ENCORDING-------" << std::endl;
        if (m_size < encodedText.size()*3) { //на один символ требуется 3 байта картинки так как мы шифруем последние три бита каждого байта т.е
                                            //на один символ требуется один пиксель
            std::cout << "too much" << std::endl;
        } else {
            int k = 0;
            std::cout << "!!!!" << encodedText.length() << std::endl;
            std::cout << "!!!!" << encodedText.size() << std::endl;
            const int n = encodedText.length();

            for (int i = 0; i < m_height; i++) {
                for (int j = 0; j < m_width; j++) {
                    if (k >= n) {break;}
                    std::cout << "!!!!!!!!!!Current ASCII Symbol - " << (int) encodedText[k] << std::endl;
                    std::cout << "BITSET of encoded char " << std::bitset<sizeof(encodedText[k]) * CHAR_BIT>(encodedText[k]) << std::endl;

                    //std::cout << "!!" << (int)encodedText[k] << std::endl;
                    unsigned char mask = 248;//0b11111000 - маска для обнуления последних трех битов цвета
                    std::cout << "BITSET " << std::bitset<sizeof(mask) * CHAR_BIT>(mask) << std::endl;
                    unsigned char mask2 = 7;//0b00000111; - макска для получения вставляемых битов символа

                    unsigned char num =  m_pixels[i][j].b;
                    std::cout << "BITSET " << std::bitset<sizeof(num) * CHAR_BIT>(num) << std::endl;
                    std::cout << "before blue crypt symbol: " << std::bitset<sizeof(m_pixels[i][j].b) * CHAR_BIT>(m_pixels[i][j].b) << std::endl;
                    m_pixels[i][j].b = m_pixels[i][j].b & mask; //обнуляем последние три бита в цвете
                    unsigned char part = ((unsigned char)encodedText[k]) & mask2; //берем последние три бита из байта символа
                    std::cout << "part bits: " << std::bitset<sizeof(part) * CHAR_BIT>(part) << std::endl;
                    m_pixels[i][j].b = m_pixels[i][j].b | part; //вставляем их в последние три бита цвета
                    std::cout << "after blue crypt symbol: " << std::bitset<sizeof(m_pixels[i][j].b) * CHAR_BIT>(m_pixels[i][j].b) << std::endl;

                    std::cout << "before green crypt symbol: " << std::bitset<sizeof(m_pixels[i][j].g) * CHAR_BIT>(m_pixels[i][j].g) << std::endl;
                    mask2 = mask2 << 3; //сдвигаем маску чтобы получить центральные три бита символа
                    part = (unsigned char)encodedText[k] & mask2; //получаем эти три бита
                    part = part >> 3; //сдвигаем биты в край
                    m_pixels[i][j].g &= mask; //m_pixels[i][j].g = m_pixels[i][j].g & mask; //обнуляем последние три бита в цвете
                    std::cout << "part bits: " << std::bitset<sizeof(part) * CHAR_BIT>(part) << std::endl;
                    m_pixels[i][j].g |= part; //m_pixels[i][j].g = m_pixels[i][j].g | part; // вставляем биты из символа в последние нулевые биты цвета
                    std::cout << "after green crypt symbol: " << std::bitset<sizeof(m_pixels[i][j].g) * CHAR_BIT>(m_pixels[i][j].g) << std::endl;

                    std::cout << "before red crypt symbol: " << std::bitset<sizeof(m_pixels[i][j].r) * CHAR_BIT>(m_pixels[i][j].r) << std::endl;
                    mask2 = mask2 << 3; //еще раз сдвигаем маску чтобы получить первые три бита символа
                    part = (unsigned char)encodedText[k] & mask2; // получаем эти биты
                    //part = part >> 3; // сдвигаем их в правый край
                    part = part >> 6;
                    m_pixels[i][j].r = m_pixels[i][j].r & mask; //обнуляем последние три бита в цвете
                    std::cout << "part bits: " << std::bitset<sizeof(part) * CHAR_BIT>(part) << std::endl;
                    m_pixels[i][j].r = m_pixels[i][j].r | part;  // вставляем полученные биты из символа в последние нулевые биты цвета
                    std::cout << "after red crypt symbol: " << std::bitset<sizeof(m_pixels[i][j].r) * CHAR_BIT>(m_pixels[i][j].r) << std::endl;


                    m_pixels[i][j].encorded = true;
                    std::cout << "!!!!WARNING k = " << k << std::endl;

                    k++;

                }
            }

        }
    }

    void BMP::Decording(std::string &decodedText) {
        std::cout << "------DECORDING-------" << std::endl;
        for (int i = 0; i < m_height; i++) {
            for (int j = 0; j < m_width; j++) {
                if (m_pixels[i][j].encorded) {
                    unsigned char codeSymbol = 0;

                    unsigned char mask = 7;//0b00000111;
                    std::cout << "BITSET mask " << std::bitset<sizeof(mask) * CHAR_BIT>(mask) << std::endl;

                    std::cout << "----" << std::endl;

                    std::cout << "BITSET pixel RED " << std::bitset<sizeof(m_pixels[i][j].r) * CHAR_BIT>(m_pixels[i][j].r) << std::endl;
                    unsigned char part = m_pixels[i][j].r & mask; //считываем последние три бита с кодом
                    std::cout << "red BITSET part " << std::bitset<sizeof(part) * CHAR_BIT>(part) << std::endl;
                    part = part << 6;
                    codeSymbol = codeSymbol | part; //вставляем их в три первые бита декодируемого символа

                    std::cout << "BITSET part " << std::bitset<sizeof(codeSymbol) * CHAR_BIT>(codeSymbol) << std::endl;
                    std::cout << "----" << std::endl;

                    std::cout << "BITSET pixel GREEN " << std::bitset<sizeof(m_pixels[i][j].g) * CHAR_BIT>(m_pixels[i][j].g) << std::endl;
                    part = m_pixels[i][j].g & mask; //считываем последние три бита с кодом
                    std::cout << "green BITSET part " << std::bitset<sizeof(part) * CHAR_BIT>(part) << std::endl;
                    part = part << 3; //двигаем их в центральные три бита
                    std::cout << "green BITSET part <-" << std::bitset<sizeof(part) * CHAR_BIT>(part) << std::endl;

                    codeSymbol = codeSymbol | part; //вставляем их в  центральные три бита символа
                    std::cout << "BITSET part " << std::bitset<sizeof(codeSymbol) * CHAR_BIT>(codeSymbol) << std::endl;
                    std::cout << "----" << std::endl;

                    std::cout << "BITSET pixel BLUE " << std::bitset<sizeof(m_pixels[i][j].b) * CHAR_BIT>(m_pixels[i][j].b) << std::endl;
                    part = m_pixels[i][j].b & mask; //считываем последние три бита с кодом
                    std::cout << "blue BITSET part " << std::bitset<sizeof(part) * CHAR_BIT>(part) << std::endl;
                    std::cout << "blue BITSET part <- " << std::bitset<sizeof(part) * CHAR_BIT>(part) << std::endl;
                    codeSymbol = codeSymbol | part; //вставляем их в последние три бита
                    std::cout << "BITSET codeSymbol " << std::bitset<sizeof(codeSymbol) * CHAR_BIT>(codeSymbol) << std::endl;
                    std::cout << "----" << std::endl;

                    decodedText.push_back(codeSymbol);
                    std::cout << "BITSET codeSymbol" << std::bitset<sizeof(codeSymbol) * CHAR_BIT>(codeSymbol) << std::endl;
                    std::cout << "!" << (int)codeSymbol << std::endl;
                }
            }
        }
    }


}