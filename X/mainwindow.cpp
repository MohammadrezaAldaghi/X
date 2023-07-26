#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_checkButton_clicked()
{
    QImage ProfileImage;
    QImage profileImageFromFile;
            if (profileImageFromFile.load("Organisation/Moahmmadreza.json")) {
                ProfileImage = profileImageFromFile;
                qDebug()<<"yes";
            }
            else {
              qDebug()<<"No";

            }
}

