#ifndef HOME_H
#define HOME_H

#include <QWidget>

namespace Ui {
class home;
}

class home : public QWidget
{
    Q_OBJECT

public:
    explicit home(QWidget *parent = nullptr);
    ~home();

public slots:
    void goCredit();

private:
    Ui::home *ui;
};

#endif // HOME_H
