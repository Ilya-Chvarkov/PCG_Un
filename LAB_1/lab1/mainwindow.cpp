#include "mainwindow.h"
#include <QColor>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createUI();
}

MainWindow::~MainWindow() {}

void MainWindow::createUI()
{
/*
    QColor rrr(255,200,0);
    qDebug()<< rrr.red()<<"\n";
    qDebug()<< rrr.hue()<<"\n";
    qDebug()<< rrr.magenta()<<"\n";
    qDebug()<< rrr.lightness()<<"\n";
*/


    rSlider = new QSlider(Qt::Horizontal);
    gSlider = new QSlider(Qt::Horizontal);
    bSlider = new QSlider(Qt::Horizontal);

    rSlider->setRange(0, 255);
    gSlider->setRange(0, 255);
    bSlider->setRange(0, 255);

    rEdit = new QLineEdit;
    gEdit = new QLineEdit;
    bEdit = new QLineEdit;

    rEdit->setText("0");
    gEdit->setText("0");
    bEdit->setText("0");


    QGroupBox *rgbBox = new QGroupBox("RGB");
    QGridLayout *rgbLayout = new QGridLayout;
    rgbLayout->addWidget(new QLabel("R:"), 0, 0);
    rgbLayout->addWidget(rSlider, 0, 1);
    rgbLayout->addWidget(rEdit, 0, 2);
    rgbLayout->addWidget(new QLabel("G:"), 1, 0);
    rgbLayout->addWidget(gSlider, 1, 1);
    rgbLayout->addWidget(gEdit, 1, 2);
    rgbLayout->addWidget(new QLabel("B:"), 2, 0);
    rgbLayout->addWidget(bSlider, 2, 1);
    rgbLayout->addWidget(bEdit, 2, 2);
    rgbBox->setLayout(rgbLayout);


/////////////////////////////////////////////////////////////////
    cSlider = new QSlider(Qt::Horizontal);
    mSlider = new QSlider(Qt::Horizontal);
    ySlider = new QSlider(Qt::Horizontal);
    kSlider = new QSlider(Qt::Horizontal);

    cSlider->setRange(0, 100);
    mSlider->setRange(0, 100);
    ySlider->setRange(0, 100);
    kSlider->setRange(0, 100);
    kSlider->setValue(100);
    // //
    cEdit = new QLineEdit;
    mEdit = new QLineEdit;
    yEdit = new QLineEdit;
    kEdit = new QLineEdit;

    cEdit->setText("0");
    mEdit->setText("0");
    yEdit->setText("0");
    kEdit->setText("100");

    QGroupBox *cmykBox = new QGroupBox("CMYK");
    QGridLayout *cmykLayout = new QGridLayout;
    cmykLayout->addWidget(new QLabel("C:"), 0, 0);
    cmykLayout->addWidget(cSlider, 0, 1);
    cmykLayout->addWidget(cEdit, 0, 2);
    cmykLayout->addWidget(new QLabel("M:"), 1, 0);
    cmykLayout->addWidget(mSlider, 1, 1);
    cmykLayout->addWidget(mEdit, 1, 2);
    cmykLayout->addWidget(new QLabel("Y:"), 2, 0);
    cmykLayout->addWidget(ySlider, 2, 1);
    cmykLayout->addWidget(yEdit, 2, 2);
    cmykLayout->addWidget(new QLabel("K:"), 3, 0);
    cmykLayout->addWidget(kSlider, 3, 1);
    cmykLayout->addWidget(kEdit, 3, 2);
    cmykBox->setLayout(cmykLayout);
/////////////////////////////////////////////////////////////////////


    hSlider = new QSlider(Qt::Horizontal);
    lSlider = new QSlider(Qt::Horizontal);
    sSlider = new QSlider(Qt::Horizontal);

    hSlider->setRange(0, 360);
    lSlider->setRange(0, 100);
    sSlider->setRange(0, 100);


    hEdit = new QLineEdit;
    lEdit = new QLineEdit;
    sEdit = new QLineEdit;

    hEdit->setText("0");
    lEdit->setText("0");
    sEdit->setText("0");



    QGroupBox *hlsBox = new QGroupBox("HLS");
    QGridLayout *hlsLayout = new QGridLayout;
    hlsLayout->addWidget(new QLabel("H:"), 0, 0);
    hlsLayout->addWidget(hSlider, 0, 1);
    hlsLayout->addWidget(hEdit, 0, 2);
    hlsLayout->addWidget(new QLabel("L:"), 1, 0);
    hlsLayout->addWidget(lSlider, 1, 1);
    hlsLayout->addWidget(lEdit, 1, 2);
    hlsLayout->addWidget(new QLabel("S:"), 2, 0);
    hlsLayout->addWidget(sSlider, 2, 1);
    hlsLayout->addWidget(sEdit, 2, 2);
    hlsBox->setLayout(hlsLayout);
//////////////////////////////////////////////////////

    colorDisplay = new QLabel;
    colorDisplay->setFixedSize(100, 100);
    colorDisplay->setStyleSheet("background-color: rgb(255, 255, 255);");

    QPushButton *colorPickerButton = new QPushButton("Выбрать цвет");

    // Layouts
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(rgbBox);
    mainLayout->addWidget(cmykBox);
    mainLayout->addWidget(hlsBox);
    mainLayout->addWidget(colorDisplay);
    mainLayout->addWidget(colorPickerButton);

    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
////////////////////////////////////////////////////////
///
///
///

    connect(rSlider, &QSlider::valueChanged, this, &MainWindow::updateRGB);
    connect(gSlider, &QSlider::valueChanged, this, &MainWindow::updateRGB);
    connect(bSlider, &QSlider::valueChanged, this, &MainWindow::updateRGB);

    connect(rEdit, &QLineEdit::editingFinished, this, &MainWindow::updateRGB2);
    connect(gEdit, &QLineEdit::editingFinished, this, &MainWindow::updateRGB2);
    connect(bEdit, &QLineEdit::editingFinished, this, &MainWindow::updateRGB2);


    connect(cSlider, &QSlider::valueChanged, this, &MainWindow::updateCMYK);
    connect(mSlider, &QSlider::valueChanged, this, &MainWindow::updateCMYK);
    connect(ySlider, &QSlider::valueChanged, this, &MainWindow::updateCMYK);
    connect(kSlider, &QSlider::valueChanged, this, &MainWindow::updateCMYK);

    connect(cEdit, &QLineEdit::editingFinished, this, &MainWindow::updateCMYK2);
    connect(mEdit, &QLineEdit::editingFinished, this, &MainWindow::updateCMYK2);
    connect(yEdit, &QLineEdit::editingFinished, this, &MainWindow::updateCMYK2);
    connect(kEdit, &QLineEdit::editingFinished, this, &MainWindow::updateCMYK2);

    connect(hSlider, &QSlider::valueChanged, this, &MainWindow::updateHLS);
    connect(lSlider, &QSlider::valueChanged, this, &MainWindow::updateHLS);
    connect(sSlider, &QSlider::valueChanged, this, &MainWindow::updateHLS);

    connect(hEdit, &QLineEdit::editingFinished, this, &MainWindow::updateHLS2);
    connect(lEdit, &QLineEdit::editingFinished, this, &MainWindow::updateHLS2);
    connect(sEdit, &QLineEdit::editingFinished, this, &MainWindow::updateHLS2);

    connect(this, &MainWindow::colorChanged, this, &MainWindow::updateInf);
    connect(colorPickerButton, &QPushButton::clicked, this, &MainWindow::pickColor);



}

