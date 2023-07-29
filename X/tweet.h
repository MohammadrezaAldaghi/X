#ifndef TWEET_H
#define TWEET_H
#include <QString>
#include<QJsonDocument>
#include<QJsonObject>
#include<QObject>
#include<QDebug>
#include<QFile>
#include <QMessageBox>
#include <QDir>
#include <QMap>
#include <QByteArray>
#include <QJsonArray>


class Tweet
{
public:
    Tweet();
    void AddTweet(QString username,QString message,QString hashtag);

private:
//    QMap<QString UsernameTweet,QString Message> TweetMessage
    QMap<QString,QString> TweetMessage;
    QString Hashtag;

};

#endif // TWEET_H
