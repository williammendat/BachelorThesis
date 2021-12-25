#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "processimages.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pbUpdate_clicked();

private:
    Ui::MainWindow *ui;
    ProcessImages *m_processImage = nullptr;

private:
    void _setLabels();
    void _update();
};

#endif // MAINWINDOW_H
