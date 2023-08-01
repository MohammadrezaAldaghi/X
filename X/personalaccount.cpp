#include "personalaccount.h"
#include "tweetform.h"
#include "ui_personalaccount.h"

PersonalAccount::PersonalAccount(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PersonalAccount)
{
    ui->setupUi(this);
    srand(time(nullptr));
//    {
//        QTimer *timer = new QTimer();
//        timer->setInterval(1000); // fire every second
//        connect(timer, SIGNAL(), this, SLOT(ReadFromFolderAllTweet()));
//        timer->start();
//    }
    {
        ui->BiogrphyButton->hide();
    }

    ReadFromFolderAllAccount();
    ui->SearchLabel->setStyleSheet("color : red");
    connect(ui->listWidget, &QListWidget::itemClicked, this,&PersonalAccount::ItemClickedSettingListWidget);
    connect(ui->SettingListWidget,&QListWidget::itemClicked,this,&PersonalAccount::ItemClickedSettingListWidget);
    connect(ui->FindHashtagOrUsernameListWidget,&QListWidget::itemClicked,this,&PersonalAccount::onButtonClicked);
    connect(ui->FindHashtagOrUsernameListWidget, &QListWidget::itemClicked, this,&PersonalAccount:: ItemClickedSettingListWidget);


}
PersonalAccount::~PersonalAccount()
{
    delete ui;
}

