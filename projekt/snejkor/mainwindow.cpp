#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "plansza.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Plansza *plansza = new Plansza(this);
    setCentralWidget(plansza);
}

MainWindow::~MainWindow()
{
    delete ui;
}
