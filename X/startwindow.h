#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>
#include "personaluser.h"
#include "signupPersonalUser.h"


namespace Ui {
class Startwindow;
}

class Startwindow : public QWidget
{
    Q_OBJECT

public:
    explicit Startwindow(QWidget *parent = nullptr);
    ~Startwindow();

private slots:
    void on_OrganisationButton_clicked();

    void on_PersonalButton_clicked();

private:
    Ui::Startwindow *ui;
};

#endif // STARTWINDOW_H
