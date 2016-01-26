#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Logic.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(logic->getServer(),SIGNAL(toDisplay(QString)),ui->textBrowser,SLOT(append(QString)));
    connect(logic,SIGNAL(toDisplay(QString)),ui->textBrowser,SLOT(append(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
