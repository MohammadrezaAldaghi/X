#ifndef TWEETFORM_H
#define TWEETFORM_H

#include "qtmetamacros.h"
#include "qwidget.h"
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLayout>
#include <QPixmap>

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


private:
    Ui::TweetForm *ui;
};

#endif // TWEETFORM_H
