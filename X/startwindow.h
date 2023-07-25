#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>

namespace Ui {
class Startwindow;
}

class Startwindow : public QWidget
{
    Q_OBJECT

public:
    explicit Startwindow(QWidget *parent = nullptr);
    ~Startwindow();

private:
    Ui::Startwindow *ui;
};

#endif // STARTWINDOW_H
