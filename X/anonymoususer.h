#ifndef ANONYMOUSUSER_H
#define ANONYMOUSUSER_H
#include <QString>
#include<QJsonDocument>
#include<QJsonObject>
#include<QObject>
#include<QDebug>
#include<QFile>
#include <QMessageBox>
#include <QDir>
#include "user.h"


class AnonymousUser : public User
{
public:
    AnonymousUser();
    void SetFollowersAnonymousUser();
    bool SetAttributeAnonymousUser();


private:
    int Followers;

};

#endif // ANONYMOUSUSER_H
