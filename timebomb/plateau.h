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
    void setNbCard(int nc);

private slots:
    void click_home();
    void cut_card();
    void returnToReveal(int nbCard);
    void show_rules();
    void hide_rules();

private:
    Ui::Plateau *ui;
    Game_Controller *game;
    int nbTour;
    void clear_table();
    int nbCard;
    void sherlock_wins();
    void moriarty_wins();
    void bomb_explodes();

signals:
    void finTour(int);
};

#endif // PLATEAU_H
