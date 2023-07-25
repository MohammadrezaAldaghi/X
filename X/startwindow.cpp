#include "startwindow.h"
#include "ui_startwindow.h"

Startwindow::Startwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Startwindow)
{
    ui->setupUi(this);
    setStyleSheet("background-color: yellow");
    ui->AnonymousButton->setStyleSheet("color : red");
    ui->AnonymousButton->setToolTip("<span style='font-size: 14px;'> This account will be created for organizations, departments and companies</span>");
    ui->OrganisationButton->setStyleSheet("color : blue");
    ui->OrganisationButton->setToolTip("<span style='font-size: 14px;'> These types of accounts will be made for ordinary people</span>");
    ui->PersonalButton->setStyleSheet("color : green");
    ui->PersonalButton->setToolTip("<span style='font-size: 14px;'> you can track personal accounts.</span>");
}

Startwindow::~Startwindow()
{
    delete ui;
}