void PersonalAccount::ShowItemClickedInformationWithQString()
{
    ui->FindHashtagOrUsernameListWidget->clear();
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

                    QListWidgetItem* item = new QListWidgetItem("Message : " + message + "\n Hashtag : " + hashtag);
                    ui->FindHashtagOrUsernameListWidget->addItem(item);
                    ui->FindHashtagOrUsernameListWidget->setStyleSheet("color : darkblue");
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
    QFile temp("Tweet/Tweet1.json");
    if(temp.exists())
    {
        QFile::remove("Tweet/Tweet.json");
        QFile::rename("Tweet/Tweet1.json","Tweet/Tweet.json");
    }

    ui->FindHashtagOrUsernameListWidget->clear();
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
                    QString name = obj.value("Name").toString();
                    QString tweetID = obj.value("TweetID").toString();
                    QString likeTweet = obj.value("Like").toString();

                    // Create a new widget item for the text and button
                    QWidget *widgetItem = new QWidget(ui->FindHashtagOrUsernameListWidget);

                    // Create a label for the text
                    QLabel *textLabel = new QLabel(name + "  " + username + "\nMessage : " + message + "\n Hashtag : " + hashtag + "\n", widgetItem);

                    // Create the button
                    QPushButton *likeButton = new QPushButton("Like", widgetItem);
                    QPushButton *mentionButton = new QPushButton("Mention",widgetItem);
                    likeButton->setStyleSheet("color : green");
                    mentionButton->setStyleSheet("color : purple");

                    // Create a label for the button and text
                    QLabel* likeLabel = new QLabel();
                    likeLabel->setFixedSize(likeButton->size());
                    likeLabel->setText(likeTweet + " Likes ❤️");

                    // Create an object of the QFont class to set the text font
                    QFont font("Arial", 11);
                    likeLabel->setFont(font);

                    likeLabel->setStyleSheet("color : red");

                    // Create a horizontal layout for the button and text
                    QHBoxLayout *layout = new QHBoxLayout();
                    layout->addWidget(textLabel);
                    layout->addStretch(); // Add a stretchable space between the label and button
                    layout->addWidget(likeButton);
                    layout->addWidget(mentionButton);
                    layout->addWidget(likeLabel);
                    widgetItem->setLayout(layout);

                    // Create a new item for the widget
                    QListWidgetItem *item = new QListWidgetItem(ui->FindHashtagOrUsernameListWidget);
                    item->setSizeHint(widgetItem->sizeHint()); // Set the size hint for the item to match the size of the widget

                    // Set the widget as the item widget
                    ui->FindHashtagOrUsernameListWidget->setItemWidget(item, widgetItem);

                    ui->FindHashtagOrUsernameListWidget->setStyleSheet("color : darkblue");

                    // button signnal and slot (test)
                    {
//                        connect(likeButton,&QPushButton::clicked,this,&PersonalAccount::onButtonClicked);
                        connect(likeButton, &QPushButton::clicked, [=]()
                        {
                            test(tweetID);
                            // Handle the button click here
                        });
//                        connect(mentionButton,&QPushButton::clicked,this,&PersonalAccount::onButtonClicked);
                        connect(mentionButton,&QPushButton::clicked,[=]()
                        {
                            onButtonClicked();
                        });
                    }



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

void PersonalAccount::SetUsernameAndNamePersonalAcoount(QString username, QString Name)
{
    Username = username;
    this->Name = Name;
}

void PersonalAccount::DisplayProfilePersonalAcoount(QString username)
{
    ui->FindHashtagOrUsernameListWidget->clear();
    {
        QString folderPath = "Personal/";
        QDir directory(folderPath);
        QStringList jsonFiles = directory.entryList(QStringList() << "*.json", QDir::Files);
        foreach(QString fileName,jsonFiles)
        {
            QString temp = fileName;
            temp = temp.remove(".json");
            QListWidgetItem* item = new QListWidgetItem(temp);
            item->setBackground(Qt::red);
            if(temp==username)
            {
                ui->listWidget->addItem(item);
                {
                    QFile jsonFile("Personal/"+username+".json");
                    if (!jsonFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
                        // Error handling
                    }

                    QByteArray jsonData = jsonFile.readAll();
                    jsonFile.close();

                    QJsonParseError jsonError;
                    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &jsonError);

                    if (jsonError.error != QJsonParseError::NoError) {
                        // Error handling
                    }

                    if (!jsonDoc.isObject()) {
                        // Error handling
                    }

                    QJsonObject jsonObj = jsonDoc.object();
                    QString password = jsonObj["Password"].toString();
                    QString phoneNumber = jsonObj["PhoneNumber"].toString();
                    QString username = jsonObj["Username"].toString();
                    QString name = jsonObj["Name"].toString();
                    QString country = jsonObj["Country"].toString();
                    QString followers = jsonObj["Followers"].toString();
                    QString followings = jsonObj["Followings"].toString();
                    QString birthday = jsonObj["Birthday"].toString();
                    QString biography = jsonObj["Biography"].toString();

                    QListWidgetItem* item1 = new QListWidgetItem();
                    QListWidgetItem* item2 = new QListWidgetItem();
                    QListWidgetItem* item3 = new QListWidgetItem();
                    QListWidgetItem* item4 = new QListWidgetItem();
                    QListWidgetItem* item5 = new QListWidgetItem();
                    QListWidgetItem* item6 = new QListWidgetItem();
                    QListWidgetItem* item7 = new QListWidgetItem();
                    QListWidgetItem* item8 = new QListWidgetItem();
                    QListWidgetItem* item9 = new QListWidgetItem();
                    item1->setText("Username : " + username);
                    item2->setText("Password : " + password);
                    item3->setText("PhoneNumber : " + phoneNumber);
                    item4->setText("name : " + name);
                    item5->setText("Country : " + country);
                    item6->setText("Followers : " + followers);
                    item7->setText("Followings : " + followings);
                    item8->setText("Birthday : " + birthday);
                    item9->setText("Biography : " + biography);
                    ui->FindHashtagOrUsernameListWidget->addItem(item1);
                    ui->FindHashtagOrUsernameListWidget->addItem(item2);
                    ui->FindHashtagOrUsernameListWidget->addItem(item3);
                    ui->FindHashtagOrUsernameListWidget->addItem(item4);
                    ui->FindHashtagOrUsernameListWidget->addItem(item5);
                    ui->FindHashtagOrUsernameListWidget->addItem(item6);
                    ui->FindHashtagOrUsernameListWidget->addItem(item7);
                    ui->FindHashtagOrUsernameListWidget->addItem(item8);
                    ui->FindHashtagOrUsernameListWidget->addItem(item9);

                }

                return;
            }


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
            item->setBackground(Qt::red);
            if(temp==username)
            {
                ui->listWidget->addItem(item);
                {
                    QFile jsonFile("Organisation/"+username+".json");
                    if (!jsonFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
                        // Error handling
                    }

                    QByteArray jsonData = jsonFile.readAll();
                    jsonFile.close();

                    QJsonParseError jsonError;
                    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &jsonError);

                    if (jsonError.error != QJsonParseError::NoError) {
                        // Error handling
                    }

                    if (!jsonDoc.isObject()) {
                        // Error handling
                    }

                    QJsonObject jsonObj = jsonDoc.object();
                    QString password = jsonObj["Password"].toString();
                    QString phoneNumber = jsonObj["PhoneNumber"].toString();
                    QString username = jsonObj["Username"].toString();
                    QString biography = jsonObj["Biography"].toString();

                    QListWidgetItem* item1 = new QListWidgetItem();
                    QListWidgetItem* item2 = new QListWidgetItem();
                    QListWidgetItem* item3 = new QListWidgetItem();
                    QListWidgetItem* item9 = new QListWidgetItem();
                    item1->setText("Username : " + username);
                    item2->setText("Password : " + password);
                    item3->setText("PhoneNumber : " + phoneNumber);
                    item9->setText("Biography : " + biography);
                    ui->FindHashtagOrUsernameListWidget->addItem(item1);
                    ui->FindHashtagOrUsernameListWidget->addItem(item2);
                    ui->FindHashtagOrUsernameListWidget->addItem(item3);
                    ui->FindHashtagOrUsernameListWidget->addItem(item9);

                }

                return;
            }
        }
    }
    //*******************************************
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
                    if(temp==username)
                    {
                        ui->listWidget->addItem(item);
                        {
                            QFile jsonFile("Anonymous/"+username+".json");
                            if (!jsonFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
                                // Error handling
                            }

                            QByteArray jsonData = jsonFile.readAll();
                            jsonFile.close();

                            QJsonParseError jsonError;
                            QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &jsonError);

                            if (jsonError.error != QJsonParseError::NoError) {
                                // Error handling
                            }

                            if (!jsonDoc.isObject()) {
                                // Error handling
                            }

                            QJsonObject jsonObj = jsonDoc.object();
                            QString password = jsonObj["Password"].toString();
                            QString phoneNumber = jsonObj["PhoneNumber"].toString();
                            QString username = jsonObj["Username"].toString();
                            QString biography = jsonObj["Biography"].toString();
                            QString name = jsonObj["Name"].toString();
                            QListWidgetItem* item1 = new QListWidgetItem();
                            QListWidgetItem* item2 = new QListWidgetItem();
                            QListWidgetItem* item3 = new QListWidgetItem();
                            QListWidgetItem* item4 = new QListWidgetItem();
                            QListWidgetItem* item9 = new QListWidgetItem();
                            item1->setText("Username : " + username);
                            item2->setText("Password : " + password);
                            item3->setText("PhoneNumber : " + phoneNumber);
                            item9->setText("Biography : " + biography);
                            item4->setText("Name : " + name);
                            ui->FindHashtagOrUsernameListWidget->addItem(item1);
                            ui->FindHashtagOrUsernameListWidget->addItem(item2);
                            ui->FindHashtagOrUsernameListWidget->addItem(item3);
                            ui->FindHashtagOrUsernameListWidget->addItem(item4);
                            ui->FindHashtagOrUsernameListWidget->addItem(item9);

                        }

                        return;
                }
            }
        }

}

