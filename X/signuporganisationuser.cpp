#include "signuporganisationuser.h"
#include "ui_signuporganisationuser.h"

SignUpOrganisationUser::SignUpOrganisationUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignUpOrganisationUser)
{
    ui->setupUi(this);
    setStyleSheet("background-color: #B0C4DE");
    //setStyleSheet signupPersonalUser line Edit
    {
        ui->UsernameLineEdit->setStyleSheet("background-color : #FFFF66");
        ui->PasswordLineEdit->setStyleSheet("background-color : #FFFF66");
        ui->PhoneNumberLineEdit->setStyleSheet("background-color : #FFFF66");
    }
    //setStyleSheet signupPersonalUser label
    {
        ui->UsernameLabel->setStyleSheet("background-color: #98FB98");
        ui->PasswordLabel->setStyleSheet("background-color: #98FB98");
        ui->PhoneNumberLabel->setStyleSheet("background-color: #98FB98");
    }
    //setStyleSheet signupPersonalUser Button
    {
        ui->ChoseImageButton->setStyleSheet("background-color: #8A2BE2");
        ui->CancelButton->setStyleSheet("background-color: #8A2BE2");
        ui->RegisterButton->setStyleSheet("background-color: #8A2BE2");
    }

}

SignUpOrganisationUser::~SignUpOrganisationUser()
{
    delete ui;
}
