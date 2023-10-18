#ifndef CONVERTER_H
#define CONVERTER_H

#include <QColor>
#include <cmath>

struct info {
    double first = 0;
    double second = 0;
    double third = 0;
};

class converter
{
public:
    converter();
    void convert_RGB();
    void setColorRGB(int r,int g,int b);
    void setColorCMYK(float c,float m,float y,float k);
    void setColorHSV(float h,float s,float v);
    void base4ToOthers(QColor a);
    QColor getColor() const;
    info XYZ;
    info LAB;
private:
    QColor base4;
};

#endif // CONVERTER_H
