#ifndef PERSONALACCOUNT_H
#define PERSONALACCOUNT_H

#include "qwidget.h"
#include <QWidget>
#include <QListWidgetItem>
#include <QListWidget>
#include <QDir>
#include <QColor>
#include <QMessageBox>
#include <QObject>
#include <qobject.h>
#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonObject>
#include <QTimer>
#include <tweet.h>
#include <QtGlobal>
#include <QTextEdit>
#include "followersclasses.h"
#include "mentionclasses.h"


namespace Ui {
class PersonalAccount;
}

class PersonalAccount : public QWidget
{
    Q_OBJECT;

public:
    explicit PersonalAccount(QWidget *parent = nullptr);
    ~PersonalAccount();
    void ReadFromFolderAllAccount();
    void ReadFromFolderAllAccountWithQString(QString str);
    void ReadFromFolderAllTweetWithHashtag(QString str);
    void ReadFromFolderAllTweetWithUsername(QString str);
    void ReadFromFolderAllTweet(QString str);
    void SetUsernameAndNamePersonalAcoount(QString username, QString Name);
    void DisplayProfilePersonalAcoount(QString username);
    void GetTweetLikeFromFile();
    void AdjustBiographyWithUsernameAndPassword(QString username,QString bio);
    void Logout();
    void ChnageNamePersonalAccountWithUsernameAndPasswordChangeSafly(QString usernam,QString NewName);
    void ChangeBirthdayPersonalAccountWithUsernameAndPasswordChangeSafly(QString usernam,QString NewBirthday);
    void ChangeCountryPersonalAccountWithUsernameAndPasswordChangeSafly(QString username,QString newCountry);
    int GetTweetLikePersonalAccountWithTweetID(QString tweetid);
    void ChangeUsernamePersonalAccountWithUsernameAndPasswordChangeSafly(QString oldUsername,QString newUsername);
    void ChangePasswordPersonalAccountWithUsernameAndPasswordChangeSafly(QString oldPassword,QString NewPassword,QString usernameAccount);


private slots:
    void on_SettingButton_clicked();

    void on_SearchLineEdit_textChanged(const QString &arg1);

    void ShowItemClickedInformationWithQString();

    void on_TweetButton_clicked();

    void ItemClickedSettingListWidget(QListWidgetItem *item);

    void MentionButtonTweet(QString usernameNAME,QString username,QString tweetid,QString mentionMessage);

    void LikeButtonTweet(QString te,QString usernamSendTweet);

    void FollowerButtonAccount(QString UsernameSendTweet,QString FollowerUsername);

    void on_FollowersButton_clicked();

    void ShowAllTweetWithFollowerAccountUsername(QListWidgetItem *item);

    void on_FollowingsButton_clicked();

    void BackgroundTweetClicked(QString tweetID);


private:
    Ui::PersonalAccount *ui;
    QString Username;
    QString Name;
    QTimer* timer = new QTimer(this);


};

#endif // PERSONALACCOUNT_H
