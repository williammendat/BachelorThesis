#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_processImage = new ProcessImages();
}

MainWindow::~MainWindow()
{
    delete ui;

    if(m_processImage != nullptr)
        delete m_processImage;
}

void MainWindow::on_pbUpdate_clicked()
{
    _setLabels();
}

void MainWindow::_setLabels(){
    m_processImage->vReadProcessImage();
    _update();
}

void MainWindow::_update(){
    double dValue = static_cast<double>(m_processImage->getAirPressur());
    QString value = QString::number(dValue);
    ui->lblLuftdruck->setText(value);

    dValue = static_cast<double>(m_processImage->getTemperature());
    value = QString::number(dValue);
    ui->lblTemperatur->setText(value);

    dValue = static_cast<double>(m_processImage->getHumidity());
    value = QString::number(dValue);
    ui->lblLuftfreutigkeit->setText(value);

    dValue = static_cast<double>(m_processImage->getMagnetometerX());
    value = QString::number(dValue);
    ui->lblKompassX->setText(value);

    dValue = static_cast<double>(m_processImage->getMagnetometerY());
    value = QString::number(dValue);
    ui->lblKompassY->setText(value);

    dValue = static_cast<double>(m_processImage->getMagnetometerZ());
    value = QString::number(dValue);
    ui->lblKompassZ->setText(value);
}
