#include "mentionclasses.h"

MentionClasses::MentionClasses()
{
    QDir().mkdir("Mention");
    QDir directory ("Mention");
    if(directory.exists())
    {
        qDebug()<<"file create successfully\n";
    }
    else
    {
        qDebug()<<"file create not successfully\n ";
    }
}

void MentionClasses::SetMentionIDMentionClasses(QString mentionID)
{
    MentionID = mentionID;
}

void MentionClasses::SetUsernameSendMentionMentionClasses(QString usernameSendMention)
{
    UsernameSendMention = usernameSendMention;
}

void MentionClasses::SetUsernameNAMEMentionClasses(QString usernameNAME)
{
    UsernameNAME = usernameNAME;
}

void MentionClasses::SetAttributeMentionClasses()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();

    QDate currentDate = QDate::currentDate();
        QTime currentTime = QTime::currentTime();

        QString formattedDate = currentDate.toString("dddd, d MMMM yyyy");
        QString formattedTime = currentTime.toString("hh:mm AP");

//        qDebug() << "Current Date: " << formattedDate;
//        qDebug() << "Current Time: " << formattedTime;

    QFile file("Mention/Mention.json");
    try {
        if(Test(UsernameSendMention,MentionID))
        {
            if(file.open(QIODevice::ReadWrite))
            {
                QByteArray jsonData = file.readAll();

                QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);

                QJsonArray jsonArray ;
                if(jsonDoc.isArray())
                {
                    jsonArray = jsonDoc.array();
                }
                QJsonObject jsonObj ;
                jsonObj["MentionID"] = MentionID;
                jsonObj["UsernameSendMention"] = UsernameSendMention;
                jsonObj["UsernameNAME"] = UsernameNAME;
                jsonObj["MentionMessage"] = MentionMessage;
                jsonObj["Current Date"] = formattedDate;
                jsonObj["Current Time"] = formattedTime;
                jsonArray.append(jsonObj);
                QJsonDocument newDoc (jsonArray);
                file.resize(0);
                file.write(newDoc.toJson());
                file.close();

            }
            else
            {
                throw std::invalid_argument ("File not found");
            }
        }


    } catch (std::exception& e) {
        QMessageBox::critical(nullptr,"Error","! " + QString::fromStdString(e.what()));
    }
}

void MentionClasses::SetMentionMessageMentionClasses(QString mentionMessage)
{
    MentionMessage = mentionMessage;
}

bool MentionClasses::Test(QString usernameAccount, QString tweettid)
{
    QFile file("Mention/Mention.json");
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
                            QString usernameSendMention = jsonObj.value("UsernameSendMention").toString();
                            QString mentionID = jsonObj.value("MentionID").toString();
                            if(mentionID == tweettid && usernameSendMention == usernameAccount)
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

QVector<QJsonObject> MentionClasses::GetMentionClasses()
{
    QVector<QJsonObject> result;
    QFile file("Mention/Mention.json");
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
                            QString mentionID = jsonObj.value("MentionID").toString();
                            QString mentionMessage = jsonObj.value("MentionMessage").toString();
                            QString usernameNAME = jsonObj.value("UsernameNAME").toString();
                            QString usernameSendMention = jsonObj.value("UsernameSendMention").toString();
                            QString formattedDate = jsonObj.value("Current Date").toString();
                            QString formattedTime = jsonObj.value("Current Time").toString();
                            result.push_back(jsonObj);
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
