#include "tester.h"

void Tester::init()
{
    mainWindow = new MainWindow();
}

void Tester::cleanup()
{
    delete mainWindow;
}



void Tester::testRGBToCMYKConversionIntoSliders()
{
    // set RGB
    mainWindow->setColor(QColor(0, 255, 255)); // Cyan

    // Checking CMYK values
    int c, m, y, k;

    c = mainWindow->cSlider->value();
    m = mainWindow->mSlider->value();
    y = mainWindow->ySlider->value();
    k = mainWindow->kSlider->value();


    QCOMPARE(c, 100);
    QCOMPARE(m, 0);
    QCOMPARE(y, 0);
    QCOMPARE(k, 0);
}

void Tester::testRGBToCMYKConversionIntoBoxes()
{
    // set RGB
    mainWindow->setColor(QColor(0, 255, 255));

    // Checking CMYK values
    QString c, m, y, k;
    c = mainWindow->cEdit->text();
    m = mainWindow->mEdit->text();
    y = mainWindow->yEdit->text();
    k = mainWindow->kEdit->text();

    QCOMPARE(c, "100");
    QCOMPARE(m, "0");
    QCOMPARE(y, "0");
    QCOMPARE(k, "0");
}

void Tester::testCMYKToHLSConversionIntoSliders()
{
    // set CMYK
    QColor yy;
    yy.setCmyk(0,255,255,0);
    mainWindow->setColor(yy);
    int h,s,l;
    h = mainWindow->hSlider->value();
    l = mainWindow->lSlider->value();
    s = mainWindow->sSlider->value();

    QCOMPARE(h,0);
    QCOMPARE(s,100);
    QCOMPARE(l,50);
}

void Tester::testCMYKToHLSConversionIntoBoxes()
{
    QColor yy;
    yy.setCmyk(0,255,255,0);
    mainWindow->setColor(yy);


    QString h,s,l;
    h = mainWindow->hEdit->text();
    l = mainWindow->lEdit->text();
    s = mainWindow->sEdit->text();


    QCOMPARE(h, "0");
    QCOMPARE(l, "50");
    QCOMPARE(s, "100");
}

void Tester::testHLSToRGBConversionIntoSliders()
{
    QColor yy;
    yy.setHslF(0,1.0,0.5);
    mainWindow->setColor(yy);

    int r,g,b;
    r = mainWindow->rSlider->value();
    g = mainWindow->gSlider->value();
    b = mainWindow->bSlider->value();
    QCOMPARE(r,255);
    QCOMPARE(g,0);
    QCOMPARE(b,0);
}

void Tester::testHLSToRGBConversionIntoBoxes()
{
    QColor yy;
    yy.setHslF(0,1.0,0.5);
    mainWindow->setColor(yy);
    QString r,g,b;
    r = mainWindow->rEdit->text();
    g = mainWindow->gEdit->text();
    b = mainWindow->bEdit->text();


    QCOMPARE(r,"255");
    QCOMPARE(g,"0");
    QCOMPARE(b,"0");
}





