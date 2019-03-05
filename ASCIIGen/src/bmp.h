#ifndef BMP_H
#define BMP_H

class BMP
{
    private:
        int x;
        int y;
        int colorNumber;
    public:
        BMP(int _x, int _y, int _colorNumber);
        int GetX();
        int GetY();
        int GetColorNumber();
        ~BMP();
};
#endif
