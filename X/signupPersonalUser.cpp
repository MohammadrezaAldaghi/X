#include "signupPersonalUser.h"
#include "ui_signup.h"
#include "personaluser.h"

signupPersonalUser::signupPersonalUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signupPersonalUser)
{
    ui->setupUi(this);
}

signupPersonalUser::~signupPersonalUser()
{
    delete ui;
}

void signupPersonalUser::on_RegisterButton_clicked()
{
    PersonalUser* currnetUser = new PersonalUser();
    currnetUser->SetUsername(ui->UsernameLineEdit->text());
    currnetUser->SetBirthdayPersonalUser(ui->BirthdayLineEdit->text());
    currnetUser->SetPassword(ui->PasswordLineEdit->text());
    currnetUser->SetPhonNemberPersonalUser(ui->PhoneNemberLineEdit->text());
    currnetUser->SetContryPersonalUser(ui->CountryLineEdit->text());
    currnetUser->SetNamePersonalUser(ui->NameLineEdit->text());
    currnetUser->SetFollowersPersonalUser();
    currnetUser->SetFollowingsPersonalUser();

    if(currnetUser->SetAttributePersonalUser())
        QMessageBox::information(this,"sdfdsdfdfsdfsd","Registration was successful");
    else
        QMessageBox::critical(this,"Registration failed","Registration failed. Please try again");



}


void signupPersonalUser::on_ChoseProfile_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open Image", "", "Image Files (*.png *.jpg *.bmp)");

    if (!fileName.isEmpty()) {
        // load the image into your application
    }
}