void MainWindow::updateInf()
{

    if(uppp == true)
    {
        return;
    }
    uppp = true;

    int r = Tek.red();
    int g = Tek.green();
    int b = Tek.blue();

    int c = Tek.cyan();
    int m = Tek.magenta();
    int y = Tek.yellow();
    int k = Tek.black();

    int h = Tek.hue();
    int l = Tek.lightness();
    int s = Tek.saturation();

    if(updatingRGB == false)
    {
        rSlider->setValue(r);
        gSlider->setValue(g);
        bSlider->setValue(b);
    }
    if(updatingRGB2 == false)
    {
        rEdit->setText(QString::number(r));
        gEdit->setText(QString::number(g));
        bEdit->setText(QString::number(b));
    }
    if(updatingCMYK == false){
        cSlider->setValue((int)(c/2.55));
        mSlider->setValue((int)(m/2.55));
        ySlider->setValue((int)(y/2.55));
        kSlider->setValue((int)(k/2.55));
    }
    if(updatingCMYK2 == false){
        cEdit->setText(QString::number((int)(c/2.55)));
        mEdit->setText(QString::number((int)(m/2.55)));
        yEdit->setText(QString::number((int)(y/2.55)));
        kEdit->setText(QString::number((int)(k/2.55)));
    }



    if(updatingHSL == false)
    {
        hSlider->setValue(h);
        sSlider->setValue((int)s/2.55);
        lSlider->setValue((int)l/2.55);
    }

    if(updatingHSL2 == false){
        hEdit->setText(QString::number(h));
        lEdit->setText(QString::number((int)(l/2.55)));
        sEdit->setText(QString::number((int)(s/2.55)));
    }

    uppp = false;
}


