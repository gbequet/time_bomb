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
    explicit Reveal(QWidget *parent, Game_Controller game);
    ~Reveal();

private:
    Ui::Reveal *ui;
    Game_Controller game;
};

#endif // REVEAL_H
