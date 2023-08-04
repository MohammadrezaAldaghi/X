#ifndef FOLLOWERSCLASSES_H
#define FOLLOWERSCLASSES_H
#include <QString>
#include<QJsonDocument>
#include<QJsonObject>
#include<QObject>
#include<QDebug>
#include<QFile>
#include <QMessageBox>
#include <QDir>
#include <QJsonArray>
#include <QVector>

class FollowersClasses
{
public:
    FollowersClasses();
    void SetFollowersClassesFollowedAccount(QString followedAccount);
    void SetFollowersClassesFollowerAccount(QString followerAccount);
    void SetAttributeFollowersClasses();
    QVector<QString> GetFollowersClassesFollowedAccount(QString username);
    int GetFollowerClassFollowedAccount(QString followedAccount);
    bool Test(QString followedAccount,QString followerAccount);

private:
    QString FollowedAccount;
    QString FollowerAccount;

};

#endif // FOLLOWERSCLASSES_H
