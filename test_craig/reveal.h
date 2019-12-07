#ifndef REVEAL_H
#define REVEAL_H

#include <QWidget>
#include "game_controller.h"

namespace Ui {
class Reveal;
}

class Reveal : public QWidget
{
    Q_OBJECT

public:
    explicit Reveal(QWidget *parent = nullptr, Game_Controller *game = nullptr);
    ~Reveal();
    void setGame(Game_Controller *g);
    void setNbCard(int nc);

private slots:
    void nextMove();
//    void

private:
    Ui::Reveal *ui;
    Game_Controller *game;
    int nbCard;
    bool first;
    int cmp;
};

#endif // REVEAL_H
