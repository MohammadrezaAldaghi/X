#include "personaluser.h"

PersonalUser::PersonalUser()
{

}

void PersonalUser::SetContryPersonalUser(QString country)
{
    Country = country;
}

void PersonalUser::SetBirthdayPersonalUser(QString birthday)
{
    Birthday = birthday;
}

void PersonalUser::SetNamePersonalUser(QString name)
{
    Name = name;
}

void PersonalUser::SetColorHeaderPersonalUser()
{

}

void PersonalUser::SetPhonNemberPersonalUser(QString number)
{
    PhoneNember = number;
}
bool PersonalUser::SetAttributePersonalUser()
{
    QDir().mkdir(Username);
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

    QString fileName = Username + "/" + Username + ".json";
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
