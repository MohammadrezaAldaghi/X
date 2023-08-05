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

void TweetForm::on_TweetButton_clicked()
{
//    qDebug()<<ui->TweetTextEdit->toPlainText()<<"\n"; //get textEdit text
    Tweet* t = new Tweet();
    t->AddTweet(Username,ui->TweetTextEdit->toPlainText(),ui->HashtagTextEdit->toPlainText(),Name,0);
    ui->TweetTextEdit->setText("");
    ui->TweetSentLabel->setText("Tweet sent successfully");
    ui->TweetSentLabel->setStyleSheet("color : red");
    this->close();
}


