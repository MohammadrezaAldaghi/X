#ifndef PERSONALACCOUNT_H
#define PERSONALACCOUNT_H

#include "qwidget.h"
#include <QWidget>
#include <QListWidgetItem>
#include <QListWidget>
#include <QDir>


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


private:
    Ui::PersonalAccount *ui;
};

#endif // PERSONALACCOUNT_H
