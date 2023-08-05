#include "followersclasses.h"


FollowersClasses::FollowersClasses()
{
    //Create "Follower " folder
    QDir().mkdir("Follower");
}

void FollowersClasses::SetFollowersClassesFollowedAccount(QString followedAccount)
{
    FollowedAccount = followedAccount;
}

void FollowersClasses::SetFollowersClassesFollowerAccount(QString followerAccount)
{
    FollowerAccount = followerAccount;
}

void FollowersClasses::SetAttributeFollowersClasses()//برای همه نوع اکانت یکسان است
{
   QFile file("Follower/Follower.json");
   try {
       if(Test(FollowedAccount,FollowerAccount) == true)
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
               jsonObj["FollowerAccount"] = FollowerAccount;
               jsonObj["FollowedAccount"] = FollowedAccount;
               jsonArray.append(jsonObj);

               QJsonDocument newJsonDoc(jsonArray);

               file.resize(0);
               file.write(newJsonDoc.toJson());
               file.close();
           }
           else
           {
               file.close();
               throw std::invalid_argument("File create not successfully");
           }
       }

   } catch (std::exception& e) {
       file.close();
       QMessageBox::critical(nullptr,"Error",e.what());
   }

}

QVector<QString> FollowersClasses::GetFollowersClassesFollowedAccount(QString username)
{
    QVector <QString> result;
    QFile file("Follower/Follower.json");
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
                            QString followerAccount = jsonObj.value("FollowerAccount").toString();
                            QString followedAccount = jsonObj.value("FollowedAccount").toString();

                            if(followerAccount == username)
                            {
                                result.push_back(followedAccount);
                            }
                            else
                            {

                            }
                        }
                    }
                }
            }

            file.close();
        }
        if(!file.exists())
        {
            return result;
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
    return result;
}

int FollowersClasses::GetFollowerClassFollowedAccount(QString followedAccount)
{
    QFile file("Follower/Follower.json");

    int total = 0;
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
                            QString followedaccount = jsonObj.value("FollowedAccount").toString();
                            int likeCounter;
                            if(jsonObj.value("FollowedAccount").toString()=="")
                            {
                                likeCounter = 0;
                            }
                            if(followedAccount == followedaccount)
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

bool FollowersClasses::Test(QString followedAccount, QString followerAccount)
{
    QFile file("Follower/Follower.json");
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
                            QString followedaccount = jsonObj.value("FollowedAccount").toString();
                            QString followeraccount = jsonObj.value("FollowerAccount").toString();
                            if(followedAccount == followedaccount && followerAccount == followeraccount)
                            {
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

bool FollowersClasses::IsUserCanFollower(QString USER)
{
    qDebug()<<"FollowerAccount = "<<USER<<"\n";
    //read from Organisation User
    {
        QFile jsonFile("Organisation/"+ USER +".json");
        if(jsonFile.exists())
        {
            return true;
        }
    }
    //read Personal User
    {
        QFile jsonFile("Personal/"+USER+".json");
        if(jsonFile.exists())
        {
            return true;
        }

    }
    return false;
}

QVector<QString> FollowersClasses::GetFollowedClassFollowedAccount(QString followedAccountUsername)
{
    QVector <QString> result;
    QFile file("Follower/Follower.json");
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
                            QString followerAccount = jsonObj.value("FollowerAccount").toString();
                            QString followedAccount = jsonObj.value("FollowedAccount").toString();

                            if(followedAccount == followedAccountUsername)
                            {
                                result.push_back(followerAccount);

                            }
                            else
                            {

                            }
                        }
                    }
                }
            }

            file.close();
        }
        if(!file.exists())
        {
            return result;
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
    return result;
}
