#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "QGradient"
#include "QLabel"
#include "QHBoxLayout"
#include "QComboBox"
#include "QVBoxLayout"
#include "QGridLayout"
#include "QGroupBox"
#include "QPainter"
#include <QApplication>
#include "QLineEdit"
#include "converter.h"
#include <QPushButton>
#include <QEvent>
#include <QMouseEvent>
#include <QValidator>
class Widget : public QWidget
{
    Q_OBJECT

//public signals:
  //  void activated(int,OBject);
private slots:

    void GradientColor();

    void ExitButtonPressed();

    void set_RGB();

    void set_CMYK();

    void set_HSV();
// sliders
    void set_Slider_HSV();
    void set_Slider_RGB();
    void set_Slider_CMYK();
public:
    void setAllInfo();
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void installALLinfo();
    void CreatingModels();
    void paintEvent(QPaintEvent*);
    bool eventFilter(QObject *object, QEvent *event);
    void DarkTheme();

    QLabel* rgb_color;
    QLabel* cmyk_color;
    QLabel* hsv_color;

    QVBoxLayout* chosenColorl;
    QHBoxLayout* RightL;

    QHBoxLayout* zones;
    QVBoxLayout* main;
    QHBoxLayout* main_;

    QGridLayout* zone1;
    QGridLayout* zone2;
    QGridLayout* zone3;

    QLabel* marker1;
    QLabel* marker2;
    QLabel* marker3;
    QLabel* currentColorLabel =  new QLabel;

    QGroupBox* RGB;
    QGroupBox* CMYK;
    QGroupBox* HSV;

    QGridLayout* RGB_l;
    QGridLayout* CMYK_l;
    QGridLayout* HSV_l;

    QLabel* RGB_Grad = new QLabel;

    QLineEdit* R = new QLineEdit;
    QLineEdit* G = new QLineEdit;
    QLineEdit* B = new QLineEdit;

    QSlider* Rs = new QSlider;
    QSlider* Gs = new QSlider;
    QSlider* Bs = new QSlider;

    QLineEdit* C = new QLineEdit;
    QLineEdit* M = new QLineEdit;
    QLineEdit* Y = new QLineEdit;
    QLineEdit* K = new QLineEdit;

    QSlider* Cs = new QSlider;
    QSlider* Ms = new QSlider;
    QSlider* Ys = new QSlider;
    QSlider* Ks = new QSlider;

    QLineEdit* HSV_H = new QLineEdit;
    QLineEdit* HSV_S = new QLineEdit;
    QLineEdit* HSV_V = new QLineEdit;

    QSlider* HHs = new QSlider;
    QSlider* SSs = new QSlider;
    QSlider* VVs = new QSlider;

    QGroupBox* mas[3];

    QColor base_c = Qt::black;
    QSlider* sliderR = new QSlider;
    QSlider* sliderG = new QSlider;
    QSlider* sliderB = new QSlider;

    QPushButton* exit = new QPushButton;

    converter color;
    QStringList switch_c {"RGB","CMYK","HSV"};
    QColor currentColor = Qt::black;

};
#endif // WIDGET_H