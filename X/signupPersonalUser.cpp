#include "signupPersonalUser.h"
#include "personaluser.h"
#include "ui_signupPersonalUser.h"

SignUp::SignUp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
   //setStyleSheet signupPersonalUser line Edit
   {
        setStyleSheet("background-color: #FFC0CB");//رنگ گلبهی
        ui->BirthdayLineEdit->setStyleSheet("background-color : #87CEEB");
        ui->CountryLineEdit->setStyleSheet("background-color : #87CEEB");
        ui->NameLineEdit->setStyleSheet("background-color : #87CEEB");
        ui->PasswordLineEdit->setStyleSheet("background-color : #87CEEB");
        ui->UsernameLineEdit->setStyleSheet("background-color : #87CEEB");
        ui->PhoneNumberLineEdit->setStyleSheet("background-color : #87CEEB");
    }
   //setStyleSheet signupPersonalUser label
    {
      ui->UsernameLabel->setStyleSheet("background-color : #FFFF66");
      ui->Birthdaylabel->setStyleSheet("background-color : #FFFF66");
      ui->Countrylabel->setStyleSheet("background-color : #FFFF66");
      ui->NameLabel->setStyleSheet("background-color : #FFFF66");
      ui->Passwordlabel->setStyleSheet("background-color : #FFFF66");
      ui->PhonNumbeLabel->setStyleSheet("background-color : #FFFF66");
      ui->ChoseProfile->setStyleSheet("background-color: #D2B48C");
    }
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_RegisterButton_clicked()
{
    PersonalUser* currnetUser = new PersonalUser();
    currnetUser->SetUsername(ui->UsernameLineEdit->text());
    currnetUser->SetBirthdayPersonalUser(ui->BirthdayLineEdit->text());
    currnetUser->SetPassword(ui->PasswordLineEdit->text());
    currnetUser->SetPhonNemberPersonalUser(ui->PhoneNumberLineEdit->text());
    currnetUser->SetContryPersonalUser(ui->CountryLineEdit->text());
    currnetUser->SetNamePersonalUser(ui->NameLineEdit->text());
    currnetUser->SetFollowersPersonalUser();
    currnetUser->SetFollowingsPersonalUser();

    if(currnetUser->SetAttributePersonalUser())
        QMessageBox::information(this,"sdfdsdfdfsdfsd","Registration was successful");
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

