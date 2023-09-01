#include "signupPersonalUser.h"
#include "checkaccountexist.h"
#include "personalaccount.h"
#include "personaluser.h"
#include "startwindow.h"
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
   //create folder
    {
        QDir().mkdir("Personal");
    }

}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::SetImage(QImage img)
{
    image = img;
}

void SignUp::on_RegisterButton_clicked()
{
    CheckAccountExist* Check = new CheckAccountExist();
    Check->SetUsernameCheckCheckAccountExist(ui->UsernameLineEdit->text());
    if(Check->ItExist(ui->UsernameLineEdit->text())==true)
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
        currnetUser->SetProfileImagePersonalUser(image);

        if(currnetUser->SetAttributePersonalUser())
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
        PA->SetUsernameAndNamePersonalAcoount(ui->UsernameLineEdit->text(),(ui->NameLineEdit->text()));
        PA->show();
    }
    else
    {
        QMessageBox::critical(this,"Error","A user with this username has already registered. Please enter a different username");
    }


}


void SignUp::on_ChoseProfile_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open Image", "", "Image Files (*.png *.jpg *.bmp)");

    if (!fileName.isEmpty()) {
        QImage image;
        bool loaded = image.load(fileName);
        if (loaded) {
            this->image = image;
        } else {
            qDebug()<<"wrong\n";
        }
    }
}


void SignUp::on_CancelButton_clicked()
{
    Startwindow* S = new Startwindow();
    S->show();
    this->close();
}

