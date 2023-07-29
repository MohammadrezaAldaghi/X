#include "personalaccount.h"
#include "ui_personalaccount.h"

PersonalAccount::PersonalAccount(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PersonalAccount)
{
    ui->setupUi(this);
    ReadFromFolderAllAccount();
    ui->SearchLabel->setStyleSheet("background-color : lightblue");
    connect(ui->listWidget,&QListWidget::itemClicked,this,&PersonalAccount::ShowItemClickedInformationWithQString);

}

PersonalAccount::~PersonalAccount()
{
    delete ui;
}

void PersonalAccount::ShowItemClickedInformationWithQString()
{

    QListWidgetItem* item = new QListWidgetItem("Salam");
    ui->listWidget->addItem(item);

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
//            connect(ui->listWidget,&QListWidget::itemClicked,this,&ShowItemClickedInformationWithQString);

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
//            connect(ui->listWidget,&QListWidget::itemClicked,this,&PersonalAccount::ShowItemClickedInformationWithQString);
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

void PersonalAccount::ReadFromFolderAllAccountWithQString(QString str)
{
    ui->listWidget->clear();
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
            if(temp.contains(str))
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
           if(temp.contains(str))
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
            if(temp.contains(str))
            ui->listWidget->addItem(item);
        }
    }
}

void PersonalAccount::ReadFromFolderAllTweet(QString str)
{
//    QFile file("Tweet/Tweet.json");
//    try
//    {
//        if(file.open(QIODevice::ReadOnly))
//        {
//            QByteArray fileData = file.readAll();

//            QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData);
//            QJsonObject jsonObj = jsonDoc.object();

//            QString username = jsonObj.value("Username").toString();
//            QString message = jsonObj.value("Message").toString();
//            QString hashtag = jsonObj.value("Hashtag").toString();
//            qDebug()<<username;
//            file.close();
//        }
//        else
//        {
//            file.close();
//            throw std::invalid_argument("invalid file path");
//        }
//    }
//    catch(std::exception &e)
//    {
//        QMessageBox::critical(nullptr,e.what(),"There was a problem, please try again");
//    }

    QFile file("Tweet/Tweet.json");
    try
    {
        if(file.open(QIODevice::ReadOnly))
        {
            QByteArray fileData = file.readAll();

            QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData);

            if (jsonDoc.isArray())
            {
                QJsonArray jsonArray = jsonDoc.array();

                foreach (const QJsonValue &value, jsonArray)
                {
                    QJsonObject obj = value.toObject();

                    QString username = obj.value("Username").toString();
                    QString message = obj.value("Message").toString();
                    QString hashtag = obj.value("#").toString();

                    qDebug() << "Username: " << username;
                    qDebug() << "Message: " << message;
                    qDebug() << "Hashtag: " << hashtag;
                    qDebug() << "-------------------";
                }
            }

            file.close();
        }
        else
        {
            file.close();
            throw std::invalid_argument("invalid file path");
        }
    }
    catch(std::exception &e)
    {
        QMessageBox::critical(nullptr,e.what(),"There was a problem, please try again");
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
    QListWidgetItem* item6 = new QListWidgetItem("Show my profile");

    QColor grrenBright(0,155,160);
    QColor skyColor(135, 100, 170);
    item1->setBackground(QBrush(skyColor));
    item2->setBackground(QBrush(skyColor));
    item3->setBackground(QBrush(skyColor));
    item4->setBackground(QBrush(skyColor));
    item5->setBackground(QBrush(skyColor));
    item6->setBackground(QBrush(grrenBright));

    ui->SettingListWidget->addItem(item1);
    ui->SettingListWidget->addItem(item2);
    ui->SettingListWidget->addItem(item3);
    ui->SettingListWidget->addItem(item4);
    ui->SettingListWidget->addItem(item5);
    ui->SettingListWidget->addItem(item6);
}


void PersonalAccount::on_SearchLineEdit_textChanged(const QString &arg1)
{
//    ReadFromFolderAllAccountWithQString(arg1);
    ReadFromFolderAllTweet(arg1);
}





void PersonalAccount::on_TweetButton_clicked()
{
    //hide ui
    {

    }

}

