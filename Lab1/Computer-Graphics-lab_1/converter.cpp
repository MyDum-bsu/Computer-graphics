#include "converter.h"

converter::converter(){}

void converter::setColorRGB(int r, int g, int b) {
    base4.setRgb(r,g,b);
    base4ToOthers(base4);
}

void converter::setColorCMYK(float c, float m, float y, float k) {
    base4.setCmykF(c,m,y,k);
    base4ToOthers(base4);
}

void converter::setColorHSV(float h, float s, float v) {
    base4.setHsvF(h,s,v);
    base4ToOthers(base4);
}

void converter::base4ToOthers(QColor a) {
  base4 = a;
}

QColor converter::getColor() const {
    return base4;
}

