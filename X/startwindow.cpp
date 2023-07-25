#include "startwindow.h"
#include "ui_startwindow.h"

Startwindow::Startwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Startwindow)
{
    ui->setupUi(this);
    setStyleSheet("background-color: yellow");
    ui->AnonymousLabel->setStyleSheet("color : red");
    ui->OrganisationLabel->setStyleSheet("color : blue");
    ui->PersonalLabel->setStyleSheet("color : green");
}

Startwindow::~Startwindow()
{
    delete ui;
}
