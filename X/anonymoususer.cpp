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
    QString directoryPath = "Anonymous";
        QString fileName = "." + Username + ".json";
        QString filePath = directoryPath + "/" + fileName;

        // تنظیم اطلاعات کاربر در JSON
        QJsonObject jsonObj;
        jsonObj["Username"] = Username;
        jsonObj["Password"] = Password;
        jsonObj["Name"] = "User Anonymous";
        jsonObj["TweetCounter"] = "0";

        // تبدیل JSON به بایت‌ها
        QJsonDocument jsonDoc(jsonObj);
        QByteArray jsonData = jsonDoc.toJson();

        // ایجاد پوشه اگر وجود ندارد
        QDir directory;
        if (!directory.exists(directoryPath))
        {
            directory.mkpath(directoryPath);
        }

        // ذخیره بایت‌ها در فایل
        QFile file(filePath);
        if (file.open(QIODevice::Append))
        {
            file.write(jsonData);
            file.close();

            // تنظیم مجوزهای فایل برای مخفی شدن
            file.setPermissions(QFile::ReadOwner | QFile::WriteOwner );

            return true;
        }
        else
        {
            file.close();
            return false;
        }

}
