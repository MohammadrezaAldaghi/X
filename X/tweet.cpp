#include "tweet.h"

Tweet::Tweet()
{
    srand(time(nullptr));
    QDir().mkdir("Tweet");
    try
    {
        QDir directory("Tweet");
        if(directory.exists())
        {

        }
        else
        {
            throw std::invalid_argument("Error");
        }

    }
    catch(std::exception& e)
    {
        QMessageBox::critical(nullptr,e.what(),"File not Created");
    }
}

void Tweet::AddTweet(QString username, QString message, QString hashtag,QString name,int like)
{
    {
        QFile file("Tweet/Tweet.json");
        try
        {
            if (file.open(QIODevice::ReadWrite))
            {
                QByteArray fileData = file.readAll();

                QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData);

                QJsonArray jsonArray;
                if (jsonDoc.isArray())
                {
                    jsonArray = jsonDoc.array();
                }

                QJsonObject jsonObj;
                jsonObj["Username"] = username;
                jsonObj["Message"] = message;
                jsonObj["#"] = hashtag;
                jsonObj["Name"] = name;
                jsonObj["TweetID"] = QString::fromStdString(std::to_string(rand()*rand()*rand()));
                jsonObj["Like"] = QString::fromStdString(std::to_string(like));
                jsonArray.append(jsonObj);

                QJsonDocument newJsonDoc(jsonArray);

                file.resize(0);
                file.write(newJsonDoc.toJson());

                file.close();
            }
            else
            {
                file.close();
                throw std::invalid_argument("invalid file path");
            }
        }
        catch(std::exception &e)
        {
            QMessageBox::critical(nullptr,e.what(),"There was a problem, please try again");
        }
    }
}

void Tweet::test(QString tweetid)
{
    QFile file("Tweet/Tweet.json");

        if(file.open(QIODevice::ReadOnly))
        {
            QByteArray fileData = file.readAll();

            QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData);

            if (jsonDoc.isArray())
            {
                QJsonArray jsonArray = jsonDoc.array();

                foreach (const QJsonValue &value, jsonArray)
                {
                    QJsonObject obj = value.toObject();

                    QString username = obj.value("Username").toString();
                    QString message = obj.value("Message").toString();
                    QString hashtag = obj.value("#").toString();
                    QString name = obj.value("Name").toString();
                    QString tweetID = obj.value("TweetID").toString();
                    QString like = obj.value("Like").toString();

                    {
                        if(tweetid==tweetID)
                        {
                            AddُTheNumberOfLikesToTweet(username,message,hashtag,name,like.toInt()+1,tweetid);
                        }
                        else
                        {
                            AddُTheNumberOfLikesToTweet(username,message,hashtag,name,like.toInt(),tweetid);
                        }

                    }



                }
            }
        file.close();
        }



}



void Tweet::AddُTheNumberOfLikesToTweet(QString username, QString message, QString hashtag,QString name,int like,QString tweetId)
{


    {
        QFile file("Tweet/Tweet1.json");
        try
        {
            if (file.open(QIODevice::ReadWrite))
            {
                QByteArray fileData = file.readAll();

                QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData);

                QJsonArray jsonArray;
                if (jsonDoc.isArray())
                {
                    jsonArray = jsonDoc.array();
                }

                QJsonObject jsonObj;
                jsonObj["Username"] = username;
                jsonObj["Message"] = message;
                jsonObj["#"] = hashtag;
                jsonObj["Name"] = name;
                jsonObj["TweetID"] = QString::fromStdString(std::to_string(rand()*rand()*rand()));
                jsonObj["Like"] = QString::fromStdString(std::to_string(like));
                jsonArray.append(jsonObj);

                QJsonDocument newJsonDoc(jsonArray);

                file.resize(0);
                file.write(newJsonDoc.toJson());

                file.close();
            }
            else
            {
                file.close();
                throw std::invalid_argument("invalid file path");
            }
        }
        catch(std::exception &e)
        {
            QMessageBox::critical(nullptr,e.what(),"There was a problem, please try again");
        }
        file.close();
    }



}
