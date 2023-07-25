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
    bool SetUserAttribute();
    void SetContry(QString country);
    void SetUsername(QString username);
    void SetPhoneNember(QString phonenumber);
    void SetBirthday(QString birthday);
    void SetPassword(QString password);
    void SetFollowings();
    void SetFollowers();
    void SetProfileImage(QImage image);
    void SetName(QString name);
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
