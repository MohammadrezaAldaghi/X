#include "mainwindow.h"
#include "signupPersonalUser.h"
#include <QApplication>
#include "startwindow.h"
#include "signuporganisationuser.h"
#include "signupanonymoususer.h"
#include "loginform.h"
#include "personalaccount.h"
#include "tweetform.h"

#include <QDate>
#include <QTime>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QDateTime currentDateTime = QDateTime::currentDateTime();

//    QDate currentDate = QDate::currentDate();
//        QTime currentTime = QTime::currentTime();

//        QString formattedDate = currentDate.toString("dddd, d MMMM yyyy");
//        QString formattedTime = currentTime.toString("hh:mm AP");

//        qDebug() << "Current Date: " << formattedDate;
//        qDebug() << "Current Time: " << formattedTime;


    MainWindow w;
    w.show();

//    SignUp S;
//    S.show();

//    Startwindow S;
//    S.show();

//    SignUpOrganisationUser S;
//    S.show();

//    SignUpAnonymousUser S;
//    S.show();

//    LoginForm L;
//    L.show();

//    PersonalAccount P;
//    P.show();

//    TweetForm T;
//    T.show();



    return a.exec();
}
