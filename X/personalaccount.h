#ifndef PERSONALACCOUNT_H
#define PERSONALACCOUNT_H

#include "qwidget.h"
#include <QWidget>
#include <QListWidgetItem>
#include <QListWidget>
#include <QDir>
#include <QColor>



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


private slots:
    void on_SettingButton_clicked();

    void on_SearchLineEdit_textChanged(const QString &arg1);

private:
    Ui::PersonalAccount *ui;


};

#endif // PERSONALACCOUNT_H
