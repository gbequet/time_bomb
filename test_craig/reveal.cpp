#include <QDebug>
#include "reveal.h"
#include "ui_reveal.h"
#include "game_controller.h"

Reveal::Reveal(QWidget *parent, Game_Controller *game) :
    QWidget(parent),
    ui(new Ui::Reveal),
    game(game)
{
    ui->setupUi(this);

    nbTour = 5;

    connect(ui->quitter, SIGNAL(clicked()), parent, SLOT(goHome()));
    connect(ui->next, SIGNAL(clicked()), this, SLOT(nextMove()));

    qDebug() << "coucou" << endl;

//    QString c = game->getPlayerName(0);
//    QString c = game->players[0].getName();
//    ui->curPlayer->setText("Cartes de " + c);
//    qDebug() << game->nbPlayer << endl;
}

Reveal::~Reveal()
{
    delete ui;
}

void Reveal::setGame(Game_Controller *g)
{
    game = g;
}

void Reveal::nextMove()
{

}
