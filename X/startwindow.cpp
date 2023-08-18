#include "startwindow.h"
#include "personalaccount.h"
#include "ui_startwindow.h"
#include "mainwindow.h"


Startwindow::Startwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Startwindow)
{
    ui->setupUi(this);
    setStyleSheet("background-color: #a9acb1");
    ui->AnonymousButton->setStyleSheet("color : #9eb3ff");
    ui->AnonymousButton->setStyleSheet("background-color: #8fdfc7");
    ui->AnonymousButton->setToolTip("<span style='font-size: 14px;'> This account will be created for organizations, departments and companies</span>");
    ui->OrganisationButton->setStyleSheet("color : #8fdfc7");
    ui->OrganisationButton->setStyleSheet("background-color: #8fdfc7");
    ui->OrganisationButton->setToolTip("<span style='font-size: 14px;'> These types of accounts will be made for ordinary people</span>");
    ui->PersonalButton->setStyleSheet("color : #8fdfc7");
    ui->PersonalButton->setStyleSheet("background-color: #8fdfc7");
    ui->PersonalButton->setToolTip("<span style='font-size: 14px;'> you can track personal accounts.</span>");
    ui->BackButton->setStyleSheet("background-color: #777d82");
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

