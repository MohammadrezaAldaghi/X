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

//    QIcon loginIcon = QIcon("C:/Users/ARTA/Desktop/Login.png");
//    QIcon signupIcon = QIcon("image.qrc/Sign up.png");

    QSize loginiconSize(ui->LoginButton->size());
    QSize signupiconSize(ui->SignupButton->size());
    ui->LoginButton->setStyleSheet("background-color : lightgreen");
    ui->SignupButton->setStyleSheet("background-color : lightblue");
    ui->LoginButton->setIconSize(loginiconSize);
//    ui->LoginButton->setIcon(loginIcon);
    ui->SignupButton->setIconSize(signupiconSize);
//    ui->SignupButton->setIcon(signupIcon);


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





void MainWindow::on_actionHelp_3_triggered()
{
    QString  HelpString = "SETTING:بخش تنظیمات نرم افزار \n"
                          "Logout  :خروج از حساب کاربری\n"
                          "adjust profile:تنظیمات پروفایل\n"
            "adjust biography:تنظیمات بیوگرافی\n"
            "change username:تغییر در نام کاربری\n"
            "change phone number:تغییر شماره موبایل\n"
            "show my profile:نمایش کامل حساب کاربری\n"
            "change name:تغییر نام\n"
            "change birthday:تغییر تاریخ تولد\n"
            "change country:تغییر کشور\n"
            "show all hashtag:نمایش تمام هشتک ها\n"
            "change password:تغییر پسورد\n"
            "delete tweet:پاک کردن توییت\n"
            "like:لایک کردن\n"
            "mention send:نظر دادن\n"
            "follow:دنبال کردن\n"
            "show mention:نشان دادن نظر ها\n"
            "tweet:توییت گذاشتن\n"
            "qt:فریمورک\n"
            "c++:زبان\n";

    QMessageBox::information(this,"Help window",HelpString);
}

