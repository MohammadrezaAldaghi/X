#ifndef TWEETFORM_H
#define TWEETFORM_H

#include "qtmetamacros.h"
#include "qwidget.h"
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLayout>
#include <QPixmap>
#include "tweet.h"


namespace Ui {
class TweetForm;
}

class TweetForm : public QWidget
{
    Q_OBJECT;

public:
    explicit TweetForm(QWidget *parent = nullptr);
    ~TweetForm();

private slots:


    void on_TweetButton_clicked();

private:
    Ui::TweetForm *ui;
};

#endif // TWEETFORM_H
