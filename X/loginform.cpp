#include "loginform.h"
#include "ui_loginform.h"

LoginForm::LoginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);
    ui->CancelButton->setStyleSheet("background-color : blue");
    ui->LoginButton->setStyleSheet("background-color : blue");
    ui->PasswordLabel->setStyleSheet("background-color : red");
    ui->UsernameLabel->setStyleSheet("background-color : red");
    ui->PasswordLineEdit->setStyleSheet("background-color : green");
    ui->UsernameLineEdit->setStyleSheet("background-color : green");
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
        qDebug()<<"username ="<< username<<" , passwordl = "<<password<<"\n";
        if(ui->PasswordLineEdit->text()==password&&ui->UsernameLineEdit->text()==username)
        {


        }
        else
        {
            QMessageBox::critical(this,"Error","User not found");
            this->hide();
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
        qDebug()<<"username ="<< username<<" , passwordl = "<<password<<"\n";
        if(ui->PasswordLineEdit->text()==password&&ui->UsernameLineEdit->text()==username)
        {


        }
        else
        {
            QMessageBox::critical(this,"Error","User not found");
            this->hide();
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


        }
        else
        {
            QMessageBox::critical(this,"Error","User not found");
            this->hide();
        }

    }

}
