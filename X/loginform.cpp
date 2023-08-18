#include "loginform.h"
#include "personalaccount.h"
#include "startwindow.h"
#include "ui_loginform.h"
#include "mainwindow.h"


LoginForm::LoginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);
    ui->CancelButton->setStyleSheet("background-color : #a9acb1");
    ui->LoginButton->setStyleSheet("background-color : #a9acb1");
    ui->PasswordLabel->setStyleSheet("color : #f89b6c");
    ui->UsernameLabel->setStyleSheet("color : #f89b6c");
    ui->PasswordLineEdit->setStyleSheet("background-color : #8fdfc7");
    ui->UsernameLineEdit->setStyleSheet("background-color : #8fdfc7");
    setStyleSheet("background-color : yellow");
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::on_LoginButton_clicked()
{
    //read from Organisation User
    {
        QFile jsonFile("Organisation/"+ui->UsernameLineEdit->text()+".json");
        if (!jsonFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            // Error handling
        }

        QByteArray jsonData = jsonFile.readAll();
        jsonFile.close();

        QJsonParseError jsonError;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &jsonError);

        if (jsonError.error != QJsonParseError::NoError) {
            // Error handling
        }

        if (!jsonDoc.isObject()) {
            // Error handling
        }

        QJsonObject jsonObj = jsonDoc.object();
        QString password = jsonObj["Password"].toString();
        QString phoneNumber = jsonObj["PhoneNumber"].toString();
        QString username = jsonObj["Username"].toString();
        qDebug()<<"username11 ="<< username<<" , passwordl11 = "<<password<<"\n";
//        qDebug()<<"ui->UsernameLineEdit->text() = " <<ui->UsernameLineEdit->text()<<" , " << "ui->PasswordLineEdit->text() = "<<ui->PasswordLineEdit->text();
        if(ui->PasswordLineEdit->text()==password&&ui->UsernameLineEdit->text()==username)
        {
            PersonalAccount* P = new PersonalAccount();
            P->SetUsernameAndNamePersonalAcoount(username,"name");
            this->hide();
            P->show();
            qDebug()<<"Yes";
        }

    }
    //read Personal User
    {
        QFile jsonFile("Personal/"+ui->UsernameLineEdit->text()+".json");
        if (!jsonFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            // Error handling
        }

        QByteArray jsonData = jsonFile.readAll();
        jsonFile.close();

        QJsonParseError jsonError;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &jsonError);

        if (jsonError.error != QJsonParseError::NoError) {
            // Error handling
        }

        if (!jsonDoc.isObject()) {
            // Error handling
        }

        QJsonObject jsonObj = jsonDoc.object();
        QString password = jsonObj["Password"].toString();
        QString phoneNumber = jsonObj["PhoneNumber"].toString();
        QString username = jsonObj["Username"].toString();
        QString name = jsonObj["Name"].toString();
        qDebug()<<"username ="<< username<<" , passwordl = "<<password<<"\n";
        if(ui->PasswordLineEdit->text()==password&&ui->UsernameLineEdit->text()==username)
        {
                PersonalAccount* P = new PersonalAccount();
                P->SetUsernameAndNamePersonalAcoount(username,name);
                this->hide();
                P->show();
                qDebug()<<"Yes";


        }


    }
    //read Anonymous user
    {
        QFile jsonFile("Anonymous/"+ui->UsernameLineEdit->text()+".json");
        if (!jsonFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            // Error handling
        }

        QByteArray jsonData = jsonFile.readAll();
        jsonFile.close();

        QJsonParseError jsonError;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &jsonError);

        if (jsonError.error != QJsonParseError::NoError) {
            // Error handling
        }

        if (!jsonDoc.isObject()) {
            // Error handling
        }

        QJsonObject jsonObj = jsonDoc.object();
        QString password = jsonObj["Password"].toString();
        QString phoneNumber = jsonObj["PhoneNumber"].toString();
        QString username = jsonObj["Username"].toString();
        if(ui->PasswordLineEdit->text()==password&&ui->UsernameLineEdit->text()==username)
        {

            PersonalAccount* P = new PersonalAccount();
            P->SetUsernameAndNamePersonalAcoount(username,"User Anonymous");
            this->hide();
            P->show();
            qDebug()<<"Yes";
        }


    }

}


void LoginForm::on_CancelButton_clicked()
{
    MainWindow* M = new MainWindow();
    this->close();
    M->show();
}

