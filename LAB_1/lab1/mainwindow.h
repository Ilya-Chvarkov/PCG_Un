#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSlider>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include <QGroupBox>
#include <QColorDialog>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT
 friend class Tester;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setColor(const QColor& newColor);

private slots:

    void updateInf();

    void updateRGB();
    void updateRGB2();
    void updateCMYK();
    void updateCMYK2();
    void updateHLS();
    void updateHLS2();

   // void updateFromSliders();
    void pickColor();

private:

    QSlider *rSlider, *gSlider, *bSlider;
    QSlider *cSlider, *mSlider, *ySlider, *kSlider;
    QSlider *hSlider, *lSlider, *sSlider;
    QLineEdit *rEdit, *gEdit, *bEdit;

    QLineEdit *cEdit, *mEdit, *yEdit, *kEdit;

    QLineEdit *hEdit, *lEdit, *sEdit;


    QLabel *colorDisplay;

    QColor rgbToColor();
    QColor cmykToColor();
    QColor hlsToColor();
  //  void colorToRGB(const QColor &color);
  //  void colorToCMYK(const QColor &color);
  //  void colorToHLS(const QColor &color);

    void updateColorDisplay(const QColor &color);

    bool updatingRGB = false;
    bool updatingCMYK = false;
    bool updatingHSL = false;
    bool updatingRGB2 = false;
    bool updatingCMYK2 = false;
    bool updatingHSL2 = false;
    bool uppp = false;

    QColor Tek;

    void createUI();
    void updateAllModelsfromRGB();
  //  void updateAllModelsfromCMYK();
  //  void updateAllModelsfromHLS();

signals:
    void colorChanged(const QColor& newColor);

};

#endif // MAINWINDOW_H
