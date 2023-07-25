#include "mainwindow.h"
#include "signup.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    SignUp S;
    S.show();

    return a.exec();
}
