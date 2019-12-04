#include "reveal.h"
#include "ui_reveal.h"
#include "game_controller.h"

Reveal::Reveal(QWidget *parent, Game_Controller game) :
    QWidget(parent),
    ui(new Ui::Reveal),
    game(game)
{
    ui->setupUi(this);
}

Reveal::~Reveal()
{
    delete ui;
}
