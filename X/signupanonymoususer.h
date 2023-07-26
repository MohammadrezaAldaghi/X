#ifndef SIGNUPANONYMOUSUSER_H
#define SIGNUPANONYMOUSUSER_H

#include <QWidget>
#include <QWidget>
#include <QFileDialog>
#include "organisationuser.h"
#include <QImage>
#include <QTimer>
#include "anonymoususer.h"


namespace Ui {
class SignUpAnonymousUser;
}

class SignUpAnonymousUser : public QWidget
{
    Q_OBJECT

public:
    explicit SignUpAnonymousUser(QWidget *parent = nullptr);
    ~SignUpAnonymousUser();

private slots:
    void on_RegisterButton_clicked();

private:
    Ui::SignUpAnonymousUser *ui;
};

#endif // SIGNUPANONYMOUSUSER_H
