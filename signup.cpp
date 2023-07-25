#include "signup.h"
#include "ui_signup.h"


SignUp::SignUp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_RegisterButton_clicked()
{
    User* currnetUser = new User();
    currnetUser->SetUsername(ui->UsernameLineEdit->text());
    currnetUser->SetBirthday(ui->BirthdayLineEdit->text());
    currnetUser->SetPassword(ui->PasswordLineEdit->text());
    currnetUser->SetPhoneNember(ui->PhoneNemberLineEdit->text());
    currnetUser->SetContry(ui->CountryLineEdit->text());
    currnetUser->SetName(ui->NameLineEdit->text());
    currnetUser->SetFollowers();
    currnetUser->SetFollowings();

    if(currnetUser->SetUserAttribute())
        QMessageBox::information(this,"Registration successful","Registration was successful");
    else
        QMessageBox::critical(this,"Registration failed","Registration failed. Please try again");



}


void SignUp::on_ChoseProfile_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open Image", "", "Image Files (*.png *.jpg *.bmp)");

    if (!fileName.isEmpty()) {
        // load the image into your application
    }
}

