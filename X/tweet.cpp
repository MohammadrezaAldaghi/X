#include "tweet.h"

Tweet::Tweet()
{
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

void Tweet::AddTweet(QString username, QString message, QString hashtag)
{
    QJsonObject jsonObj;
    jsonObj["Username"] = username;
    jsonObj["Message"] = message;
    jsonObj["#"] = hashtag;

    QJsonDocument jsonDoc(jsonObj);

    QByteArray jsonData = jsonDoc.toJson();

    QFile file("Tweet/Tweet.json");
    try
    {
        if(file.open(QIODevice::Append))
        {
            file.write(jsonData);
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
