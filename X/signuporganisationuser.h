#ifndef SIGNUPORGANISATIONUSER_H
#define SIGNUPORGANISATIONUSER_H

#include <QWidget>

namespace Ui {
class SignUpOrganisationUser;
}

class SignUpOrganisationUser : public QWidget
{
    Q_OBJECT

public:
    explicit SignUpOrganisationUser(QWidget *parent = nullptr);
    ~SignUpOrganisationUser();

private:
    Ui::SignUpOrganisationUser *ui;
};

#endif // SIGNUPORGANISATIONUSER_H
