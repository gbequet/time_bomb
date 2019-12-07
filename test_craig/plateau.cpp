#include "plateau.h"
#include "ui_plateau.h"
#include "game_controller.h"
#include "player_controller.h"
#include "card_controller.h"
#include "fenetreprincipale.h"
#include <unistd.h>

std::vector<CardJeu> cards;

Plateau::Plateau(QWidget *parent, Game_Controller *game) :
    QWidget(parent),
    ui(new Ui::Plateau),
    game(game)
{
    ui->setupUi(this);
}

void Plateau::setGame(Game_Controller *g)
{
    game = g;

    for(int i = 0; i < game->players.size(); i++)
    {
        Player p = game->players[i];
        std::vector<CardJeu> cards = p.getCards();
    }

    QLayout * line_top = ui->players_line_top;
    QLayout * line_bot = ui->players_line_bot;
    QLayout * line_left = ui->players_line_left;
    QLayout * line_right = ui->players_line_right;

    std::vector<QLayout *> layouts;
    layouts.push_back(line_top);
    layouts.push_back(line_bot);
    layouts.push_back(line_left);
    layouts.push_back(line_right);

    //Placement des joueurs
    for(int i = 0; i < 8; i++)
    {
        QLayout  * layout = layouts[i%4];
        QPushButton *qp;
        if(i >= game->nbPlayer)
        {
            qp = (QPushButton *)layout->itemAt(3)->widget();
            QWidget *sp = layout->itemAt(2)->widget();
            delete qp;
            layout->removeWidget(sp);
        }
        else if(i < game->nbPlayer)
        {
            if(i < 4)
            {
                qp = (QPushButton *) layout->itemAt(1)->widget();
            }
            else
            {
                qp = (QPushButton *) layout->itemAt(3)->widget();
            }
            connect(qp, SIGNAL(clicked()), this, SLOT(click_home()));
            qp->setProperty("id", i);
        }
    }
}

//Select player and show cards
void Plateau::click_home()
{
    QPushButton *senderObj = (QPushButton * )sender();
    int id =  senderObj->property("id").toInt();
    Player p = game->players[id];
    cards = p.getCards();
    std::vector<QLayout*> layouts;
    layouts.push_back(ui->cards_line_top);
    layouts.push_back(ui->cards_line_bot);

    QLayout* cur_layout = layouts[0];
    int card_index = 1;
    for(int i = 0; i < cards.size(); i++)
    {
        qDebug() << "Card " << i << " is cut " << cards[i].isCut();
        if(i == 3)
        {
            cur_layout = layouts[1];
            card_index = 1;
        }
        QPushButton * qt = (QPushButton *)cur_layout->itemAt(card_index)->widget();
        if(!cards[i].isCut())
        {
            qt->setStyleSheet("border-image: url(:/images/cards/card-hidden.png)");
            qt->setProperty("type", cards[i].getType());
            qt->setProperty("owner", id);
            qt->setProperty("id", i);
            connect(qt, SIGNAL(clicked()), this, SLOT(cut_card()));
            qt->show();

        }
        else
        {
            qt->hide();
        }
        card_index += 2;
    }
    this->repaint();
}


//Cut card
void Plateau::cut_card()
{

    QPushButton *senderObj = (QPushButton * )sender();
    int type = senderObj->property("type").toInt();
    switch(type)
    {
        case 1 :
            senderObj->setStyleSheet("border-image: url(:/images/cards/card-defuse.png)");
            break;
        case 2 :
            senderObj->setStyleSheet("border-image: url(:/images/cards/card-big-ben-explosion.png)");
            break;
        default:
            senderObj->setStyleSheet("border-image: url(:/images/cards/card-useless.png)");
            break;
    }
    this->repaint();

    int player_id = senderObj->property("owner").toInt();
    int card_index = senderObj->property("id").toInt();
    Player_Controller::cutCardTo(game->players[player_id], card_index);
}


Plateau::~Plateau()
{
    delete ui;
}
