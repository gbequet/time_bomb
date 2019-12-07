#include "plateau.h"
#include "ui_plateau.h"
#include "game_controller.h"
#include "player_controller.h"
#include "card_controller.h"
#include "fenetreprincipale.h"
#include <unistd.h>
#include <QTime>

std::vector<CardJeu> cards;
QPushButton * prev_selected_player;

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


    connect(ui->card_16, SIGNAL(clicked()), this, SLOT(cut_card()));
    connect(ui->card_17, SIGNAL(clicked()), this, SLOT(cut_card()));
    connect(ui->card_18, SIGNAL(clicked()), this, SLOT(cut_card()));
    connect(ui->card_19, SIGNAL(clicked()), this, SLOT(cut_card()));
    connect(ui->card_20, SIGNAL(clicked()), this, SLOT(cut_card()));




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

    //Cartes cachées par défaut
    this->clear_table();


    int totalDefusing = game->nbPlayer;
    int totalCable = (game->nbPlayer * 5) - game->nbPlayer - 1;

    ui->defusing_count_label->setProperty("total", totalDefusing);
    ui->cable_cout_label->setProperty("total", totalCable);
    ui->defusing_count_label->setProperty("cut", 0);
    ui->cable_cout_label->setProperty("cut", 0);

    ui->defusing_count_label->setText("0/"+QString::number(totalDefusing));
    ui->cable_cout_label->setText("0/"+QString::number(totalCable));



}

//Select player and show cards
void Plateau::click_home()
{
    QPushButton *senderObj = (QPushButton * )sender();
    if(prev_selected_player) prev_selected_player->setStyleSheet("border-image : url(:/back-small.png)");
    senderObj->setStyleSheet("border-image : url(:/player-selected.png)");
    prev_selected_player = senderObj;
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
    int nbCut = 0;
    int total = 0;

    switch(type)
    {
        case 1 :
            senderObj->setStyleSheet("border-image: url(:/images/cards/card-defuse.png)");
            nbCut = ui->defusing_count_label->property("cut").toInt();
            total = ui->defusing_count_label->property("total").toInt();
            ui->defusing_count_label->setProperty("cut", nbCut + 1);
            nbCut++;
            ui->defusing_count_label->setText(QString::number(nbCut) + "/" + QString::number(total));
            break;
        case 2 :
            senderObj->setStyleSheet("border-image: url(:/images/cards/card-big-ben-explosion.png)");
            break;
        default:
            senderObj->setStyleSheet("border-image: url(:/images/cards/card-useless.png)");
            nbCut = ui->cable_cout_label->property("cut").toInt();
            total = ui->cable_cout_label->property("total").toInt();
            ui->cable_cout_label->setProperty("cut", nbCut + 1);
            nbCut++;
            ui->cable_cout_label->setText(QString::number(nbCut) + "/" + QString::number(total));
            break;
    }

    this->repaint();

    QTime dieTime= QTime::currentTime().addSecs(2);
        while (QTime::currentTime() < dieTime)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

    this->clear_table();

    int player_id = senderObj->property("owner").toInt();
    int card_index = senderObj->property("id").toInt();
    Player_Controller::cutCardTo(game->players[player_id], card_index);
    game->curPlayer = game->players[player_id];
    ui->tour_label->setText("AU TOUR DE " + game->curPlayer.getName().toUpper());

}

void Plateau::clear_table(){
    std::vector<QLayout*> cards_layouts;
    cards_layouts.push_back(ui->cards_line_top);
    cards_layouts.push_back(ui->cards_line_bot);
    for(int i = 0; i < cards_layouts.size(); i++){
        for(int j = 0; j < cards_layouts[i]->count(); j++){
            QWidget * w = cards_layouts[i]->itemAt(j)->widget();
            if (w != NULL)
              {
                w->setVisible(false);
              }
        }
    }
}


Plateau::~Plateau()
{
    delete ui;
}
