#include "user.h"

User::User()
{

}

void User::SetUsername(QString username)
{
    Username = username;
}

void User::SetPassword(QString password)
{
    Password = password;
}

void User::SetUsernmaeAndPasswordUser(QString username,QString password)
{
    Password = password;
    Username = username;
}

