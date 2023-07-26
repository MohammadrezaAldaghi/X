#include "signuporganisationuser.h"
#include "ui_signuporganisationuser.h"

SignUpOrganisationUser::SignUpOrganisationUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignUpOrganisationUser)
{
    ui->setupUi(this);
}

SignUpOrganisationUser::~SignUpOrganisationUser()
{
    delete ui;
}