void PersonalAccount::AdjustBiographyWithUsernameAndPassword(QString username,QString bio)
{
    {
        QFile file("Personal/" + username + ".json");
        if(file.exists())
        {
            try{

                if(file.open(QIODevice::ReadOnly))
                {
                    QByteArray jsonData = file.readAll();
                    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
                    if(jsonDoc.isNull())
                    {
                        throw std::invalid_argument("not exist");
                    }
                    else
                    {
                        QJsonObject jsonObj = jsonDoc.object();
                        if(jsonObj.value("Username").toString()==username)
                        {
                            file.close();
                            QFile::remove("Personal/" + username);
                            if(file.open(QIODevice::WriteOnly))
                            {
                                jsonObj["Biography"] = bio;
                                QJsonDocument jDoc(jsonObj);
                                QByteArray jData = jDoc.toJson();
                                file.write(jData);
                                file.close();

                            }
                        }

                    }

                }
                else
                {
                    throw std::invalid_argument("file not found");
                }

            }
            catch(std::exception& e)
            {
                QMessageBox::critical(this,"Error",e.what());
            }
        }
        file.close();
    }
    //***************************************************
    {
        QFile file("Organisation/" + username + ".json");
        if(file.exists())
        {
            try{
                if(file.open(QIODevice::ReadOnly))
                {
                    QByteArray jsonData = file.readAll();
                    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
                    if(jsonDoc.isNull())
                    {
                        throw std::invalid_argument("not exist");
                    }
                    else
                    {
                        QJsonObject jsonObj = jsonDoc.object();
                        if(jsonObj.value("Username").toString()==username)
                        {
                            file.close();
                            QFile::remove("Organisation/" + username);
                            if(file.open(QIODevice::WriteOnly))
                            {
                                jsonObj["Biography"] = bio;
                                QJsonDocument jDoc(jsonObj);
                                QByteArray jData = jDoc.toJson();
                                file.write(jData);
                                file.close();

                            }
                        }

                    }

                }
                else
                {
                    throw std::invalid_argument("file not found");
                }

            }
            catch(std::exception& e)
            {
                QMessageBox::critical(this,"Error",e.what());
            }
        }
        file.close();
    }
    //**************************************************************
    {
        QFile file("Anonymous/" + username + ".json");
        if(file.exists())
        {
            try{
                if(file.open(QIODevice::ReadOnly))
                {
                    QByteArray jsonData = file.readAll();
                    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
                    if(jsonDoc.isNull())
                    {
                        throw std::invalid_argument("not exist");
                    }
                    else
                    {
                        QJsonObject jsonObj = jsonDoc.object();
                        if(jsonObj.value("Username").toString()==username)
                        {
                            file.close();
                            QFile::remove("Anonymous/" + username);
                            if(file.open(QIODevice::WriteOnly))
                            {
                                jsonObj["Biography"] = bio;
                                QJsonDocument jDoc(jsonObj);
                                QByteArray jData = jDoc.toJson();
                                file.write(jData);
                                file.close();

                            }
                        }

                    }

                }
                else
                {
                    throw std::invalid_argument("file not found");
                }

            }
            catch(std::exception& e)
            {
                QMessageBox::critical(this,"Error",e.what());
            }
        }
        file.close();
    }


}

