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
    QDateTime currentDateTime = QDateTime::currentDateTime();

    QDate currentDate = QDate::currentDate();
        QTime currentTime = QTime::currentTime();

        QString formattedDate = currentDate.toString("dddd, d MMMM yyyy");
        QString formattedTime = currentTime.toString("hh:mm AP");
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
                jsonObj["TweetID"] = QString::fromStdString(std::to_string(abs(rand()*rand()*rand())));
                jsonObj["Like"] = QString::fromStdString(std::to_string(like));
                jsonObj["Current Date"] = formattedDate;
                jsonObj["Current Time"] = formattedTime;
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

bool Tweet::test(QString tweetid,QString usernamePeson)
{
    qDebug()<<"test\n";
    QFile file("Tweet/Like.json");
    try
    {
        if(file.exists())
        {
            if (file.open(QIODevice::ReadOnly))
            {
                QByteArray fileData = file.readAll();

                QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData);

                if (jsonDoc.isArray())
                {
                    QJsonArray jsonArray = jsonDoc.array();

                    for (const auto& jsonValue : jsonArray)
                    {
                        if (jsonValue.isObject())
                        {
                            QJsonObject jsonObj = jsonValue.toObject();
                            QString username = jsonObj.value("Username").toString();
                            QString usernameLike = jsonObj.value("UsernameLike").toString();
                            QString tweetID = jsonObj.value("TweetID").toString();
                            qDebug()<<"username = "<<username<<" , usernameLike = "<<usernameLike<<" , tweetID = "<<tweetID<<"\n";
                            if(usernamePeson == usernameLike && tweetid == tweetID)
                            {
                                qDebug()<<"usernamePeson = " << usernamePeson << "\n";
                                file.close();
                                return false;
                            }
                        }
                    }
                }

                file.close();
            }
        }
        if(!file.exists())
        {
            return true;
        }
        else
        {
            file.close();
            throw std::invalid_argument("invalid file path");
        }
    }
    catch(std::exception &e)
    {
//        QMessageBox::critical(nullptr,e.what(),"There was a problem, please try again");
    }
    file.close();
    return true;
}

int Tweet::GetTweetLikeCounter(QString tweetID)
{
    int total = 0;
    QFile file("Tweet/Like.json");
    try
    {
        if(file.exists())
        {
            if (file.open(QIODevice::ReadOnly))
            {
                QByteArray fileData = file.readAll();

                QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData);

                if (jsonDoc.isArray())
                {
                    QJsonArray jsonArray = jsonDoc.array();

                    for (const auto& jsonValue : jsonArray)
                    {
                        if (jsonValue.isObject())
                        {
                            QJsonObject jsonObj = jsonValue.toObject();
                            QString username = jsonObj.value("Username").toString();
                            QString usernameLike = jsonObj.value("UsernameLike").toString();
                            QString tweetId = jsonObj.value("TweetID").toString();
                            int likeCounter;
                            if(jsonObj.value("TweetLike").toString()=="")
                            {
                                likeCounter = 0;
                            }
                            else
                            {
                                likeCounter = jsonObj.value("TweetLike").toInt();
                            }
                            if(tweetID == tweetId)
                            {
                                total++;
                            }

                        }
                    }
                }
            }

            file.close();
        }
        if(!file.exists())
        {
            return 0;
        }
        if(file.error())
        {
            file.close();
            throw std::invalid_argument("invalid file path");
        }
    }
    catch(std::exception &e)
    {
        QMessageBox::critical(nullptr,e.what(),"There was a problem, please try again");
    }
    qDebug()<<"Total = "<<total<<"\n";
    return total;
}

bool Tweet::DeleteTweet(QString tweetID)
{
    // Load the JSON file
        QFile file("Tweet/Tweet.json");
        if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
        {
            qDebug() << "Failed to open the JSON file.";
            return false;
        }

        // Parse the JSON document
        QByteArray jsonData = file.readAll();
        QJsonParseError jsonError;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &jsonError);
        if (jsonError.error != QJsonParseError::NoError)
        {
            qDebug() << "Failed to parse the JSON document:" << jsonError.errorString();
            file.close();
            return false;
        }

        // Get the root array of the JSON document
        QJsonArray rootArray = jsonDoc.array();

        // Find and remove the object with the specified TweetID
        for (int i = 0; i < rootArray.size(); ++i)
        {
            QJsonObject jsonObject = rootArray.at(i).toObject();
            if (jsonObject.value("TweetID").toString() == tweetID)
            {
                rootArray.removeAt(i);
                break;
            }
        }

        // Update the JSON document
        jsonDoc.setArray(rootArray);

        // Clear the file content
        file.resize(0);

        // Write the modified JSON document back to the file
        file.write(jsonDoc.toJson());
        file.close();

        qDebug() << "Object removed successfully.";
        return true;
}

void Tweet::AddُTheNumberOfLikesToTweet(QString usernameLike,QString TweetID,QString TweetUsername)
{
    qDebug()<<"AddُTheNumberOfLikesToTweet\n";

    {
        QFile file("Tweet/Like.json");
        try
        {
            if(test(TweetID,usernameLike)==true)
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
                    jsonObj["Username"] = TweetUsername;
                    jsonObj["UsernameLike"] = usernameLike;
                    jsonObj["TweetID"] = TweetID;
                    jsonObj["TweetLike"] = QString::fromStdString(std::to_string(GetTweetLikeCounter(TweetID) + 1));
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
        }
        catch(std::exception &e)
        {
            QMessageBox::critical(nullptr,e.what(),"There was a problem, please try again");
        }
        file.close();
    }




}
