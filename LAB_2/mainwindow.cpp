#include "mainwindow.h"
#include <QFileDialog>
#include <QImageReader>
#include <QHeaderView>
#include <QFileInfo>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    tableWidget = new QTableWidget(this);
    tableWidget->setColumnCount(5);
    tableWidget->setHorizontalHeaderLabels(QStringList() << "File Name" << "Size (px)" << "Resolution (dpi)" << "Color Depth" << "Compression");
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    buttonSelectFolder = new QPushButton("Select Folder", this);
    connect(buttonSelectFolder, &QPushButton::clicked, this, &MainWindow::selectFolder);

    buttonSelectFile = new QPushButton("Select File", this);
    connect(buttonSelectFile, &QPushButton::clicked, this, &MainWindow::selectFile);


    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(buttonSelectFolder);
    layout->addWidget(buttonSelectFile);
    layout->addWidget(tableWidget);

    QWidget *container = new QWidget();
    container->setLayout(layout);
    setCentralWidget(container);
}

MainWindow::~MainWindow() {}

void MainWindow::selectFolder()
{
    QString folderPath = QFileDialog::getExistingDirectory(this, "Select Folder");
    if (!folderPath.isEmpty())
    {
        loadImages(folderPath);
    }
}

void MainWindow::selectFile()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Select Image File", QString(),
                                                    "Images (*.jpg *.jpeg *.png *.gif *.bmp *.tif *.pcx)");
    if (!filePath.isEmpty())
    {
        loadImages(filePath);
    }
}

void MainWindow::loadImages(const QString &path)
{
    QFileInfo pathInfo(path);

    if (pathInfo.isDir())
    {
        QDir dir(path);
        QStringList filters;
        filters << "*.jpg" << "*.jpeg" << "*.png" << "*.gif" << "*.bmp" << "*.tif" << "*.pcx";
        dir.setNameFilters(filters);
        QFileInfoList fileList = dir.entryInfoList();

        for (const QFileInfo &fileInfo : fileList)
        {
            processImage(fileInfo);
        }
    }
    else if (pathInfo.isFile())
    {
        processImage(pathInfo);
    }
}

void MainWindow::processImage(const QFileInfo &fileInfo)
{
    QImageReader reader(fileInfo.filePath());
    QImage image = reader.read();
    if (!image.isNull())
    {
        QSize size = image.size();
        int resolutionX = image.physicalDpiX();
        int resolutionY = image.physicalDpiY();
        QString resolution = (resolutionX > 0 && resolutionY > 0) ? QString("%1x%2").arg(resolutionX).arg(resolutionY) : "Unknown";
        int depth = image.depth();

        qint64 fileSizeOnDisk = fileInfo.size();
        size_t imageSizeInMemory = image.sizeInBytes();
        double compressionPercentage = (static_cast<double>(imageSizeInMemory) / fileSizeOnDisk) ;
        QString compression = QString::number(compressionPercentage, 'f', 2);

        addTableRow(fileInfo.fileName(), size, resolution, depth, compression);
    }
}

void MainWindow::addTableRow(const QString &fileName, const QSize &size, const QString &resolution, int depth, const QString &compression)
{
    int row = tableWidget->rowCount();
    tableWidget->insertRow(row);

    tableWidget->setItem(row, 0, new QTableWidgetItem(fileName));
    tableWidget->setItem(row, 1, new QTableWidgetItem(QString("%1x%2").arg(size.width()).arg(size.height())));
    tableWidget->setItem(row, 2, new QTableWidgetItem(resolution));
    tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(depth)));
    tableWidget->setItem(row, 4, new QTableWidgetItem(compression));
}
