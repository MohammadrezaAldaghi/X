#include "anonymoususer.h"

AnonymousUser::AnonymousUser()
{
    QDir().mkdir("Anonymous");
}

void AnonymousUser::SetFollowersAnonymousUser()
{
    Followers = 0;
}

bool AnonymousUser::SetAttributeAnonymousUser()
{
    QJsonObject jsonObj;
    jsonObj["Username"] = Username;
    jsonObj["Password"] = Password;
    jsonObj["Name"] = "User Anonymous";
    jsonObj["TweetCounter"] = "0";

    QJsonDocument jsonDoc(jsonObj);

    QByteArray jsonData = jsonDoc.toJson();

    QFile file("Anonymous/" + Username + ".json");
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
