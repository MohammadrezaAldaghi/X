#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include "user.h"
#include <QTimer>
#include <QFileDialog>


namespace Ui {
class SignUp;
}

class SignUp : public QWidget
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();

private slots:
    void on_RegisterButton_clicked();

    void on_ChoseProfile_clicked();

private:
    Ui::SignUp *ui;
};

#endif // SIGNUP_H
