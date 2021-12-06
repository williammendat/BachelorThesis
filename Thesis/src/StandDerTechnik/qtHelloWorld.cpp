#include "mainwindow.h"

int main(int argc, char *argv[])
{
    // Set the Application
    QApplication app(argc, argv);
    QWidget window;
    // Set fixed Width of the Window
    window.setFixedWidth(300);

    // Set the Title of the Window
    window.setWindowTitle("Meine erste Qt App");

    // Create a Label and align it to Center
    QLabel *lblHello = new QLabel("Hello World!");
    lblHello->setAlignment(Qt::AlignCenter);

    // Create a Button and connect it to close the Window
    QPushButton *btnExit = new QPushButton("&Exit");
    // Connect button with the App
    QObject::connect(btnExit, SIGNAL(clicked()), &app, SLOT(quit()));

    // Sowohl das Label als auch die Schaltfläche vertikal ausrichten
    QVBoxLayout *layout = new QVBoxLayout;

    // Add the Widgets
    layout->addWidget(lblHello);
    layout->addWidget(btnExit);
    window.setLayout(layout);

    window.show();
    return app.exec();
}
