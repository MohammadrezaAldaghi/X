#include "user.h"

User::User()
{

}

bool User::SetUserAttribute()
{
    qDebug()<<"yes\n";
    QJsonObject jsonObj;
    jsonObj["Username"] = Username;
    jsonObj["Password"] = Password;
    jsonObj["PhoneNember"] = PhoneNember;
    jsonObj["Country"] = Country;
    jsonObj["Birthday"] = Birthday;
    jsonObj["Followers"] = Followers;
    jsonObj["Followings"] = Followings;
    jsonObj["Name"] = Name;

    QJsonDocument jsonDoc(jsonObj);

    QByteArray jsonData = jsonDoc.toJson();

    QString fileName = Username + ".json";
    QFile file(fileName);

    try{
        if(file.open(QIODevice::Append))
        {
            file.write(jsonData);
            file.close();
            return true;
        }
        else
        {
            file.close();
            throw std::invalid_argument("file is not opened successfully");
        }
    }
    catch(std::exception& e)
    {
        return false;
    }

}

void User::SetContry(QString country)
{
    Country = country;
}

void User::SetUsername(QString username)
{
    Username = username;
}

void User::SetPhoneNember(QString phonenumber)
{
    PhoneNember = phonenumber;
}

void User::SetBirthday(QString birthday)
{
    Birthday = birthday;
}

void User::SetPassword(QString password)
{
    Password = password;
}

void User::SetFollowings()
{
    Followings = 0;
}

void User::SetFollowers()
{
    Followers = 0;
}

void User::SetName(QString name)
{
    Name = name;
}

