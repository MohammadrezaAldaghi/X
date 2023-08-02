#include "mainwindow.h"
#include "qjsonarray.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_checkButton_clicked()
{
    {
        QFile file("Tweet/Like.json");
        try
        {
            if (file.open(QIODevice::ReadWrite))
            {
                QByteArray fileData = file.readAll();

                QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData);

                QJsonArray jsonArray;
                if (jsonDoc.isArray())
                {
                    jsonArray = jsonDoc.array();
                }

                QJsonObject jsonObj;
                jsonObj["Username"] = "username";
                jsonObj["UsernameLike"] = "1234";
                jsonObj["TweetID"] = "123456789";
                jsonArray.append(jsonObj);

                QJsonDocument newJsonDoc(jsonArray);

                file.resize(0);
                file.write(newJsonDoc.toJson());

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
        file.close();
    }



}

