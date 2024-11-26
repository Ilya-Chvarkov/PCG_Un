#include <QApplication>
#include "mainwindow.h"
#include <QtTest/QtTest>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <tester.h>
#include <fstream>
int main(int argc, char *argv[]) {

    freopen("testing.log", "w", stdout);
    QApplication a(argc, argv);
    QLoggingCategory::setFilterRules("qt.qpa.*=false\n"
                                     "qt.core.qmetaobject.connectslotsbyname=false");
    QTest::qExec(new Tester, argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}


