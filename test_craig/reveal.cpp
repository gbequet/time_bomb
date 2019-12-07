#include <QDebug>
#include "reveal.h"
#include "ui_reveal.h"
#include "game_controller.h"
#include "fenetreprincipale.h"
#include "card_controller.h"
#include "cardjeu.h"

using namespace std;

Reveal::Reveal(QWidget *parent, Game_Controller *game) :
    QWidget(parent),
    ui(new Ui::Reveal),
    game(game)
{
    ui->setupUi(this);

    nbCard = 5;
    ui->next->setText("Show");
//    aVue = false;
    cmp = 0;
    first = true;

    connect(ui->quitter, SIGNAL(clicked()), parent, SLOT(goHome()));
    connect(ui->next, SIGNAL(clicked()), this, SLOT(nextMove()));
}

Reveal::~Reveal()
{
    delete ui;
}

void Reveal::setGame(Game_Controller *g)
{
    game = g;

    QString c = game->players[0].getName();
    ui->curPlayer->setText("Cartes de " + c);
}

void Reveal::nextMove()
{
    if(cmp < game->nbPlayer)
    {
        if(ui->next->text() == "Show") // on montre ses cartes a players[cmp]
        {
            QString c = game->players[cmp].getName();
            ui->curPlayer->setText("Cartes de " + c);

            if(game->players[cmp].getTeam() == 0) // gentil
                ui->perso->setStyleSheet("border-image: url(:/images/characters/sherlock1.png)");
            else // mechant
                ui->perso->setStyleSheet("border-image: url(:/images/characters/moriarty1.png)");

            vector<CardJeu> cardsCurPlayer = game->players[cmp].getCards();

            for(int i=0; i<nbCard; i++)
            {
                QToolButton * qt = (QToolButton *)ui->playerCards->itemAt(i)->widget();
                switch(cardsCurPlayer[i].getType())
                {
                    case 1:
                        qt->setStyleSheet("border-image: url(:/images/cards/card-defuse.png)");
                        break;
                    case 2:
                        qt->setStyleSheet("border-image: url(:/images/cards/card-big-ben-explosion.png)");
                        break;
                    default:
                        qt->setStyleSheet("border-image: url(:/images/cards/card-useless.png)");
                        break;
                }
            }
            ui->next->setText("Next");
        }
        else if(ui->next->text() == "Next")
        {
            ++cmp;
            QString c = game->players[cmp].getName();
            ui->curPlayer->setText("Cartes de " + c);
            ui->perso->setStyleSheet("border-image: url(:/images/characters/hidden.png)");

            vector<CardJeu> cardsCurPlayer = game->players[cmp].getCards();

            for(int i=0; i<nbCard; i++)
            {
                QToolButton * qt = (QToolButton *)ui->playerCards->itemAt(i)->widget();
                qt->setStyleSheet("border-image: url(:/images/cards/card-hidden.png)");
            }

            ui->next->setText("Show");
        }
    }
}
