#include "mainwindow.h"
#include "signupPersonalUser.h"
#include <QApplication>
#include "startwindow.h"
#include "signuporganisationuser.h"
#include "signupanonymoususer.h"
#include "loginform.h"
#include "personalaccount.h"
#include "tweetform.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    SignUp S;
//    S.show();

    Startwindow S;
    S.show();

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
