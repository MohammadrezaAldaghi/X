#include "checkaccountexist.h"

CheckAccountExist::CheckAccountExist()
{

}

void CheckAccountExist::SetUsernameCheckCheckAccountExist(QString usernameCheck)
{
    UsernameCheck = usernameCheck;
}

bool CheckAccountExist::ItExist(QString usernameExist)
{
    {
        QString folderPath = "Anonymous/";
        QDir directory(folderPath);
        QStringList jsonFiles = directory.entryList(QStringList() << "*.json", QDir::Files);
        foreach(QString fileName,jsonFiles)
        {
            QString temp = fileName;
            temp = temp.remove(".json");
            if(temp == usernameExist)
            {
                return false;
            }
        }
    }
    //*******************************************
    {
        QString folderPath = "Personal/";
        QDir directory(folderPath);
        QStringList jsonFiles = directory.entryList(QStringList() << "*.json", QDir::Files);
        foreach(QString fileName,jsonFiles)
        {
            QString temp = fileName;
            temp = temp.remove(".json");
            if(temp == usernameExist)
            {
                return false;
            }
        }
    }
    //*******************************************
    {
        QString folderPath = "Organisation/";
        QDir directory(folderPath);
        QStringList jsonFiles = directory.entryList(QStringList() << "*.json", QDir::Files);
        foreach(QString fileName,jsonFiles)
        {
            QString temp = fileName;
            temp = temp.remove(".json");
            if(temp == usernameExist)
            {
                return false;
            }
        }
    }

    return true;

}
