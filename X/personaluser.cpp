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
    QJsonObject jsonObj;
    jsonObj["Username"] = Username;
    jsonObj["Password"] = Password;
    jsonObj["PhoneNumber"] = PhoneNember;
    jsonObj["Country"] = Country;
    jsonObj["Birthday"] = Birthday;
    jsonObj["Followers"] = QString::fromStdString(std::to_string(Followers));
    jsonObj["Followings"] = QString::fromStdString(std::to_string(Followings));
    jsonObj["Name"] = Name;
    jsonObj["Biography"] = Biography;
    jsonObj["TweetCounter"] = "0";
    ProfileImage.save("Personal/" + Username + ".jpg");
    QJsonDocument jsonDoc(jsonObj);

    QByteArray jsonData = jsonDoc.toJson();

    QString fileName = "Personal/" + Username + ".json";
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

void PersonalUser::SetProfileImagePersonalUser(QImage img)
{
    ProfileImage = img;
}

void PersonalUser::SetFollowingsPersonalUser()
{
    Followings = 0;
}

void PersonalUser::SetBiographyPersonalUser(QString bio)
{
    Biography = bio;
}

void PersonalUser::SetFollowersPersonalUser()
{
    Followers = 0;
}
