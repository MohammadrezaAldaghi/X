#ifndef MENTIONCLASSES_H
#define MENTIONCLASSES_H
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
#include <QDate>
#include <QTime>
#include <QDebug>


class MentionClasses
{
public:
    MentionClasses();
    void SetMentionIDMentionClasses(QString mentionID);
    void SetUsernameSendMentionMentionClasses(QString usernameSendMention);
    void SetUsernameNAMEMentionClasses(QString usernameNAME);
    void SetAttributeMentionClasses();
    void SetMentionMessageMentionClasses(QString mentionMessage);
    bool Test(QString usernameAccount,QString tweettid);
    QVector<QJsonObject> GetMentionClasses();

private :

    QString MentionID;
    QString UsernameSendMention;
    QString UsernameNAME;
    QString MentionMessage;

};

#endif // MENTIONCLASSES_H
