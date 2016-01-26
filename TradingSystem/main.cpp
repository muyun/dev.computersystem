#include "mainwindow.h"
#include <QApplication>
#include "Logic.h"
Logic* logic;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    logic=new Logic;
    MainWindow w;
    w.show();
    return a.exec();
}
