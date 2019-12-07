#ifndef PLATEAU_H
#define PLATEAU_H

#include <vector>
#include <QWidget>
#include "ui_plateau.h"
#include "game_controller.h"

namespace Ui {
class Plateau;
}

class Plateau : public QWidget
{
    Q_OBJECT

public:
    explicit Plateau(QWidget *parent = nullptr, Game_Controller *game = nullptr);
    ~Plateau();
    void setGame(Game_Controller *g);

private slots:
    void click_home();
    void cut_card();

private:
    Ui::Plateau *ui;
    Game_Controller *game;
};

#endif // PLATEAU_H
