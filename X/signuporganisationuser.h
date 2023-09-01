#ifndef SIGNUPORGANISATIONUSER_H
#define SIGNUPORGANISATIONUSER_H

#include <QWidget>
#include <QFileDialog>
#include "organisationuser.h"
#include <QImage>
#include <QTimer>


namespace Ui {
class SignUpOrganisationUser;
}

class SignUpOrganisationUser : public QWidget
{
    Q_OBJECT

public:
    explicit SignUpOrganisationUser(QWidget *parent = nullptr);
    ~SignUpOrganisationUser();

private slots:
    void on_ChoseImageButton_clicked();

    void on_RegisterButton_clicked();

    void on_CancelButton_clicked();

private:
    Ui::SignUpOrganisationUser *ui;
    QImage image;
};

#endif // SIGNUPORGANISATIONUSER_H
