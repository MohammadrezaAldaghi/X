#ifndef USER_H
#define USER_H
#include <QString>
#include<QJsonDocument>
#include<QJsonObject>
#include<QObject>
#include<QDebug>
#include<QFile>
#include <QMessageBox>
#include <QDir>

class User
{
public:
    User();
    void SetUsername(QString username);
    void SetPassword(QString password);
    void SetUsernmaeAndPasswordUser(QString username,QString password);

protected:
    QString Username;
    QString Password;
    QString PhoneNember;
    QString Country;
    QString Birthday;
    int Followings;
    int Followers;
    QString ColorHeader;
    QString Name;
    QImage ProfileImage;

};

#endif // USER_H
