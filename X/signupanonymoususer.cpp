#include "signupanonymoususer.h"
#include "checkaccountexist.h"
#include "personalaccount.h"
#include "startwindow.h"
#include "ui_signupanonymoususer.h"

SignUpAnonymousUser::SignUpAnonymousUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignUpAnonymousUser)
{
    ui->setupUi(this);
    ui->PasswordLineEdit->setStyleSheet("background-color :blue");
    ui->UsernameLineEdit->setStyleSheet("background-color :blue");
    ui->PasswordLabel->setStyleSheet("background-color :green");
    ui->UsernameLabel->setStyleSheet("background-color :green");
    ui->CancelButton->setStyleSheet("background-color :yellow");
    ui->RegisterButton->setStyleSheet("background-color :yellow");

}

SignUpAnonymousUser::~SignUpAnonymousUser()
{
    delete ui;
}

void SignUpAnonymousUser::on_RegisterButton_clicked()
{
    CheckAccountExist* Check = new CheckAccountExist();
    Check->SetUsernameCheckCheckAccountExist(ui->UsernameLineEdit->text());
    if(Check->ItExist(ui->UsernameLineEdit->text())==true)
    {
        AnonymousUser user;
        user.SetFollowersAnonymousUser();
        user.SetUsernmaeAndPasswordUser(ui->UsernameLineEdit->text(),ui->PasswordLineEdit->text());
        if(user.SetAttributeAnonymousUser())
        {
            QMessageBox::information(this,"Register message","Registration was successful");
            this->hide();
        }
        else
        {
            QMessageBox::critical(this,"Register message","Registration failed. Please try again");
            this->hide();
        }
        close();
        PersonalAccount *PA = new PersonalAccount();
        PA->SetUsernameAndNamePersonalAcoount(ui->UsernameLineEdit->text(),"Anonymou User");
        PA->show();
    }
    else
    {
        QMessageBox::critical(this,"Error","A user with this username has already registered. Please enter a different username");
    }
}


void SignUpAnonymousUser::on_CancelButton_clicked()
{
    Startwindow* S = new Startwindow();
    S->show();
    this->close();

}

