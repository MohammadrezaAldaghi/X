#ifndef ORGANISATIONUSER_H
#define ORGANISATIONUSER_H
#include "user.h"
#include <QString>
#include<QJsonDocument>
#include<QJsonObject>
#include<QObject>
#include<QDebug>
#include<QFile>
#include <QMessageBox>
#include <QDir>


class OrganisationUser : public User
{
public:
    OrganisationUser();
    void SetPhoneNumberOrganisationUser(QString number);
    void SetFollowingsOrganisationUser();
    void SetFollowersOrganisationUser();
    void SetProfileImageOrganisationUser(QImage img);
    void SetHeadOfTheOrganizationOrganisationUser(QString headOfTheOrganization);
    bool SetAttributeOrganisationUser();


private:
    int Followings;
    int Followers;
    QString PhoneNaumber;
    QString HeadOfTheOrganization;
    QImage ProfileImage;

};

#endif // ORGANISATIONUSER_H