void PersonalAccount::on_SettingButton_clicked()
{
    ui->SettingListWidget->clear();
    QListWidgetItem* item1 = new QListWidgetItem("Logout");
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
    TweetForm* T = new TweetForm();
    T->SetUsernameAndNameTweetForm(Username,Name);
    T->show();

}

void PersonalAccount::ItemClickedSettingListWidget(QListWidgetItem *itemArgument)
{
    qDebug()<<itemArgument->text()<<"\n";
    try {
       if(itemArgument->text()=="Show my profile")
       {
           DisplayProfilePersonalAcoount(Username);
       }
       if(itemArgument->text()=="Adjust Biography")
       {
           ui->FindHashtagOrUsernameListWidget->clear();
           QTextEdit* textEdit = new QTextEdit(ui->FindHashtagOrUsernameListWidget);
           textEdit->setFixedSize(ui->FindHashtagOrUsernameListWidget->size());
           textEdit->show();
           ui->SearchLabel->setText("input Biography");
           ui->SearchLineEdit->hide();
           ui->TweetButton->hide();
           ui->BiogrphyButton->show();

           connect(ui->BiogrphyButton,&QPushButton::clicked,[=]()
           {
            AdjustBiographyWithUsernameAndPassword(Username,textEdit->toPlainText());
            textEdit->clear();
            textEdit->hide();
            ui->FindHashtagOrUsernameListWidget->show();
            ui->SearchLabel->setText("Search :");
            ui->SearchLineEdit->show();
            ui->TweetButton->show();
            ui->BiogrphyButton->hide();
            on_SearchLineEdit_textChanged("");
           });
       }
       if(itemArgument->text() == "Logout")
       {
        try{
            bool THROW = false;
            if(QFile::remove( "Personal/"+Username + ".json"))
            {
               this->close();
               THROW = true;
               qApp->exit();
            }
            if(QFile::remove( "Anonymous/"+Username + ".json"))
            {
               this->close();
               THROW = true;
               qApp->exit();
            }
            if(QFile::remove( "Organisation/"+Username + ".json"))
            {
                this->close();
                THROW = true;
                qApp->exit();
            }
            if(!THROW)
            {
                throw std::invalid_argument("file not removed!!!!!!!!!!!");
            }
        }
           catch(std::exception& e)
           {
               QMessageBox::critical(this,"Error",e.what());
           }


       }

    } catch (std::exception& e)
    {
        QMessageBox::critical(this,"Error",e.what());
    }
//یک تابع براش باید بنویسم
}

void PersonalAccount::onButtonClicked()
{
    long test = rand() * rand();
    qDebug()<<"mentionButton"<<", test = "<<test<<"\n";
}

void PersonalAccount::test(QString te)
{
    Tweet t;
    t.test(te);
}

