#include "signuporganisationuser.h"
#include "checkaccountexist.h"
#include "personalaccount.h"
#include "startwindow.h"
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
    //create folder
     {
         QDir().mkdir("Organisation");
     }

}

SignUpOrganisationUser::~SignUpOrganisationUser()
{
    delete ui;
}

void SignUpOrganisationUser::on_ChoseImageButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open Image", "", "Image Files (*.png *.jpg *.bmp)");
    if (!fileName.isEmpty()) {
        // load the image into your application
        QImage img(fileName);
        image = img;
    }
}


void SignUpOrganisationUser::on_RegisterButton_clicked()
{
    CheckAccountExist* Check = new CheckAccountExist();
    Check->SetUsernameCheckCheckAccountExist(ui->UsernameLineEdit->text());
    if(Check->ItExist(ui->UsernameLineEdit->text())==true)
    {
        OrganisationUser currentUser;
        currentUser.SetUsernmaeAndPasswordUser(ui->UsernameLineEdit->text(),ui->PasswordLineEdit->text());
        currentUser.SetFollowersOrganisationUser();
        currentUser.SetFollowingsOrganisationUser();
        currentUser.SetPhoneNumberOrganisationUser(ui->PhoneNumberLineEdit->text());
        currentUser.SetProfileImageOrganisationUser(image);
        currentUser.SetHeadOfTheOrganizationOrganisationUser(ui->HeadOfTheOrganizationLineEdit->text());
        if(currentUser.SetAttributeOrganisationUser())
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
        PA->SetUsernameAndNamePersonalAcoount(ui->UsernameLineEdit->text(),ui->HeadOfTheOrganizationLineEdit->text());
        PA->show();
    }
    else
    {
        QMessageBox::critical(this,"Error","A user with this username has already registered. Please enter a different username");
    }


}


void SignUpOrganisationUser::on_CancelButton_clicked()
{
    Startwindow* S = new Startwindow();
    S->show();
    this->close();
}

