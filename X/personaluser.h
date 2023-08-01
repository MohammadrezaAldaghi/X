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
    void SetProfileImagePersonalUser(QImage img);
    void SetFollowingsPersonalUser();
    void SetBiographyPersonalUser(QString bio);
    void SetFollowersPersonalUser();


private:
    QString PhoneNember;
    QString Country;
    QString Birthday;
    int Followings;
    int Followers;
    QString ColorHeader;
    QString Name;
    QImage ProfileImage;
    QString Biography;

};

#endif // PERSONALUSER_H
