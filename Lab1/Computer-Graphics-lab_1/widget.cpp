#include "widget.h"
#include "QDebug"
#include <QRegularExpression>

Widget::Widget(QWidget *parent)
    : QWidget(parent) {
    RGB_Grad->installEventFilter(this);
    CreatingModels();
    DarkTheme();
    sliderR->setMaximum(255);
    sliderR->setMinimum(0);
    sliderG->setMaximum(255);
    sliderG->setMinimum(0);
    sliderB->setMaximum(255);
    sliderB->setMinimum(0);
    chosenColorl = new QVBoxLayout;
    RightL = new QHBoxLayout;
    zone3 = new QGridLayout;
    zone2 = new QGridLayout;
    zone1 = new QGridLayout;

    rgb_color = new QLabel("RGB");
    cmyk_color = new QLabel("CMYK");
    hsv_color = new QLabel("HSV");

    zones =  new QHBoxLayout;
    main = new QVBoxLayout;
    main_ = new QHBoxLayout;

    zone1->addWidget(rgb_color,1,0);
    zone2->addWidget(cmyk_color,1,0);
    zone3->addWidget(hsv_color,1,0);


    mas[0] = RGB;
    mas[1] = CMYK;
    mas[2] = HSV;

    zone1->addWidget(mas[0],2,0);
    zone2->addWidget(mas[1],2,0);
    zone3->addWidget(mas[2],2,0);

    zones->addLayout(zone1);
    zones->addLayout(zone2);
    zones->addLayout(zone3);

    exit->setText("=EXIT=");

    RGB_Grad->setCursor(Qt::CrossCursor);

    sliderR->setCursor(Qt::PointingHandCursor);
    sliderG->setCursor(Qt::PointingHandCursor);
    sliderB->setCursor(Qt::PointingHandCursor);


    main->addWidget(new QLabel{"Gradient Choosing:    R    G    B"});
    main_->addWidget(RGB_Grad);
    main_->addWidget(sliderR);
    main_->addWidget(sliderG);
    main_->addWidget(sliderB);
    main_->addLayout(RightL);
    chosenColorl->setAlignment(Qt::AlignmentFlag::AlignVCenter);
    chosenColorl->addWidget(new QLabel{"Choosen color:"});
    chosenColorl->addWidget(currentColorLabel);
    chosenColorl->addWidget(exit);
    main_->addLayout(chosenColorl);
    main_->setAlignment(Qt::AlignmentFlag::AlignLeft);
    main->addLayout(main_);
    main->addSpacing(15);
    main->addLayout(zones);


    this->setLayout(main);
    connect(sliderR,SIGNAL(valueChanged(int)),SLOT(GradientColor()));
    connect(sliderG,SIGNAL(valueChanged(int)),SLOT(GradientColor()));
    connect(sliderB,SIGNAL(valueChanged(int)),SLOT(GradientColor()));
    connect(exit,SIGNAL(clicked(bool)),SLOT(ExitButtonPressed()));
    connect(R,SIGNAL(editingFinished()),SLOT(set_RGB()));
    connect(G,SIGNAL(editingFinished()),SLOT(set_RGB()));
    connect(B,SIGNAL(editingFinished()),SLOT(set_RGB()));
    connect(C,SIGNAL(editingFinished()),SLOT(set_CMYK()));
    connect(M,SIGNAL(editingFinished()),SLOT(set_CMYK()));
    connect(Y,SIGNAL(editingFinished()),SLOT(set_CMYK()));
    connect(K,SIGNAL(editingFinished()),SLOT(set_CMYK()));

    connect(HSV_H,SIGNAL(editingFinished()),SLOT(set_HSV()));
    connect(HSV_S,SIGNAL(editingFinished()),SLOT(set_HSV()));
    connect(HSV_V,SIGNAL(editingFinished()),SLOT(set_HSV()));

    //sliders connect
    connect(Rs,SIGNAL(sliderReleased()),SLOT(set_Slider_RGB()));
    connect(Gs,SIGNAL(sliderReleased()),SLOT(set_Slider_RGB()));
    connect(Bs,SIGNAL(sliderReleased()),SLOT(set_Slider_RGB()));

    connect(Cs,SIGNAL(sliderReleased()),SLOT(set_Slider_CMYK()));
    connect(Ms,SIGNAL(sliderReleased()),SLOT(set_Slider_CMYK()));
    connect(Ys,SIGNAL(sliderReleased()),SLOT(set_Slider_CMYK()));
    connect(Ks,SIGNAL(sliderReleased()),SLOT(set_Slider_CMYK()));

    connect(HHs,SIGNAL(sliderReleased()),SLOT(set_Slider_HSV()));
    connect(SSs,SIGNAL(sliderReleased()),SLOT(set_Slider_HSV()));
    connect(VVs,SIGNAL(sliderReleased()),SLOT(set_Slider_HSV()));


    //this->setWindowFlags(Qt::CustomizeWindowHint);
    installALLinfo();
    //this->setFixedSize(500,400);
    //qApp->installEventFilter(this);
    //this->setFixedSize(525,500);
}

 void Widget::CreatingModels() {
    RGB = new QGroupBox;
    HSV = new QGroupBox;
    CMYK = new QGroupBox;

    RGB_l = new QGridLayout;
    HSV_l = new QGridLayout;
    CMYK_l = new QGridLayout;

    QRegularExpression rgx1("[0-9]|[1-9][0-9]|0[0-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5]");
    QValidator *comValidator1 = new  QRegularExpressionValidator(rgx1, this);
    R->setValidator(comValidator1);
    G->setValidator(comValidator1);
    B->setValidator(comValidator1);
    QRegularExpression rgx2("[0-9]|[1-9][0-9]|0[0-9][0-9]|100");
    QValidator *comValidator2 = new  QRegularExpressionValidator(rgx2, this);
    C->setValidator(comValidator2);
    M->setValidator(comValidator2);
    Y->setValidator(comValidator2);
    K->setValidator(comValidator2);
    HSV_H->setValidator(comValidator2);
    HSV_S->setValidator(comValidator2);
    HSV_V->setValidator(comValidator2);
    RGB_Grad->setFixedSize(this->width()/6,this->width()/6);
    currentColorLabel->setFixedSize(this->width()/12,this->width()/12);

    Rs->setOrientation(Qt::Horizontal);
    Gs->setOrientation(Qt::Horizontal);
    Bs->setOrientation(Qt::Horizontal);
    Rs->setMaximum(255);
    Rs->setMinimum(0);
    Gs->setMaximum(255);
    Gs->setMinimum(0);
    Bs->setMaximum(255);
    Bs->setMinimum(0);
    RGB_l->addWidget(new QLabel{"R:"},1,0);
    RGB_l->addWidget(R,1,1);
    RGB_l->addWidget(new QLabel{"G:"},2,0);
    RGB_l->addWidget(G,2,1);
    RGB_l->addWidget(new QLabel{"B:"},3,0);
    RGB_l->addWidget(B,3,1);
    RGB_l->addWidget(Rs,1,2);
    RGB_l->addWidget(Gs,2,2);
    RGB_l->addWidget(Bs,3,2);
    RGB->setLayout(RGB_l);


    HHs->setOrientation(Qt::Horizontal);
    SSs->setOrientation(Qt::Horizontal);
    VVs->setOrientation(Qt::Horizontal);
    HHs->setRange(0,100);
    SSs->setRange(0,100);
    VVs->setRange(0,100);
    HSV_l->addWidget(new QLabel{"H:"},1,0);
    HSV_l->addWidget(HSV_H,1,1);
    HSV_l->addWidget(new QLabel{"S:"},2,0);
    HSV_l->addWidget(HSV_S,2,1);
    HSV_l->addWidget(new QLabel{"V:"},3,0);
    HSV_l->addWidget(HSV_V,3,1);
    HSV_l->addWidget(HHs,1,2);
    HSV_l->addWidget(SSs,2,2);
    HSV_l->addWidget(VVs,3,2);
    HSV->setLayout(HSV_l);


    Cs->setOrientation(Qt::Horizontal);
    Ms->setOrientation(Qt::Horizontal);
    Ys->setOrientation(Qt::Horizontal);
    Ks->setOrientation(Qt::Horizontal);
    Cs->setRange(0,100);
    Ms->setRange(0,100);
    Ys->setRange(0,100);
    Ks->setRange(0,100);
    CMYK_l->addWidget(new QLabel{"C:"},1,0);
    CMYK_l->addWidget(C,1,1);
    CMYK_l->addWidget(new QLabel{"M:"},2,0);
    CMYK_l->addWidget(M,2,1);
    CMYK_l->addWidget(new QLabel{"Y:"},3,0);
    CMYK_l->addWidget(Y,3,1);
    CMYK_l->addWidget(new QLabel{"K:"},4,0);
    CMYK_l->addWidget(K,4,1);
    CMYK_l->addWidget(Cs,1,2);
    CMYK_l->addWidget(Ms,2,2);
    CMYK_l->addWidget(Ys,3,2);
    CMYK_l->addWidget(Ks,4,2);
    CMYK->setLayout(CMYK_l);
}

 void Widget::paintEvent(QPaintEvent*) {
     QPixmap pix(RGB_Grad->width(),RGB_Grad->height());
     QPixmap pix2(currentColorLabel->width(),currentColorLabel->height());
     QPainter painter(&pix);
     QPainter painter2(&pix2);
     QLinearGradient gradl(0,0,pix.width(),0);
     gradl.setColorAt(0,Qt::black);
     gradl.setColorAt(1,base_c);
     painter.setBrush(gradl);
     painter.drawRect(0,0,RGB_Grad->width(),RGB_Grad->height());
     RGB_Grad->setPixmap(pix);
     painter2.setBrush(color.getColor());
     painter2.drawRect(0,0,currentColorLabel->width(),currentColorLabel->height());
     currentColorLabel->setPixmap(pix2);
 }

 void Widget::DarkTheme() {
         QPalette darkPalette;
         darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
         darkPalette.setColor(QPalette::WindowText, Qt::white);
         darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
         darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
         darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
         darkPalette.setColor(QPalette::ToolTipText, Qt::white);
         darkPalette.setColor(QPalette::Text, Qt::white);
         darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
         darkPalette.setColor(QPalette::ButtonText, Qt::white);
         darkPalette.setColor(QPalette::BrightText, Qt::red);
         darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
         darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
         darkPalette.setColor(QPalette::HighlightedText, Qt::black);
         qApp->setPalette(darkPalette);
 }

  void Widget::GradientColor() {
      base_c.setRed(sliderR->value());
      base_c.setGreen(sliderG->value());
      base_c.setBlue(sliderB->value());
  }

  void Widget::ExitButtonPressed() {
      this->close();
  }

  void Widget::set_RGB() {
       color.setColorRGB(R->text().toInt(),G->text().toInt(),B->text().toInt());
       installALLinfo();
  }

  void Widget::set_CMYK() {
      color.setColorCMYK(C->text().toFloat()/100,M->text().toFloat()/100,Y->text().toFloat()/100,K->text().toFloat()/100);
      installALLinfo();
  }

  void Widget::set_HSV() {
      color.setColorHSV(HSV_H->text().toFloat()/100,HSV_S->text().toFloat()/100,HSV_V->text().toFloat()/100);
      installALLinfo();
  }

  void Widget::set_Slider_HSV() {
      color.setColorHSV((float)HHs->value()/100,(float)SSs->value()/100,(float)VVs->value()/100);
      installALLinfo();
  }

  void Widget::set_Slider_RGB() {
      color.setColorRGB(Rs->value(),Gs->value(),Bs->value());
      installALLinfo();
  }

  void Widget::set_Slider_CMYK()
  {
      color.setColorCMYK((float)Cs->value()/100,(float)Ms->value()/100,(float)Ys->value()/100,(float)Ks->value()/100);
      installALLinfo();
  }

  Widget::~Widget() {}

  void Widget::installALLinfo() {
     currentColor = color.getColor();
     R->setText(QString::number(color.getColor().red()));
     G->setText(QString::number(color.getColor().green()));
     B->setText(QString::number(color.getColor().blue()));

     Rs->setSliderPosition(color.getColor().red());
     Gs->setSliderPosition(color.getColor().green());
     Bs->setSliderPosition(color.getColor().blue());

     C->setText(QString::number(color.getColor().cyanF()*100));
     M->setText(QString::number(color.getColor().magentaF()*100));
     Y->setText(QString::number(color.getColor().yellowF()*100));
     K->setText(QString::number(color.getColor().blackF()*100));

     Cs->setSliderPosition(color.getColor().cyanF()*100);
     Ms->setSliderPosition(color.getColor().magentaF()*100);
     Ys->setSliderPosition(color.getColor().yellowF()*100);
     Ks->setSliderPosition(color.getColor().blackF()*100);

     HSV_H->setText(QString::number(color.getColor().hsvHueF()*100));
     HSV_S->setText(QString::number(color.getColor().hsvSaturationF()*100));
     HSV_V->setText(QString::number(color.getColor().valueF()*100));

     HHs->setSliderPosition(color.getColor().hsvHueF()*100);
     SSs->setSliderPosition(color.getColor().hsvSaturationF()*100);
     VVs->setSliderPosition(color.getColor().valueF()*100);
  }

bool Widget::eventFilter(QObject *obj, QEvent *event) {
    if(event->type() == QEvent::MouseButtonPress && obj == RGB_Grad) {
        QMouseEvent* cur = dynamic_cast<QMouseEvent*>(event);
        int x = cur->pos().x()+RGB_Grad->x();
        int y = cur->pos().y()+RGB_Grad->y();
        color.base4ToOthers(QWidget::grab(QRect(x, y, 1, 1)).toImage().pixelColor(0, 0));
        installALLinfo();
    }
    return false;
}
