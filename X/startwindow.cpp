#include "startwindow.h"
#include "personalaccount.h"
#include "ui_startwindow.h"
#include "mainwindow.h"


Startwindow::Startwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Startwindow)
{
    ui->setupUi(this);
    setStyleSheet("background-color: yellow");
    ui->AnonymousButton->setStyleSheet("color : red");
    ui->AnonymousButton->setStyleSheet("background-color: blue");
    ui->AnonymousButton->setToolTip("<span style='font-size: 14px;'> This account will be created for organizations, departments and companies</span>");
    ui->OrganisationButton->setStyleSheet("color : blue");
    ui->OrganisationButton->setStyleSheet("background-color: green");
    ui->OrganisationButton->setToolTip("<span style='font-size: 14px;'> These types of accounts will be made for ordinary people</span>");
    ui->PersonalButton->setStyleSheet("color : green");
    ui->PersonalButton->setStyleSheet("background-color: red");
    ui->PersonalButton->setToolTip("<span style='font-size: 14px;'> you can track personal accounts.</span>");
    ui->BackButton->setStyleSheet("background-color: purple");
}

Startwindow::~Startwindow()
{
    delete ui;
}

void Startwindow::on_OrganisationButton_clicked()
{
    SignUpOrganisationUser* currentUser = new SignUpOrganisationUser();
    currentUser->show();
}


void Startwindow::on_PersonalButton_clicked()
{
    SignUp* currentUser = new SignUp();
    currentUser->show();


}


void Startwindow::on_AnonymousButton_clicked()
{
    SignUpAnonymousUser* currentUser = new SignUpAnonymousUser();
    currentUser->show();
}


void Startwindow::on_BackButton_clicked()
{
    MainWindow* M = new MainWindow();
    this->close();
    M->show();
}

