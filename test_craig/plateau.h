#ifndef PLATEAU_H
#define PLATEAU_H

#include <vector>
#include <QWidget>
#include "ui_plateau.h"

namespace Ui {
class Plateau;
}

class Plateau : public QWidget
{
    Q_OBJECT

public:
    explicit Plateau(QWidget *parent = nullptr);
    ~Plateau();

private slots:
    void click_home();


private:
    Ui::Plateau *ui;
};

#endif // PLATEAU_H
