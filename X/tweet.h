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
#include <QtGlobal>


class Tweet
{
public:
    Tweet();
    void AddTweet(QString username,QString message,QString hashtag,QString name,int like);
    void AddُTheNumberOfLikesToTweet(QString usernameLike,QString TweetID,QString TweetUsername);
    bool test(QString tweetid,QString username);
    int GetTweetLikeCounter(QString tweetID);


private:
//    QMap<QString UsernameTweet,QString Message> TweetMessage
    QMap<QString,QString> TweetMessage;
    QString Hashtag;
    QString Name;
    bool UserLike = false;
};

#endif // TWEET_H
