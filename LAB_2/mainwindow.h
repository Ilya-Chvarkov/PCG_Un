#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDir>
#include <QFileInfo>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void selectFolder(); // Слот для выбора папки
    void selectFile();   // Слот для выбора файла
    void loadImages(const QString &path); // Метод для загрузки информации о файлах (папка или файл)

private:
    QTableWidget *tableWidget;
    QPushButton *buttonSelectFolder;
    QPushButton *buttonSelectFile;

    void processImage(const QFileInfo &fileInfo); // Метод для обработки информации об изображении
    void addTableRow(const QString &fileName, const QSize &size, const QString &resolution, int depth, const QString &compression);
};

#endif // MAINWINDOW_H
