#ifndef PERSONALUSER_H
#define PERSONALUSER_H
#include <QString>
#include<QJsonDocument>
#include<QJsonObject>
#include<QObject>
#include<QDebug>
#include<QFile>
#include <QMessageBox>
#include <QDir>
#include"user.h"


class PersonalUser : public User
{
public:
    PersonalUser();
    void SetContryPersonalUser(QString country);
    void SetPhonNemberPersonalUser(QString number);
    void SetNamePersonalUser(QString Name);
    void SetColorHeaderPersonalUser();
    void SetBirthdayPersonalUser(QString birthday);
    bool SetAttributePersonalUser();


private:
    QString PhoneNember;
    QString Country;
    QString Birthday;
    int Followings;
    int Followers;
    QString ColorHeader;
    QString Name;
    QImage ProfileImage;

};

#endif // PERSONALUSER_H
