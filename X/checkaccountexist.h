#ifndef CHECKACCOUNTEXIST_H
#define CHECKACCOUNTEXIST_H
#include <QString>
#include<QJsonDocument>
#include<QJsonObject>
#include<QObject>
#include<QDebug>
#include<QFile>
#include <QMessageBox>
#include <QDir>


class CheckAccountExist
{
public:
    CheckAccountExist();
    void SetUsernameCheckCheckAccountExist(QString usernameCheck);
    bool ItExist(QString usernameExist);


private:
    QString UsernameCheck;


};

#endif // CHECKACCOUNTEXIST_H
