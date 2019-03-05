#ifndef RGB_H
#define RGB_H


class RGB{
    private:
        int R;
        int G;
        int B;
    public:
        RGB();
        RGB(int _R, int _G, int _B);
        void SET(int _R, int _G, int _B);
        int GetR();
        int GetG();
        int GetB();
        double GetGrayscale();
};

#endif