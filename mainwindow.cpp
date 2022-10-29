#include "mainwindow.h"
#include "ui_mainwindow.h"

#define MI_MACRO

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    SystemInfo::instancia().init();

    connect(&timer,SIGNAL(timeout()),this,SLOT(updateLabelCpu()));
    timer.start(500);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateLabelCpu()
{
    ui->cpu_data->setText(QString::number(SystemInfo::instancia().cpuLoad()));
}

