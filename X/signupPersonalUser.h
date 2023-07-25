#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include "user.h"
#include <QTimer>
#include <QFileDialog>


namespace Ui {
class signupPersonalUser;
}

class signupPersonalUser : public QWidget
{
    Q_OBJECT

public:
    explicit signupPersonalUser(QWidget *parent = nullptr);
    ~signupPersonalUser();

private slots:
    void on_RegisterButton_clicked();

    void on_ChoseProfile_clicked();

private:
    Ui::signupPersonalUser *ui;
};

#endif // SIGNUP_H
