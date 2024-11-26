#ifndef TESTER_H
#define TESTER_H

#include <QtTest/QtTest>
#include "mainwindow.h"


class Tester : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void cleanup();
    void testRGBToCMYKConversionIntoSliders();
    void testRGBToCMYKConversionIntoBoxes();
    void testCMYKToHLSConversionIntoSliders();
    void testCMYKToHLSConversionIntoBoxes();
    void testHLSToRGBConversionIntoSliders();
    void testHLSToRGBConversionIntoBoxes();

private:
    MainWindow *mainWindow; // Указатель на тестируемый класс
};



#endif


