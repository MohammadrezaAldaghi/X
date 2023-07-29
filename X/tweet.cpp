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
