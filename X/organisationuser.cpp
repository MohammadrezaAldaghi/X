#include "organisationuser.h"

OrganisationUser::OrganisationUser()
{
    QDir().mkdir("Organisation");
}

void OrganisationUser::SetPhoneNumberOrganisationUser(QString number)
{
    PhoneNaumber = number;
}

void OrganisationUser::SetFollowingsOrganisationUser()
{
    Followings = 0;
}

void OrganisationUser::SetFollowersOrganisationUser()
{
    Followers = 0;
}

void OrganisationUser::SetProfileImageOrganisationUser(QImage img)
{
    ProfileImage = img;
}

bool OrganisationUser::SetAttributeOrganisationUser()
{
    QJsonObject jsonObj;
    jsonObj["Username"] = Username;
    jsonObj["Password"] = Password;
    jsonObj["PhoneNumber"] = PhoneNaumber;

    QJsonDocument jsonDoc(jsonObj);

    QByteArray jsonData = jsonDoc.toJson();

    QFile file("Organisation/" + Username + ".json");
    if(file.open(QIODevice::Append))
    {
        file.write(jsonData);
        file.close();
        return true;
    }
    else
    {
        file.close();
        return false;
    }

}
