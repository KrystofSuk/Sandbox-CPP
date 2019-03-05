#include "rgb.h"

RGB::RGB(){
    R = 0;
    G = 0;
    B = 0;
}

RGB::RGB(int _R, int _G, int _B){
    R = _R;
    G = _G;
    B = _B;
}

void RGB::SET(int _R, int _G, int _B){
    R = _R;
    G = _G;
    B = _B;
}

int RGB::GetR(){
    return R;
}

int RGB::GetG(){
    return G;
}

int RGB::GetB(){
    return B;
}

double RGB::GetGrayscale(){
    return (double)(0.21f*(double)R + 0.72f*(double)G + 0.07f*(double)B)/255;
}
