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

private slots:
    void nextMove();

private:
    Ui::Reveal *ui;
    Game_Controller *game;
    int nbTour;
};

#endif // REVEAL_H
