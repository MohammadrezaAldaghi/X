#ifndef USER_H
#define USER_H
#include <QString>
#include<QJsonDocument>
#include<QJsonObject>
#include<QObject>
#include<QDebug>
#include<QFile>
#include <QMessageBox>

class User
{
public:
    User();
    bool SetUserAttribute();
    void SetContry(QString country);
    void SetUsername(QString username);
    void SetPhoneNember(QString phonenumber);
    void SetBirthday(QString birthday);
    void SetPassword(QString password);
    void SetFollowings();
    void SetFollowers();
    void SetName(QString name);

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

};

#endif // USER_H
