#include "tweetform.h"
#include "ui_tweetform.h"

TweetForm::TweetForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TweetForm)
{
    ui->setupUi(this);
//    ui->TweetButton->setStyleSheet("background-color: lightblue");
    // Create a QPixmap object and assign the image to it
    QPixmap pixmap("C:/Users/ARTA/Desktop/tweet.png");

    // Set the pixmap to be square
    pixmap = pixmap.scaledToWidth(ui->TweetButton->height(), Qt::SmoothTransformation);

    // Set the pixmap as the icon of the button
    ui->TweetButton->setIcon(QIcon(pixmap));

    // Set the button to be circular
    ui->TweetButton->setStyleSheet("QPushButton { border-radius: 100%}");

    // Ensure that the pixmap is displayed instead of text
    ui->TweetButton->setIconSize(ui->TweetButton->size());


}

TweetForm::~TweetForm()
{
    delete ui;
}

void TweetForm::SetUsernameAndNameTweetForm(QString username, QString name)
{
    Username = username;
    Name = name;
}

QString TweetForm::GetTwwetCounterTweetForm(QString username)
{
//    QString Result;
//    {
//        QFile file("Personal/" + username + ".json");
//        if(file.exists())
//        {
//            try{

//                if(file.open(QIODevice::ReadOnly))
//                {
//                    QByteArray jsonData = file.readAll();
//                    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
//                    if(jsonDoc.isNull())
//                    {
//                        throw std::invalid_argument("not exist");
//                    }
//                    else
//                    {
//                        QJsonObject jsonObj = jsonDoc.object();
//                        if(jsonObj.value("Username").toString()==username)
//                        {
//                            file.close();
//                            QFile::remove("Personal/" + username);
//                            if(file.open(QIODevice::WriteOnly))
//                            {
//                                jsonObj["Country"] = newCountry;
//                                QJsonDocument jDoc(jsonObj);
//                                QByteArray jData = jDoc.toJson();
//                                file.write(jData);
//                                file.close();

//                            }
//                        }

//                    }

//                }
//                else
//                {
//                    throw std::invalid_argument("file not found");
//                }

//            }
//            catch(std::exception& e)
//            {
//                QMessageBox::critical(this,"Error",e.what());
//            }
//        }
//        file.close();
//    }
//    //***************************************************
//    {
//        QFile file("Organisation/" + username + ".json");
//        if(file.exists())
//        {
//            try{
//                if(file.open(QIODevice::ReadOnly))
//                {
//                    QByteArray jsonData = file.readAll();
//                    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
//                    if(jsonDoc.isNull())
//                    {
//                        throw std::invalid_argument("not exist");
//                    }
//                    else
//                    {
//                        QJsonObject jsonObj = jsonDoc.object();
//                        if(jsonObj.value("Username").toString()==username)
//                        {
//                            file.close();
//                            QFile::remove("Organisation/" + username);
//                            if(file.open(QIODevice::WriteOnly))
//                            {
//                                jsonObj["Country"] = newCountry;
//                                QJsonDocument jDoc(jsonObj);
//                                QByteArray jData = jDoc.toJson();
//                                file.write(jData);
//                                file.close();

//                            }
//                        }

//                    }

//                }
//                else
//                {
//                    throw std::invalid_argument("file not found");
//                }

//            }
//            catch(std::exception& e)
//            {
//                QMessageBox::critical(this,"Error",e.what());
//            }
//        }
//        file.close();
//    }
//    //**************************************************************
//    {
//        QFile file("Anonymous/" + username + ".json");
//        if(file.exists())
//        {
//            try{
//                if(file.open(QIODevice::ReadOnly))
//                {
//                    QByteArray jsonData = file.readAll();
//                    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
//                    if(jsonDoc.isNull())
//                    {
//                        throw std::invalid_argument("not exist");
//                    }
//                    else
//                    {
//                        QJsonObject jsonObj = jsonDoc.object();
//                        if(jsonObj.value("Username").toString()==username)
//                        {
//                            file.close();
//                            QFile::remove("Anonymous/" + username);
//                            if(file.open(QIODevice::WriteOnly))
//                            {
//                                jsonObj["Country"] = newCountry;
//                                QJsonDocument jDoc(jsonObj);
//                                QByteArray jData = jDoc.toJson();
//                                file.write(jData);
//                                file.close();

//                            }
//                        }

//                    }

//                }
//                else
//                {
//                    throw std::invalid_argument("file not found");
//                }

//            }
//            catch(std::exception& e)
//            {
//                QMessageBox::critical(this,"Error",e.what());
//            }
//        }
//        file.close();
//    }
}

void TweetForm::on_TweetButton_clicked()
{
//    qDebug()<<ui->TweetTextEdit->toPlainText()<<"\n"; //get textEdit text
    Tweet* t = new Tweet();
    t->AddTweet(Username,ui->TweetTextEdit->toPlainText(),ui->HashtagTextEdit->toPlainText(),Name,0);
    ui->TweetTextEdit->setText("");
    ui->TweetSentLabel->setText("Tweet sent successfully");
    ui->TweetSentLabel->setStyleSheet("color : red");

    {
        QString Result;
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
                                    int temp1 = std::stoi( jsonObj["TweetCounter"].toString().toStdString());
                                    temp1++;
//                                    qDebug()<<"Result = "<<jsonObj["TweetCounter"]<<"\n";
                                    jsonObj["TweetCounter"] = QString::fromStdString(std::to_string(temp1));
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
//                                    qDebug()<<"Result = "<<jsonObj["TweetCounter"].toInt()<<"\n";
                                    int temp1 = std::stoi( jsonObj["TweetCounter"].toString().toStdString());
                                    temp1++;
                                    qDebug()<<"Result = "<<jsonObj["TweetCounter"]<<"\n";
                                    jsonObj["TweetCounter"] = QString::fromStdString(std::to_string(temp1));
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
            QFile file("Anonymous/" + Username + ".json");
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
                                QFile::remove("Anonymous/" + Username);
                                if(file.open(QIODevice::WriteOnly))
                                {
                                    int temp1 = std::stoi( jsonObj["TweetCounter"].toString().toStdString());
                                    temp1++;
                                    qDebug()<<"Result = "<<jsonObj["TweetCounter"]<<"\n";
                                    jsonObj["TweetCounter"] = QString::fromStdString(std::to_string(temp1));
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



    this->close();
}


