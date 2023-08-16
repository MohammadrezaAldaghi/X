#ifndef LOGINFORM_H
#define LOGINFORM_H

#include "qtmetamacros.h"
#include "qwidget.h"
#include <QWidget>
#include <QWidget>
#include "user.h"
#include <QTimer>
#include <QFileDialog>


namespace Ui {
class LoginForm;
}

class LoginForm : public QWidget
{
    Q_OBJECT;

public:
    explicit LoginForm(QWidget *parent = nullptr);
    ~LoginForm();

private slots:
    void on_LoginButton_clicked();

    void on_CancelButton_clicked();

private:
    Ui::LoginForm *ui;
};

#endif // LOGINFORM_H
