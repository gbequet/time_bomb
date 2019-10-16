#ifndef CREDITS_H
#define CREDITS_H

#include <QWidget>

namespace Ui {
class Credits;
}

class Credits : public QWidget
{
    Q_OBJECT

public:
    explicit Credits(QWidget *parent = nullptr);
    ~Credits();

public slots:
    void goHome();

private:
    Ui::Credits *ui;
};

#endif // CREDITS_H
