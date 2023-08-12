#include "mainwindow.h"
#include "qjsonarray.h"
#include "ui_mainwindow.h"
#include "startwindow.h"
#include "loginform.h"
#include <QIcon>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->LoginButton->setStyleSheet("QPushButton { border-radius: 50%; }");
    ui->SignupButton->setStyleSheet("QPushButton {border-radius: 50%}");

    QIcon loginIcon = QIcon("C:/Users/ARTA/Desktop/Login.png");
    QIcon signupIcon = QIcon("C:/Users/ARTA/Desktop/Sign up.png");

    QSize loginiconSize(ui->LoginButton->size());
    QSize signupiconSize(ui->SignupButton->size());

    ui->LoginButton->setIconSize(loginiconSize);
    ui->LoginButton->setIcon(loginIcon);
    ui->SignupButton->setIconSize(signupiconSize);
    ui->SignupButton->setIcon(signupIcon);


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_SignupButton_clicked()
{
    this->close();
    Startwindow* S = new Startwindow();
    S->show();
}


void MainWindow::on_LoginButton_clicked()
{
    this->close();
    LoginForm* L = new LoginForm();
    L->show();
}

