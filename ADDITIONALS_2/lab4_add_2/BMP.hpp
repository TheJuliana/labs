#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <valarray>
#include "matrix.h"



namespace bmp {
#pragma pack(1) // Отключить выравнивание
    struct BMPHEADER
    {
        unsigned short    Type;
        unsigned int      Size;
        unsigned short    Reserved1;
        unsigned short    Reserved2;
        unsigned int      OffBits;
    };
#pragma pack()

#pragma pack(1)
    struct BMPINFO
    {
        unsigned int    Size;
        int             Width;
        int             Height;
        unsigned short  Planes;
        unsigned short  BitCount;
        unsigned int    Compression;
        unsigned int    SizeImage;
        int             XPelsPerMeter;
        int             YPelsPerMeter;
        unsigned int    ClrUsed;
        unsigned int    ClrImportant;
    };
#pragma pack()

#pragma pack(1)
    struct Pixel
    {
        unsigned char b;
        unsigned char g;
        unsigned char r;
        bool encorded = false;
    };
#pragma pack()

    class BMP {
    private:
        int m_width, m_height, m_size;
        std::vector<std::vector<Pixel>> m_pixels;
        std::vector<std::vector<math::Vec2d>> m_coordinates;
        void Interpolation();
    public:
        BMP();
        BMP(const BMP& bmp);
        BMP(int width, int height);
        void WriteIn(const std::string& filename);
        void WriteOut(const std::string& filename);
        void PinkFilter();
        void Fill(Pixel pixel);
        void Rotate(double angle);

        //СТЕГАНОГРАФИЯ
        void Encording(std::string& encodedText);
        void Decording(std::string& decodedText);
        void Cleaner();
        BMP& operator=(const BMP& bmp);
    };



}


