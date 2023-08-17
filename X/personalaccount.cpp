#include "personalaccount.h"
#include "tweetform.h"
#include "ui_personalaccount.h"

PersonalAccount::PersonalAccount(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PersonalAccount)
{
    ui->setupUi(this);
    srand(time(nullptr));
//    setStyleSheet("background-color: #B0C4DE;");
    {
        ui->BiogrphyButton->hide();
    }

    ReadFromFolderAllAccount();
    ReadFromFolderAllTweet("s");
    ui->SearchLabel->setStyleSheet("color : red");
    connect(ui->listWidget, &QListWidget::itemClicked, this,&PersonalAccount::ItemClickedSettingListWidget);
    connect(ui->SettingListWidget,&QListWidget::itemClicked,this,&PersonalAccount::ItemClickedSettingListWidget);
    connect(ui->FindHashtagOrUsernameListWidget, &QListWidget::itemClicked, this,&PersonalAccount::ItemClickedExpelor);




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
    if (temp.exists())
    {
        QFile::remove("Tweet/Tweet.json");
        QFile::rename("Tweet/Tweet1.json", "Tweet/Tweet.json");
    }

    ui->FindHashtagOrUsernameListWidget->clear();
    QFile file("Tweet/Tweet.json");
    try
    {
        if (file.open(QIODevice::ReadOnly))
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
                    {
                        likeTweet = QString::fromStdString(std::to_string(GetTweetLikePersonalAccountWithTweetID(tweetID)));
                    }
                    QString currentDate = obj.value("Current Date").toString();
                    QString currentTime = obj.value("Current Time").toString();

                    // Create a new widget item for the text and button
                    QWidget *widgetItem = new QWidget(ui->FindHashtagOrUsernameListWidget);

                    // Create a label for the text
                    QLabel *textLabel = new QLabel(name + "  @" + username + "\nMessage : " + message + "\n Hashtag : " + hashtag + "\n" +
                    currentDate + " , " + currentTime + "\n", widgetItem);

                    // Create the buttons
                    QPushButton *likeButton = new QPushButton("Like", widgetItem);
                    QPushButton *mentionButton = new QPushButton("Mention sent", widgetItem);
                    QPushButton *followButton = new QPushButton("Follow", widgetItem);
                    QPushButton *ShowMention = new QPushButton("Show Mention",widgetItem);

                    likeButton->setStyleSheet("color : green");
                    mentionButton->setStyleSheet("color : purple");
                    followButton->setStyleSheet("color : blue");
                    ShowMention->setStyleSheet("color : red");

                    // Create a label for the button and text
                    QLabel *likeLabel = new QLabel();
                    likeLabel->setFixedSize(likeButton->size());
                    likeLabel->setText(likeTweet + " Likes ❤️");

                    // Create a LineEdit for the button and text
                    QLineEdit *mentionLineEdit = new QLineEdit();
                    mentionLineEdit->setStyleSheet("color: rgb(150, 150, 150)");
                    mentionLineEdit->setFixedWidth(725);
                    mentionLineEdit->setFixedHeight(40);
                    mentionLineEdit->setToolTip("mention");

                    // Create an object of the QFont class to set the text font
                    QFont font("Arial", 11);
                    likeLabel->setFont(font);

                    likeLabel->setStyleSheet("color : red");

                    // Create a horizontal layout for the buttons
                    QHBoxLayout *buttonLayout = new QHBoxLayout();
                    buttonLayout->addWidget(likeButton);
                    buttonLayout->addWidget(mentionButton);
                    buttonLayout->addWidget(followButton);
                    buttonLayout->addWidget(ShowMention);

                    // Create a vertical layout for the label, buttons, and line edit
                    QVBoxLayout *verticalLayout = new QVBoxLayout();
                    verticalLayout->addWidget(textLabel);
                    verticalLayout->addWidget(likeLabel);
                    verticalLayout->addLayout(buttonLayout);
                    verticalLayout->addWidget(mentionLineEdit);
                    widgetItem->setLayout(verticalLayout);

                    // Create a new item for the widget
                    QListWidgetItem *item = new QListWidgetItem(ui->FindHashtagOrUsernameListWidget);
                    item->setSizeHint(widgetItem->sizeHint()); // Set the size hint for the item to match the size of the widget

                    // Set the widget as the item widget
                    ui->FindHashtagOrUsernameListWidget->setItemWidget(item, widgetItem);
                    item->setBackground(QBrush("lightgreen"));
                    ui->FindHashtagOrUsernameListWidget->setStyleSheet("color : darkblue");

                    // button signal and slot (test)
                    {
                        connect(likeButton, &QPushButton::clicked, [=]() {
                            LikeButtonTweet(tweetID, username);
                            // Handle the button click here
                        });
                        connect(mentionButton, &QPushButton::clicked, [=]() {
                            MentionButtonTweet(Name,Username,tweetID,mentionLineEdit->text());
                            mentionLineEdit->clear();
                        });
                        connect(followButton, &QPushButton::clicked, [=]() {
                            FollowerButtonAccount(username, Username);
                        });
                        connect(ShowMention,&QPushButton::clicked, [=]() {
                            BackgroundTweetClicked(tweetID);
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
    catch (std::exception &e)
    {
        QMessageBox::critical(nullptr, e.what(), "There was a problem, please try again");
    }

}

void PersonalAccount::SetUsernameAndNamePersonalAcoount(QString username, QString Name)
{
    Username = username;
    this->Name = Name;
}

void PersonalAccount::DisplayProfilePersonalAcoount(QString username)
{
    QLabel* imageLabel = new QLabel(this);

    // تعیین مسیر فایل عکس (می‌توانید مسیر را بر اساس شرایط خود تغییر دهید)
    QString imagePath = "C:/Users/ARTA/Desktop/tweet.png";

    // بارگذاری عکس از فایل
    QPixmap pixmap(imagePath);

    // تنظیم اندازه عکس
    QPixmap scaledPixmap = pixmap.scaled(QSize(250, 250), Qt::KeepAspectRatio);

    // نمایش عکس در QLabel
    imageLabel->setPixmap(scaledPixmap);
    ui->FindHashtagOrUsernameListWidget->clear();
    {
        QString folderPath = "Personal/";
        QDir directory(folderPath);
        QStringList jsonFiles = directory.entryList(QStringList() << "*.json", QDir::Files);
        foreach(QString fileName,jsonFiles)
        {
            QString temp = fileName;
            temp = temp.remove(".json");
            QListWidgetItem* itemList = new QListWidgetItem(temp);
            itemList->setBackground(Qt::red);
            if(temp==username)
            {
                ui->listWidget->addItem(itemList);
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
                    QListWidgetItem* item10 = new QListWidgetItem();

                    item1->setText("Username : " + username);
                    item2->setText("Password : " + password);
                    item3->setText("PhoneNumber : " + phoneNumber);
                    item4->setText("name : " + name);
                    item5->setText("Country : " + country);
                    item6->setText("Followers : " + followers);
                    item7->setText("Followings : " + followings);
                    item8->setText("Birthday : " + birthday);
                    item9->setText("Biography : " + biography);
                    item10->setSizeHint(QSize(150,150));

                    ui->FindHashtagOrUsernameListWidget->addItem(item1);
                    ui->FindHashtagOrUsernameListWidget->addItem(item2);
                    ui->FindHashtagOrUsernameListWidget->addItem(item3);
                    ui->FindHashtagOrUsernameListWidget->addItem(item4);
                    ui->FindHashtagOrUsernameListWidget->addItem(item5);
                    ui->FindHashtagOrUsernameListWidget->addItem(item6);
                    ui->FindHashtagOrUsernameListWidget->addItem(item7);
                    ui->FindHashtagOrUsernameListWidget->addItem(item8);
                    ui->FindHashtagOrUsernameListWidget->addItem(item9);
                    ui->FindHashtagOrUsernameListWidget->addItem(item10);
                    ui->FindHashtagOrUsernameListWidget->setItemWidget(item10,imageLabel);

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
            QListWidgetItem* itemList = new QListWidgetItem(temp);
            itemList->setBackground(Qt::red);
            if(temp==username)
            {
                ui->listWidget->addItem(itemList);
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
                    QString headOfTheOrganization = jsonObj["HeadOfTheOrganization"].toString();

                    QListWidgetItem* item1 = new QListWidgetItem();
                    QListWidgetItem* item2 = new QListWidgetItem();
                    QListWidgetItem* item3 = new QListWidgetItem();
                    QListWidgetItem* item4 = new QListWidgetItem();
                    QListWidgetItem* item9 = new QListWidgetItem();

                    item1->setText("Username : " + username);
                    item2->setText("Password : " + password);
                    item3->setText("PhoneNumber : " + phoneNumber);
                    item4->setText("Head Of The Organization : " + headOfTheOrganization);
                    item9->setText("Biography : " + biography);
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
    //*******************************************
    {
                QString folderPath = "Anonymous/";
                QDir directory(folderPath);
                QStringList jsonFiles = directory.entryList(QStringList() << "*.json", QDir::Files);
                foreach(QString fileName,jsonFiles)
                {
                    QString temp = fileName;
                    temp = temp.remove(".json");
                    QListWidgetItem* itemList = new QListWidgetItem(temp);
                    itemList->setBackground(Qt::red);
                    if(temp==username)
                    {
                        ui->listWidget->addItem(itemList);
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

void PersonalAccount::Logout()
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

void PersonalAccount::ChnageNamePersonalAccountWithUsernameAndPasswordChangeSafly(QString usernam1,QString NewName)
{
    {
        QFile file("Personal/" + usernam1 + ".json");
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
                        if(jsonObj.value("Username").toString()==usernam1)
                        {
                            file.close();
                            QFile::remove("Personal/" + usernam1);
                            if(file.open(QIODevice::WriteOnly))
                            {
                                jsonObj["Name"] = NewName;
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
        QFile file("Organisation/" + usernam1 + ".json");
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
                        if(jsonObj.value("Username").toString()==usernam1)
                        {
                            file.close();
                            QFile::remove("Organisation/" + usernam1);
                            if(file.open(QIODevice::WriteOnly))
                            {
                                jsonObj["Name"] = NewName;
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
        QFile file("Anonymous/" + usernam1 + ".json");
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
                        if(jsonObj.value("Username").toString()==usernam1)
                        {
                            file.close();
                            QFile::remove("Anonymous/" + usernam1);
                            if(file.open(QIODevice::WriteOnly))
                            {
                                jsonObj["Name"] = NewName;
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

void PersonalAccount::ChangeBirthdayPersonalAccountWithUsernameAndPasswordChangeSafly(QString usernam, QString NewBirthday)
{
    {
        QFile file("Personal/" + usernam + ".json");
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
                        if(jsonObj.value("Username").toString()==usernam)
                        {
                            file.close();
                            QFile::remove("Personal/" + usernam);
                            if(file.open(QIODevice::WriteOnly))
                            {
                                jsonObj["Birthday"] = NewBirthday;
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
        QFile file("Organisation/" + usernam + ".json");
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
                        if(jsonObj.value("Username").toString()==usernam)
                        {
                            file.close();
                            QFile::remove("Organisation/" + usernam);
                            if(file.open(QIODevice::WriteOnly))
                            {
                                jsonObj["Birthday"] = NewBirthday;
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
        QFile file("Anonymous/" + usernam + ".json");
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
                        if(jsonObj.value("Username").toString()==usernam)
                        {
                            file.close();
                            QFile::remove("Anonymous/" + usernam);
                            if(file.open(QIODevice::WriteOnly))
                            {
                                jsonObj["Birthday"] = NewBirthday;
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

void PersonalAccount::ChangeCountryPersonalAccountWithUsernameAndPasswordChangeSafly(QString username, QString newCountry)
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
                                jsonObj["Country"] = newCountry;
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
                                jsonObj["Country"] = newCountry;
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
                                jsonObj["Country"] = newCountry;
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

int PersonalAccount::GetTweetLikePersonalAccountWithTweetID(QString tweetID)
{
    int total = 0;
    QFile file("Tweet/Like.json");
    try
    {
        if(file.exists())
        {
            if (file.open(QIODevice::ReadOnly))
            {
                QByteArray fileData = file.readAll();

                QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData);

                if (jsonDoc.isArray())
                {
                    QJsonArray jsonArray = jsonDoc.array();

                    for (const auto& jsonValue : jsonArray)
                    {
                        if (jsonValue.isObject())
                        {
                            QJsonObject jsonObj = jsonValue.toObject();
                            QString username = jsonObj.value("Username").toString();
                            QString usernameLike = jsonObj.value("UsernameLike").toString();
                            QString tweetId = jsonObj.value("TweetID").toString();
                            int likeCounter;
                            if(jsonObj.value("TweetLike").toString()=="")
                            {
                                likeCounter = 0;
                            }
                            else
                            {
                                likeCounter = jsonObj.value("TweetLike").toInt();
                            }
                            if(tweetID == tweetId)
                            {
                                total++;
                            }

                        }
                    }
                }
            }

            file.close();
        }
        if(!file.exists())
        {
            return 0;
        }
        if(file.error())
        {
            file.close();
            throw std::invalid_argument("invalid file path");
        }
    }
    catch(std::exception &e)
    {
        QMessageBox::critical(nullptr,e.what(),"There was a problem, please try again");
    }
    qDebug()<<"Total = "<<total<<"\n";
    return total;
}

void PersonalAccount::ChangeUsernamePersonalAccountWithUsernameAndPasswordChangeSafly(QString oldUsername, QString newUsername)
{
    {
        QFile file("Personal/" + oldUsername + ".json");
        if (file.exists()) {
            try {
                if (file.open(QIODevice::ReadOnly)) {
                    QByteArray jsonData = file.readAll();
                    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
                    if (jsonDoc.isNull()) {
                        throw std::invalid_argument("not exist");
                    } else {
                        QJsonObject jsonObj = jsonDoc.object();
                        if (jsonObj.value("Username").toString() == oldUsername) {
                            file.close();
                            QString newFilePath = "Personal/" + newUsername + ".json";
                            if (QFile::rename("Personal/" + oldUsername + ".json", newFilePath)) {
                                QFile newFile(newFilePath);
                                if (newFile.open(QIODevice::WriteOnly)) {
                                    jsonObj["Username"] = newUsername;
                                    QJsonDocument jDoc(jsonObj);
                                    QByteArray jData = jDoc.toJson();
                                    newFile.write(jData);
                                    newFile.close();
                                    qDebug() << "rename successfully" << "\n";
                                } else {
                                    qDebug() << "Failed to open new file for writing" << "\n";
                                }
                            } else {
                                qDebug() << "rename not successful" << "\n";
                            }
                        }
                    }
                } else {
                    throw std::invalid_argument("file not found");
                }
            } catch (std::exception& e) {
                QMessageBox::critical(this, "Error", e.what());
            }
            file.close();
        }
    }
    //***************************************************
    {
        QFile file("Organisation/" + oldUsername + ".json");
        if (file.exists()) {
            try {
                if (file.open(QIODevice::ReadOnly)) {
                    QByteArray jsonData = file.readAll();
                    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
                    if (jsonDoc.isNull()) {
                        throw std::invalid_argument("not exist");
                    } else {
                        QJsonObject jsonObj = jsonDoc.object();
                        if (jsonObj.value("Username").toString() == oldUsername) {
                            file.close();
                            QString newFilePath = "Organisation/" + newUsername + ".json";
                            if (QFile::rename("Organisation/" + oldUsername + ".json", newFilePath)) {
                                QFile newFile(newFilePath);
                                if (newFile.open(QIODevice::WriteOnly)) {
                                    jsonObj["Username"] = newUsername;
                                    QJsonDocument jDoc(jsonObj);
                                    QByteArray jData = jDoc.toJson();
                                    newFile.write(jData);
                                    newFile.close();
                                    qDebug() << "rename successfully" << "\n";
                                } else {
                                    qDebug() << "Failed to open new file for writing" << "\n";
                                }
                            } else {
                                qDebug() << "rename not successful" << "\n";
                            }
                        }
                    }
                } else {
                    throw std::invalid_argument("file not found");
                }
            } catch (std::exception& e) {
                QMessageBox::critical(this, "Error", e.what());
            }
            file.close();
        }
    }
    //**************************************************************
    {
        QFile file("Anonymous/" + oldUsername + ".json");
        if (file.exists()) {
            try {
                if (file.open(QIODevice::ReadOnly)) {
                    QByteArray jsonData = file.readAll();
                    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
                    if (jsonDoc.isNull()) {
                        throw std::invalid_argument("not exist");
                    } else {
                        QJsonObject jsonObj = jsonDoc.object();
                        if (jsonObj.value("Username").toString() == oldUsername) {
                            file.close();
                            QString newFilePath = "Anonymous/" + newUsername + ".json";
                            if (QFile::rename("Anonymous/" + oldUsername + ".json", newFilePath)) {
                                QFile newFile(newFilePath);
                                if (newFile.open(QIODevice::WriteOnly)) {
                                    jsonObj["Username"] = newUsername;
                                    QJsonDocument jDoc(jsonObj);
                                    QByteArray jData = jDoc.toJson();
                                    newFile.write(jData);
                                    newFile.close();
                                    qDebug() << "rename successfully" << "\n";
                                } else {
                                    qDebug() << "Failed to open new file for writing" << "\n";
                                }
                            } else {
                                qDebug() << "rename not successful" << "\n";
                            }
                        }
                    }
                } else {
                    throw std::invalid_argument("file not found");
                }
            } catch (std::exception& e) {
                QMessageBox::critical(this, "Error", e.what());
            }
            file.close();
        }
    }
}

void PersonalAccount::ChangePasswordPersonalAccountWithUsernameAndPasswordChangeSafly(QString oldPassword, QString NewPassword, QString usernameAccount)
{
    {
        QFile file("Personal/" + usernameAccount + ".json");
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
                        if(jsonObj.value("Username").toString()==usernameAccount)
                        {
                            file.close();
                            QFile::remove("Personal/" + usernameAccount);
                            if(file.open(QIODevice::WriteOnly))
                            {
                                jsonObj["Password"] = NewPassword;
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
        QFile file("Organisation/" + usernameAccount + ".json");
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
                        if(jsonObj.value("Username").toString()==usernameAccount)
                        {
                            file.close();
                            QFile::remove("Organisation/" + usernameAccount);
                            if(file.open(QIODevice::WriteOnly))
                            {
                                jsonObj["Password"] = NewPassword;
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
        QFile file("Anonymous/" + usernameAccount + ".json");
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
                        if(jsonObj.value("Username").toString()==usernameAccount)
                        {
                            file.close();
                            QFile::remove("Anonymous/" + usernameAccount);
                            if(file.open(QIODevice::WriteOnly))
                            {
                                jsonObj["Password"] = NewPassword;
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
    QFile Personalfile("Personal/" + Username + ".json");
    if(Personalfile.exists())
    {
        ui->SettingListWidget->clear();
        QListWidgetItem* item1 = new QListWidgetItem("Logout");
        QListWidgetItem* item2 = new QListWidgetItem("Adjust profile");
        QListWidgetItem* item3 = new QListWidgetItem("Adjust Biography");
        QListWidgetItem* item4 = new QListWidgetItem("Change username");
        QListWidgetItem* item5 = new QListWidgetItem("Change Phone number");
        QListWidgetItem* item6 = new QListWidgetItem("Show my profile");
        QListWidgetItem* item7 = new QListWidgetItem("Change name");
        QListWidgetItem* item8 = new QListWidgetItem("change birthday");
        QListWidgetItem* item9 = new QListWidgetItem("change Country");
        QListWidgetItem* item10 = new QListWidgetItem("Show All HashTAG");
        QListWidgetItem* item11 = new QListWidgetItem("Change Password");
        QListWidgetItem* item12 = new QListWidgetItem("Delete Tweet");
        QColor grrenBright(0,155,160);
        QColor skyColor(135, 100, 170);

        item1->setBackground(QBrush(skyColor));
        item2->setBackground(QBrush(skyColor));
        item3->setBackground(QBrush(skyColor));
        item4->setBackground(QBrush(skyColor));
        item5->setBackground(QBrush(skyColor));
        item6->setBackground(QBrush(grrenBright));
        item7->setBackground(QBrush(grrenBright));
        item8->setBackground(QBrush(grrenBright));
        item9->setBackground(QBrush(grrenBright));
        item10->setBackground(QBrush("red"));
        item11->setBackground(QBrush("blue"));
        item12->setBackground(QBrush("purple"));

        ui->SettingListWidget->addItem(item1);
        ui->SettingListWidget->addItem(item2);
        ui->SettingListWidget->addItem(item3);
        ui->SettingListWidget->addItem(item4);
        ui->SettingListWidget->addItem(item5);
        ui->SettingListWidget->addItem(item6);
        ui->SettingListWidget->addItem(item7);
        ui->SettingListWidget->addItem(item8);
        ui->SettingListWidget->addItem(item9);
        ui->SettingListWidget->addItem(item10);
        ui->SettingListWidget->addItem(item11);
        ui->SettingListWidget->addItem(item12);
        return;
    }

     QFile Organisationfile("Organisation/" + Username + ".json");
     if(Organisationfile.exists())
     {
         ui->SettingListWidget->clear();
         QListWidgetItem* item1 = new QListWidgetItem("Logout");
         QListWidgetItem* item3 = new QListWidgetItem("Adjust Biography");
         QListWidgetItem* item4 = new QListWidgetItem("Change username");
         QListWidgetItem* item5 = new QListWidgetItem("Change Password");
         QListWidgetItem* item6 = new QListWidgetItem("Show my profile");
         QListWidgetItem* item7 = new QListWidgetItem("Delete Tweet");

         QColor grrenBright(0,155,160);
         QColor skyColor(135, 100, 170);
         item1->setBackground(QBrush(skyColor));
         item3->setBackground(QBrush(skyColor));
         item4->setBackground(QBrush(skyColor));
         item5->setBackground(QBrush(skyColor));
         item6->setBackground(QBrush(grrenBright));
         item7->setBackground(QBrush(grrenBright));

         ui->SettingListWidget->addItem(item1);
         ui->SettingListWidget->addItem(item3);
         ui->SettingListWidget->addItem(item4);
         ui->SettingListWidget->addItem(item5);
         ui->SettingListWidget->addItem(item6);
         ui->SettingListWidget->addItem(item7);
         return;
     }

     QFile Anonymousfile("Anonymous/" + Username + ".json");
     if(Anonymousfile.exists())
     {
         ui->SettingListWidget->clear();
         QListWidgetItem* item1 = new QListWidgetItem("Logout");
         QListWidgetItem* item3 = new QListWidgetItem("Adjust Biography");
         QListWidgetItem* item4 = new QListWidgetItem("Change username");
         QListWidgetItem* item5 = new QListWidgetItem("Change Password");
         QListWidgetItem* item6 = new QListWidgetItem("Show my profile");
         QListWidgetItem* item7 = new QListWidgetItem("Delete Tweet");

         QColor grrenBright(0,155,160);
         QColor skyColor(135, 100, 170);
         item1->setBackground(QBrush(skyColor));
         item3->setBackground(QBrush(skyColor));
         item4->setBackground(QBrush(skyColor));
         item5->setBackground(QBrush(skyColor));
         item6->setBackground(QBrush(grrenBright));
         item7->setBackground(QBrush(skyColor));

         ui->SettingListWidget->addItem(item1);
         ui->SettingListWidget->addItem(item3);
         ui->SettingListWidget->addItem(item4);
         ui->SettingListWidget->addItem(item5);
         ui->SettingListWidget->addItem(item6);
         ui->SettingListWidget->addItem(item7);
         return;
     }

}

void PersonalAccount::on_SearchLineEdit_textChanged(const QString &arg1)
{
    SearchHashtag(arg1);
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
       if(itemArgument->text()=="Change username")
       {
           ui->FindHashtagOrUsernameListWidget->clear();
           QTextEdit* textEdit = new QTextEdit(ui->FindHashtagOrUsernameListWidget);
           textEdit->setFixedSize(ui->FindHashtagOrUsernameListWidget->size()/3);
           textEdit->show();
           ui->SearchLabel->setText("Enter new Username");
           ui->SearchLineEdit->hide();
           ui->TweetButton->hide();
           ui->BiogrphyButton->setText("Accept");
           ui->BiogrphyButton->setStyleSheet("color : green");
           ui->BiogrphyButton->show();

           {
               connect(ui->BiogrphyButton,&QPushButton::clicked,[=]()
               {
                   ChangeUsernamePersonalAccountWithUsernameAndPasswordChangeSafly(Username,textEdit->toPlainText());
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
       }
       if(itemArgument->text()=="Change Password")
       {
           ui->FindHashtagOrUsernameListWidget->clear();
           QTextEdit* textEdit = new QTextEdit(ui->FindHashtagOrUsernameListWidget);
           textEdit->setFixedSize(ui->FindHashtagOrUsernameListWidget->size()/3);
           textEdit->show();
           ui->SearchLabel->setText("Enter new Password");
           ui->SearchLineEdit->hide();
           ui->TweetButton->hide();
           ui->BiogrphyButton->setText("Accept");
           ui->BiogrphyButton->setStyleSheet("color : green");
           ui->BiogrphyButton->show();
           {
               connect(ui->BiogrphyButton,&QPushButton::clicked,[=]()
               {
                   ChangePasswordPersonalAccountWithUsernameAndPasswordChangeSafly("",textEdit->toPlainText(),Username);
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

       }
       if(itemArgument->text() == "Delete Tweet")
       {
            DeleteTweet();
       }

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
            Logout();
       }
       if(itemArgument->text() == "Change name")
       {
           ui->FindHashtagOrUsernameListWidget->clear();
           QTextEdit* textEdit = new QTextEdit(ui->FindHashtagOrUsernameListWidget);
           textEdit->setFixedSize(ui->FindHashtagOrUsernameListWidget->size()/3);
           textEdit->show();
           ui->SearchLabel->setText("Enter new name");
           ui->SearchLineEdit->hide();
           ui->TweetButton->hide();
           ui->BiogrphyButton->setText("Accept");
           ui->BiogrphyButton->setStyleSheet("color : green");
           ui->BiogrphyButton->show();

           connect(ui->BiogrphyButton,&QPushButton::clicked,[=]()
           {
            ChnageNamePersonalAccountWithUsernameAndPasswordChangeSafly(Username,textEdit->toPlainText());
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
       if(itemArgument->text() == "change birthday")
       {
           ui->FindHashtagOrUsernameListWidget->clear();
           QTextEdit* textEdit = new QTextEdit(ui->FindHashtagOrUsernameListWidget);
           textEdit->setFixedSize(ui->FindHashtagOrUsernameListWidget->size()/3);
           textEdit->show();
           ui->SearchLabel->setText("Enter new Birthday");
           ui->SearchLineEdit->hide();
           ui->TweetButton->hide();
           ui->BiogrphyButton->setText("Accept");
           ui->BiogrphyButton->setStyleSheet("color : green");
           ui->BiogrphyButton->show();

           connect(ui->BiogrphyButton,&QPushButton::clicked,[=]()
           {
            ChangeBirthdayPersonalAccountWithUsernameAndPasswordChangeSafly(Username,textEdit->toPlainText());
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
       if(itemArgument->text() == "change Country")
       {
           ui->FindHashtagOrUsernameListWidget->clear();
           QTextEdit* textEdit = new QTextEdit(ui->FindHashtagOrUsernameListWidget);
           textEdit->setFixedSize(ui->FindHashtagOrUsernameListWidget->size()/3);
           textEdit->show();
           ui->SearchLabel->setText("Enter new Country");
           ui->SearchLineEdit->hide();
           ui->TweetButton->hide();
           ui->BiogrphyButton->setText("Accept");
           ui->BiogrphyButton->setStyleSheet("color : green");
           ui->BiogrphyButton->show();

           connect(ui->BiogrphyButton,&QPushButton::clicked,[=]()
           {
            ChangeCountryPersonalAccountWithUsernameAndPasswordChangeSafly(Username,textEdit->toPlainText());
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
       if(itemArgument->text() == "Show All HashTAG")
       {

       }




    } catch (std::exception& e)
    {
        QMessageBox::critical(this,"Error",e.what());
    }

}

void PersonalAccount::MentionButtonTweet(QString usernameNAME, QString username, QString tweetid,QString mentionMessage)
{
    MentionClasses M;
    M.SetMentionIDMentionClasses(tweetid);
    M.SetUsernameNAMEMentionClasses(usernameNAME);
    M.SetUsernameSendMentionMentionClasses(username);
    M.SetMentionMessageMentionClasses(mentionMessage);
    M.SetAttributeMentionClasses();



}

void PersonalAccount::LikeButtonTweet(QString tweetid,QString tweetUsername)
{
    Tweet t;
    t.AddُTheNumberOfLikesToTweet(Username,tweetid,tweetUsername);
    qDebug()<<"Tweet like counter : "<< t.GetTweetLikeCounter(tweetid)<<"\n";

}

void PersonalAccount::FollowerButtonAccount(QString FollowedAccount, QString FollowerAccount)
{
    FollowersClasses F;
    if(F.IsUserCanFollower(FollowedAccount) == true)
    {
        F.SetFollowersClassesFollowedAccount(FollowedAccount);
        F.SetFollowersClassesFollowerAccount(FollowerAccount);
        F.SetAttributeFollowersClasses();

        qDebug()<<"FollowersClasses counter = " << F.GetFollowerClassFollowedAccount(Username)<<"\n";

            {
                QFile file("Personal/" + Username + ".json");
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
                                if(jsonObj.value("Username").toString()==Username)
                                {
                                    file.close();
                                    QFile::remove("Personal/" + Username);
                                    if(file.open(QIODevice::WriteOnly))
                                    {
                                        int temp1 = std::stoi(jsonObj["Followings"].toString().toStdString());
                                        temp1 = temp1 + 1;
//                                        qDebug()<<"Temp1"<<temp1<<"\n";
                                        jsonObj["Followings"] = QString::fromStdString(std::to_string(temp1));
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
                QFile file("Organisation/" + Username + ".json");
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
                                if(jsonObj.value("Username").toString()==Username)
                                {
                                    file.close();
                                    QFile::remove("Organisation/" + Username);
                                    if(file.open(QIODevice::WriteOnly))
                                    {
                                        int temp1 = std::stoi(jsonObj["Followings"].toString().toStdString());
                                        temp1 = temp1 + 1;
                                        jsonObj["Followings"] = QString::fromStdString(std::to_string(temp1));
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



}

void PersonalAccount::on_FollowersButton_clicked()
{
    ui->listWidget->clear();
    FollowersClasses F;
    for(auto followed : F.GetFollowedClassFollowedAccount(Username))
    {
        QListWidgetItem* item = new QListWidgetItem(followed);
        item->setBackground(QBrush("blue"));
        ui->listWidget->addItem(item);
    }
    connect(ui->listWidget,&QListWidget::itemClicked,this,&PersonalAccount::ShowAllTweetWithFollowerAccountUsername);
}

void PersonalAccount::ShowAllTweetWithFollowerAccountUsername(QListWidgetItem *item)
{
    QListWidget* widgetTEMP = new QListWidget(ui->listWidget);
    QWidget* customWidget = new QWidget();
    QPushButton* BackButton = new QPushButton("Back");
    QHBoxLayout* layout = new QHBoxLayout(customWidget);
    layout->addWidget(BackButton);
    layout->setAlignment(Qt::AlignCenter);
    customWidget->setLayout(layout);
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
                QListWidgetItem* itemList = new QListWidgetItem(temp);
                itemList->setBackground(Qt::red);
                if(temp==item->text())
                {
                    ui->listWidget->addItem(itemList);
                    {
                        QFile jsonFile("Personal/"+item->text()+".json");
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
                        QListWidgetItem* item3 = new QListWidgetItem();
                        QListWidgetItem* item4 = new QListWidgetItem();
                        QListWidgetItem* item5 = new QListWidgetItem();
                        QListWidgetItem* item6 = new QListWidgetItem();
                        QListWidgetItem* item7 = new QListWidgetItem();
                        QListWidgetItem* item8 = new QListWidgetItem();
                        QListWidgetItem* item9 = new QListWidgetItem();
                        QListWidgetItem* item10 = new QListWidgetItem();

                        item1->setText("Username : " + username);
                        item3->setText("PhoneNumber : " + phoneNumber);
                        item4->setText("name : " + name);
                        item5->setText("Country : " + country);
                        item6->setText("Followers : " + followers);
                        item7->setText("Followings : " + followings);
                        item8->setText("Birthday : " + birthday);
                        item9->setText("Biography : " + biography);
                        widgetTEMP->addItem(item1);
                        widgetTEMP->addItem(item3);
                        widgetTEMP->addItem(item4);
                        widgetTEMP->addItem(item5);
                        widgetTEMP->addItem(item6);
                        widgetTEMP->addItem(item7);
                        widgetTEMP->addItem(item8);
                        widgetTEMP->addItem(item9);
                        item10->setSizeHint(customWidget->sizeHint());
                        widgetTEMP->addItem(item10);
                        widgetTEMP->setItemWidget(item10, customWidget);
                        widgetTEMP->setFixedSize(ui->listWidget->size());
                        widgetTEMP->show();
                        connect(BackButton,&QPushButton::clicked,[=]()
                        {
                            widgetTEMP->close();
                            on_FollowingsButton_clicked();
                        });
                    }

//                    return;
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
                QListWidgetItem* itemList = new QListWidgetItem(temp);
                itemList->setBackground(Qt::red);
                if(temp==item->text())
                {
                    ui->listWidget->addItem(itemList);
                    {
                        QFile jsonFile("Organisation/"+item->text()+".json");
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
                        widgetTEMP->addItem(item1);
                        widgetTEMP->addItem(item2);
                        widgetTEMP->addItem(item3);
                        widgetTEMP->addItem(item9);
                        widgetTEMP->setFixedSize(ui->listWidget->size());
                        widgetTEMP->show();

                    }

//                    return;
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
                        QListWidgetItem* itemList = new QListWidgetItem(temp);
                        itemList->setBackground(Qt::red);
                        if(temp==item->text())
                        {
                            ui->listWidget->addItem(itemList);
                            {
                                QFile jsonFile("Anonymous/"+item->text()+".json");
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
                                QString username = jsonObj["Username"].toString();
                                QString name = jsonObj["Name"].toString();
                                QListWidgetItem* item1 = new QListWidgetItem();
                                QListWidgetItem* item4 = new QListWidgetItem();
                                item1->setText("Username : " + username);
                                item4->setText("Name : " + name);
                                widgetTEMP->addItem(item1);
                                widgetTEMP->addItem(item4);
                                widgetTEMP->setFixedSize(ui->listWidget->size());
                                widgetTEMP->show();
                            }

//                            return;
                    }
                }
            }
    }


//    qDebug()<<item->text() + " ShowAllTweetWithFollowerAccountUsername"<<"\n";
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
                    if(username == item->text())
                    {
                        QString message = obj.value("Message").toString();
                        QString hashtag = obj.value("#").toString();
                        QString name = obj.value("Name").toString();
                        QString tweetID = obj.value("TweetID").toString();
                        QString likeTweet = obj.value("Like").toString();
                        {
                            likeTweet = QString::fromStdString(std::to_string(GetTweetLikePersonalAccountWithTweetID(tweetID)));
                        }

                        // Create a new widget item for the text and button
                        QWidget *widgetItem = new QWidget(ui->FindHashtagOrUsernameListWidget);

                        // Create a label for the text
                        QLabel *textLabel = new QLabel(name + "  @" + username + "\nMessage : " + message + "\n Hashtag : " + hashtag + "\n", widgetItem);

                        // Create the button
                        QPushButton *likeButton = new QPushButton("Like", widgetItem);
                        QPushButton *mentionButton = new QPushButton("Mention",widgetItem);
                        QPushButton *UnfollowButton = new QPushButton("Unfollow",widgetItem);

                        likeButton->setStyleSheet("color : green");
                        mentionButton->setStyleSheet("color : purple");
                        UnfollowButton->setStyleSheet("color : blue");

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
                        layout->addWidget(UnfollowButton);
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
                                LikeButtonTweet(tweetID,username);
                                // Handle the button click here
                            });
                            //                        connect(mentionButton,&QPushButton::clicked,this,&PersonalAccount::onButtonClicked);
                            connect(mentionButton,&QPushButton::clicked,[=]()
                            {
                                MentionButtonTweet(Name,Username,tweetID,"");
                            });
                            //                        connect(FollowButton,&QPushButton::clicked,this,&PersonalAccount::onButtonClicked);
                            connect(UnfollowButton,&QPushButton::clicked,[=]()
                            {
                                DeleteFollower(username,Username);
                            });
                        }
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

void PersonalAccount::on_FollowingsButton_clicked()
{
    ui->listWidget->clear();
    FollowersClasses F;
    for(auto follower : F.GetFollowersClassesFollowedAccount(Username))
    {
        QListWidgetItem* item = new QListWidgetItem(follower);
        ui->listWidget->addItem(item);
    }
    connect(ui->listWidget,&QListWidget::itemClicked,this,&PersonalAccount::ShowAllTweetWithFollowerAccountUsername);

}

void PersonalAccount::BackgroundTweetClicked(QString tweetID)
{
    ui->FindHashtagOrUsernameListWidget->clear();
    MentionClasses m;
    for (auto mention : m.GetMentionClasses())
    {
        if (tweetID == mention.value("MentionID").toString())
        {
            QString itemString = mention.value("UsernameSendMention").toString() + "  @" + mention.value("UsernameNAME").toString() + "\n" + mention.value("MentionMessage").toString();
            itemString += "\n" +  mention.value("Current Date").toString() + " , " + mention.value("Current Time").toString();
            QListWidgetItem* item = new QListWidgetItem(itemString);
            ui->FindHashtagOrUsernameListWidget->addItem(item);
        }
    }

    QPushButton* backButton = new QPushButton();
    backButton->setText("Back");
    backButton->setFont(QFont("Arial", 24));
    backButton->setStyleSheet("color : blue");
    QListWidgetItem* backItem = new QListWidgetItem();
    backItem->setSizeHint(backButton->sizeHint());
    ui->FindHashtagOrUsernameListWidget->addItem(backItem);
    ui->FindHashtagOrUsernameListWidget->setItemWidget(backItem, backButton);
    connect(backButton, &QPushButton::clicked, [=]() {
        on_SearchLineEdit_textChanged("");
    });


}

void PersonalAccount::ItemClickedExpelor()
{
    QFile temp("Tweet/Tweet1.json");
    if (temp.exists())
    {
        QFile::remove("Tweet/Tweet.json");
        QFile::rename("Tweet/Tweet1.json", "Tweet/Tweet.json");
    }

    ui->FindHashtagOrUsernameListWidget->clear();
    QFile file("Tweet/Tweet.json");
    try
    {
        if (file.open(QIODevice::ReadOnly))
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
                    {
                        likeTweet = QString::fromStdString(std::to_string(GetTweetLikePersonalAccountWithTweetID(tweetID)));
                    }
                    QString currentDate = obj.value("Current Date").toString();
                    QString currentTime = obj.value("Current Time").toString();

                    // Create a new widget item for the text and button
                    QWidget *widgetItem = new QWidget(ui->FindHashtagOrUsernameListWidget);

                    // Create a label for the text
                    QLabel *textLabel = new QLabel(name + "  @" + username + "\nMessage : " + message + "\n Hashtag : " + hashtag + "\n" +
                    currentDate + " , " + currentTime + "\n", widgetItem);

                    // Create the buttons
                    QPushButton *likeButton = new QPushButton("Like", widgetItem);
                    QPushButton *mentionButton = new QPushButton("Mention sent", widgetItem);
                    QPushButton *followButton = new QPushButton("Follow", widgetItem);
                    QPushButton *ShowMention = new QPushButton("Show Mention",widgetItem);

                    likeButton->setStyleSheet("color : green");
                    mentionButton->setStyleSheet("color : purple");
                    followButton->setStyleSheet("color : blue");
                    ShowMention->setStyleSheet("color : red");

                    // Create a label for the button and text
                    QLabel *likeLabel = new QLabel();
                    likeLabel->setFixedSize(likeButton->size());
                    likeLabel->setText(likeTweet + " Likes ❤️");

                    // Create a LineEdit for the button and text
                    QLineEdit *mentionLineEdit = new QLineEdit();
                    mentionLineEdit->setStyleSheet("color: rgb(150, 150, 150)");
                    mentionLineEdit->setFixedWidth(725);
                    mentionLineEdit->setFixedHeight(40);
                    mentionLineEdit->setToolTip("mention");

                    // Create an object of the QFont class to set the text font
                    QFont font("Arial", 11);
                    likeLabel->setFont(font);

                    likeLabel->setStyleSheet("color : red");

                    // Create a horizontal layout for the buttons
                    QHBoxLayout *buttonLayout = new QHBoxLayout();
                    buttonLayout->addWidget(likeButton);
                    buttonLayout->addWidget(mentionButton);
                    buttonLayout->addWidget(followButton);
                    buttonLayout->addWidget(ShowMention);

                    // Create a vertical layout for the label, buttons, and line edit
                    QVBoxLayout *verticalLayout = new QVBoxLayout();
                    verticalLayout->addWidget(textLabel);
                    verticalLayout->addWidget(likeLabel);
                    verticalLayout->addLayout(buttonLayout);
                    verticalLayout->addWidget(mentionLineEdit);
                    widgetItem->setLayout(verticalLayout);

                    // Create a new item for the widget
                    QListWidgetItem *item = new QListWidgetItem(ui->FindHashtagOrUsernameListWidget);
                    item->setSizeHint(widgetItem->sizeHint()); // Set the size hint for the item to match the size of the widget

                    // Set the widget as the item widget
                    ui->FindHashtagOrUsernameListWidget->setItemWidget(item, widgetItem);

                    ui->FindHashtagOrUsernameListWidget->setStyleSheet("color : darkblue");

                    // button signal and slot (test)
                    {
                        connect(likeButton, &QPushButton::clicked, [=]() {
                            LikeButtonTweet(tweetID, username);
                            // Handle the button click here
                        });
                        connect(mentionButton, &QPushButton::clicked, [=]() {
                            MentionButtonTweet(Name,Username,tweetID,mentionLineEdit->text());
                            mentionLineEdit->clear();
                        });
                        connect(followButton, &QPushButton::clicked, [=]() {
                            FollowerButtonAccount(username, Username);
                        });
                        connect(ShowMention,&QPushButton::clicked, [=]() {
                            BackgroundTweetClicked(tweetID);
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
    catch (std::exception &e)
    {
        QMessageBox::critical(nullptr, e.what(), "There was a problem, please try again");
    }

}

void PersonalAccount::DeleteTweet()
{
    QListWidget* widgetTEMP = new QListWidget(ui->listWidget);
    QWidget* customWidget = new QWidget();
    QPushButton* BackButton = new QPushButton("Back");
    QHBoxLayout* layout = new QHBoxLayout(customWidget);
    layout->addWidget(BackButton);
    layout->setAlignment(Qt::AlignCenter);
    customWidget->setLayout(layout);

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
                    if(username == Username)
                    {
                        QString message = obj.value("Message").toString();
                        QString hashtag = obj.value("#").toString();
                        QString name = obj.value("Name").toString();
                        QString tweetID = obj.value("TweetID").toString();
                        QString likeTweet = obj.value("Like").toString();
                        {
                            likeTweet = QString::fromStdString(std::to_string(GetTweetLikePersonalAccountWithTweetID(tweetID)));
                        }

                        // Create a new widget item for the text and button
                        QWidget *widgetItem = new QWidget(ui->FindHashtagOrUsernameListWidget);

                        // Create a label for the text
                        QLabel *textLabel = new QLabel(name + "  @" + username + "\nMessage : " + message + "\n Hashtag : " + hashtag + "\n", widgetItem);

                        // Create the button
                        QPushButton *DeleteButton = new QPushButton("Delete", widgetItem);

                        DeleteButton->setStyleSheet("color : green");

                        // Create a label for the button and text
                        QLabel* likeLabel = new QLabel();
                        likeLabel->setFixedSize(DeleteButton->size());
                        likeLabel->setText(likeTweet + " Likes ❤️");

                        // Create an object of the QFont class to set the text font
                        QFont font("Arial", 11);
                        likeLabel->setFont(font);

                        likeLabel->setStyleSheet("color : red");

                        // Create a horizontal layout for the button and text
                        QHBoxLayout *layout = new QHBoxLayout();
                        layout->addWidget(textLabel);
                        layout->addStretch(); // Add a stretchable space between the label and button
                        layout->addWidget(DeleteButton);
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

                            connect(DeleteButton, &QPushButton::clicked, [=]()
                            {
                               // Handle the button click here
                                Tweet t;
                                if(t.DeleteTweet(tweetID))
                                {
                                    QMessageBox::information(this,"Delete Message","* remove successfully");
                                }
                                else
                                {
                                    QMessageBox::critical(nullptr,"Error","! remove not successfully");
                                }
                            });

                        }
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

void PersonalAccount::DeleteFollower(QString followerusername,QString username)
{
    qDebug()<<"DeleteFollower = "<<followerusername<<"\n";
    // Load the JSON file
        QFile file("Follower/Follower.json");
        if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
        {
            qDebug() << "Failed to open the JSON file.";

        }

        // Parse the JSON document
        QByteArray jsonData = file.readAll();
        QJsonParseError jsonError;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &jsonError);
        if (jsonError.error != QJsonParseError::NoError)
        {
            qDebug() << "Failed to parse the JSON document:" << jsonError.errorString();
            file.close();

        }

        // Get the root array of the JSON document
        QJsonArray rootArray = jsonDoc.array();

        // Find and remove the object with the specified TweetID
        for (int i = 0; i < rootArray.size(); ++i)
        {
            QJsonObject jsonObject = rootArray.at(i).toObject();
            if (jsonObject.value("FollowedAccount").toString() == followerusername && jsonObject.value("FollowerAccount").toString()==username)
            {
                rootArray.removeAt(i);
                break;
            }
        }

        // Update the JSON document
        jsonDoc.setArray(rootArray);

        // Clear the file content
        file.resize(0);

        // Write the modified JSON document back to the file
        file.write(jsonDoc.toJson());
        file.close();

        qDebug() << "Object removed successfully.";
}

void PersonalAccount::SearchHashtag(QString arg)
{
    QFile temp("Tweet/Tweet1.json");
    if (temp.exists())
    {
        QFile::remove("Tweet/Tweet.json");
        QFile::rename("Tweet/Tweet1.json", "Tweet/Tweet.json");
    }

    ui->FindHashtagOrUsernameListWidget->clear();
    QFile file("Tweet/Tweet.json");
    try
    {
        if (file.open(QIODevice::ReadOnly))
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
                    if(hashtag.contains(arg )){
                        QString name = obj.value("Name").toString();
                        QString tweetID = obj.value("TweetID").toString();
                        QString likeTweet = obj.value("Like").toString();
                        {
                            likeTweet = QString::fromStdString(std::to_string(GetTweetLikePersonalAccountWithTweetID(tweetID)));
                        }
                        QString currentDate = obj.value("Current Date").toString();
                        QString currentTime = obj.value("Current Time").toString();

                        // Create a new widget item for the text and button
                        QWidget *widgetItem = new QWidget(ui->FindHashtagOrUsernameListWidget);

                        // Create a label for the text
                        QLabel *textLabel = new QLabel(name + "  @" + username + "\nMessage : " + message + "\n Hashtag : " + hashtag + "\n" +
                                                       currentDate + " , " + currentTime + "\n", widgetItem);

                        // Create the buttons
                        QPushButton *likeButton = new QPushButton("Like", widgetItem);
                        QPushButton *mentionButton = new QPushButton("Mention sent", widgetItem);
                        QPushButton *followButton = new QPushButton("Follow", widgetItem);
                        QPushButton *ShowMention = new QPushButton("Show Mention",widgetItem);

                        likeButton->setStyleSheet("color : green");
                        mentionButton->setStyleSheet("color : purple");
                        followButton->setStyleSheet("color : blue");
                        ShowMention->setStyleSheet("color : red");

                        // Create a label for the button and text
                        QLabel *likeLabel = new QLabel();
                        likeLabel->setFixedSize(likeButton->size());
                        likeLabel->setText(likeTweet + " Likes ❤️");

                        // Create a LineEdit for the button and text
                        QLineEdit *mentionLineEdit = new QLineEdit();
                        mentionLineEdit->setStyleSheet("color: rgb(150, 150, 150)");
                        mentionLineEdit->setFixedWidth(725);
                        mentionLineEdit->setFixedHeight(40);
                        mentionLineEdit->setToolTip("mention");

                        // Create an object of the QFont class to set the text font
                        QFont font("Arial", 11);
                        likeLabel->setFont(font);

                        likeLabel->setStyleSheet("color : red");

                        // Create a horizontal layout for the buttons
                        QHBoxLayout *buttonLayout = new QHBoxLayout();
                        buttonLayout->addWidget(likeButton);
                        buttonLayout->addWidget(mentionButton);
                        buttonLayout->addWidget(followButton);
                        buttonLayout->addWidget(ShowMention);

                        // Create a vertical layout for the label, buttons, and line edit
                        QVBoxLayout *verticalLayout = new QVBoxLayout();
                        verticalLayout->addWidget(textLabel);
                        verticalLayout->addWidget(likeLabel);
                        verticalLayout->addLayout(buttonLayout);
                        verticalLayout->addWidget(mentionLineEdit);
                        widgetItem->setLayout(verticalLayout);

                        // Create a new item for the widget
                        QListWidgetItem *item = new QListWidgetItem(ui->FindHashtagOrUsernameListWidget);
                        item->setSizeHint(widgetItem->sizeHint()); // Set the size hint for the item to match the size of the widget
                        item->setBackground(QBrush("lightgreen"));
                        // Set the widget as the item widget
                        ui->FindHashtagOrUsernameListWidget->setItemWidget(item, widgetItem);

                        ui->FindHashtagOrUsernameListWidget->setStyleSheet("color : darkblue");

                        // button signal and slot (test)
                        {
                            connect(likeButton, &QPushButton::clicked, [=]() {
                                LikeButtonTweet(tweetID, username);
                                // Handle the button click here
                            });
                            connect(mentionButton, &QPushButton::clicked, [=]() {
                                MentionButtonTweet(Name,Username,tweetID,mentionLineEdit->text());
                                mentionLineEdit->clear();
                            });
                            connect(followButton, &QPushButton::clicked, [=]() {
                                FollowerButtonAccount(username, Username);
                            });
                            connect(ShowMention,&QPushButton::clicked, [=]() {
                                BackgroundTweetClicked(tweetID);
                            });
                        }
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
    catch (std::exception &e)
    {
        QMessageBox::critical(nullptr, e.what(), "There was a problem, please try again");
    }

}

