#include "bmp.h"

BMP::BMP(int _x, int _y, int _colorNumber)
{
    x = _x;
    y = _y;
    colorNumber = _colorNumber;
}

int BMP::GetColorNumber(){
    return colorNumber;
}

int BMP::GetX(){
    return x;
}

int BMP::GetY(){
    return y;
}

BMP::~BMP()
{
}