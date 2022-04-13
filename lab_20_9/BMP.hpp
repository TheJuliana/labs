#pragma once
#include <iostream>
#include <fstream>
#include <vector>

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
    };
#pragma pack()

    class BMP {
    private:

    public:
        BMP();
        static void WriteIn(std::vector<std::vector<Pixel>>& pixels, std::ifstream& in, BMPINFO& bmpInfo);
        static void WriteOut(std::vector<std::vector<Pixel>>& pixels, std::ofstream& out, BMPINFO& bmpInfo);

        static void PinkFilter(std::vector<std::vector<Pixel>>& pixels, BMPINFO& bmpInfo);
    };



}


