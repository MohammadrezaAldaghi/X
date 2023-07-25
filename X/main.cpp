#include "mainwindow.h"
#include "signupPersonalUser.h"
#include <QApplication>
#include "startwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    SignUp S;
//    S.show();

    Startwindow S;
    S.show();

    return a.exec();
}