void MainWindow::updateRGB()
{
    if(updatingRGB == true)
    {
        return;
    }
    updatingRGB = true;

    QColor color = rgbToColor();
    updateColorDisplay(color);
    setColor(color);

    updatingRGB = false;

}

void MainWindow::updateRGB2()
{
    if(updatingRGB2 == true)
    {
        return;
    }
    updatingRGB2 = true;
    QString rr = rEdit->text();
    QString gg = gEdit->text();
    QString bb = bEdit->text();

    bool ok;

    int r = rr.toInt(&ok);
    int g = gg.toInt(&ok);
    int b = bb.toInt(&ok);

    QColor color(r,g,b);

    updateColorDisplay(color);
    setColor(color);
    updatingRGB2 = false;
}

void MainWindow::updateCMYK()
{
    if(updatingCMYK == true)
    {
        return;
    }
    updatingCMYK = true;

    QColor color = cmykToColor();
    updateColorDisplay(color);
    setColor(color);
    updatingCMYK = false;
}

void MainWindow::updateCMYK2()
{
    if(updatingCMYK2 == true)
    {
        return;
    }
    updatingCMYK2 = true;


    QString cc = cEdit->text();
    QString mm = mEdit->text();
    QString yy = yEdit->text();
    QString kk = kEdit->text();

    bool ok;

    int c = (int)(cc.toInt(&ok)*2.55);
    int m = (int)(mm.toInt(&ok)*2.55);
    int y = (int)(yy.toInt(&ok)*2.55);
    int k = (int)(kk.toInt(&ok)*2.55);

    QColor color;
    color.setCmyk(c, m, y, k);
    updateColorDisplay(color);
    setColor(color);
    updatingCMYK2 = false;

}

void MainWindow::updateHLS()
{
    if(updatingHSL == true)
    {
        return;
    }
    updatingHSL = true;
    QColor color = hlsToColor();
    updateColorDisplay(color);
    setColor(color);
    updatingHSL = false;
}

void MainWindow::updateHLS2()
{
    if(updatingHSL2 == true)
    {
        return;
    }
    updatingHSL2 = true;
    QString hh = hEdit->text();
    QString ll = lEdit->text();
    QString ss = sEdit->text();

    bool ok;

    int h = (int)(hh.toInt(&ok));
    int l = (int)(ll.toInt(&ok)*2.55);
    int s = (int)(ss.toInt(&ok)*2.55);


    QColor color;
    color.setHsl(h, s, l);
    updateColorDisplay(color);
    setColor(color);
    updatingHSL2 = false;
}


QColor MainWindow::rgbToColor()
{
    int r = rSlider->value();
    int g = gSlider->value();
    int b = bSlider->value();
    return QColor(r, g, b);
}

QColor MainWindow::cmykToColor()
{
    int c = (cSlider->value())*2.55;
    int m = (mSlider->value())*2.55;
    int y = (ySlider->value())*2.55;
    int k = (kSlider->value())*2.55;
    QColor our;
    our.setCmyk(c,m,y,k);
    return our;
}

QColor MainWindow::hlsToColor()
{
    qreal h = hSlider->value();
    qreal l = lSlider->value()*2.55;
    qreal s = sSlider->value()*2.55;
    QColor our;
    our.toHsl();
    our.setHsl(h,s,l);
    our.toRgb();
    return our;
}


void MainWindow::pickColor()
{
    QColor color = QColorDialog::getColor(rgbToColor(), this, "Выбор цвета");
    setColor(color);
}


void MainWindow::updateColorDisplay(const QColor &color)
{
    colorDisplay->setStyleSheet(QString("background-color: %1;").arg(color.name()));
}


void MainWindow::setColor(const QColor& newColor) {
    if (Tek != newColor) {
        Tek = newColor;
         // Извещаем об изменении цвета
    }
    emit colorChanged(Tek);
}
