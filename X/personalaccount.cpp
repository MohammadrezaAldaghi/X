#include "personalaccount.h"
#include "ui_personalaccount.h"

PersonalAccount::PersonalAccount(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PersonalAccount)
{
    ui->setupUi(this);
    ReadFromFolderAllAccount();


}

PersonalAccount::~PersonalAccount()
{
    delete ui;
}

void PersonalAccount::ReadFromFolderAllAccount()
{
    {
        QString folderPath = "Anonymous/";
        QDir directory(folderPath);
        QStringList jsonFiles = directory.entryList(QStringList() << "*.json", QDir::Files);
        foreach(QString fileName,jsonFiles)
        {
            QString temp = fileName;
            temp = temp.remove(".json");
            QListWidgetItem* item = new QListWidgetItem(temp);
            item->setBackground(Qt::red);
            ui->listWidget->addItem(item);
        }
    }
    //*******************************************
    {
        QString folderPath = "Personal/";
        QDir directory(folderPath);
        QStringList jsonFiles = directory.entryList(QStringList() << "*.json", QDir::Files);
        foreach(QString fileName,jsonFiles)
        {
            QString temp = fileName;
            temp = temp.remove(".json");
            QListWidgetItem* item = new QListWidgetItem(temp);
            item->setBackground(Qt::blue);
            ui->listWidget->addItem(item);
        }
    }
    //*******************************************
    {
        QString folderPath = "Organisation/";
        QDir directory(folderPath);
        QStringList jsonFiles = directory.entryList(QStringList() << "*.json", QDir::Files);
        foreach(QString fileName,jsonFiles)
        {
            QString temp = fileName;
            temp = temp.remove(".json");
            QListWidgetItem* item = new QListWidgetItem(temp);
            item->setBackground(Qt::green);
            ui->listWidget->addItem(item);
        }
    }
}

void PersonalAccount::on_SettingButton_clicked()
{
    ui->SettingListWidget->clear();
    QListWidgetItem* item1 = new QListWidgetItem("Lagout");
    QListWidgetItem* item2 = new QListWidgetItem("Adjust profile");
    QListWidgetItem* item3 = new QListWidgetItem("Adjust Biography");
    QListWidgetItem* item4 = new QListWidgetItem("Change usernam or password");
    QListWidgetItem* item5 = new QListWidgetItem("Change Phone number");

    QColor skyColor(135, 100, 235);
    item1->setBackground(QBrush(skyColor));
    item2->setBackground(QBrush(skyColor));
    item3->setBackground(QBrush(skyColor));
    item4->setBackground(QBrush(skyColor));
    item5->setBackground(QBrush(skyColor));

    ui->SettingListWidget->addItem(item1);
    ui->SettingListWidget->addItem(item2);
    ui->SettingListWidget->addItem(item3);
    ui->SettingListWidget->addItem(item4);
    ui->SettingListWidget->addItem(item5);
}

