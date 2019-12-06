#include "plateau.h"
#include "ui_plateau.h"
#include "game_controller.h"
#include "player_controller.h"
#include "card_controller.h"
#include "fenetreprincipale.h"
#include <unistd.h>

std::vector<Player> players;
std::vector<CardJeu> cards;

Plateau::Plateau(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Plateau)
{
    ui->setupUi(this);

    std::vector<QString> users;
    users.push_back("Craig");
    users.push_back("Joren");
    users.push_back("Guillaume");
    users.push_back("Sam");
    users.push_back("Arthur");
    int nbPlayers = 5;

    Game_Controller game_ctrl(nbPlayers, users);

    Card_Controller::createDeck(nbPlayers);
    players = Player_Controller::assignTeams(users);
    for(int i = 0; i < players.size(); i++){
        Player p = players[i];
        qDebug() << p.getName() << " est dans l'équipe " << p.getTeam();

        std::vector<CardJeu> cards = p.getCards();
        for(int j = 0; j < cards.size(); j++){
            qDebug() << "Card " << j << ": " << cards[j].getType();
        }
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


    for(int i = 0; i < 8; i++){
        QLayout  * layout = layouts[i%4];
        QPushButton *qp;
        if(i >= nbPlayers){
            qp = (QPushButton *)layout->itemAt(3)->widget();
            QWidget *sp = layout->itemAt(2)->widget();
            delete qp;
            layout->removeWidget(sp);
        }else if(i < nbPlayers){
            if(i < 4){
                qp = (QPushButton *) layout->itemAt(1)->widget();
            }
            else{
                qDebug() << i%4;
                qp = (QPushButton *) layout->itemAt(3)->widget();
            }
            connect(qp, SIGNAL(clicked()), this, SLOT(click_home()));
            qp->setProperty("id", i);
        }
    }


}

void Plateau::click_home(){
    QPushButton *senderObj = (QPushButton * )sender();
    int id =  senderObj->property("id").toInt();
    Player p = players[id];
    cards = p.getCards();
    std::vector<QLayout*> layouts;
    layouts.push_back(ui->cards_line_top);
    layouts.push_back(ui->cards_line_bot);

    QLayout* cur_layout = layouts[0];
    int card_index = 1;
    for(int i = 0; i < cards.size(); i++){

        if(i == 3){
            cur_layout = layouts[1];
            card_index = 1;
        }

        QPushButton * qt = (QPushButton *)cur_layout->itemAt(card_index)->widget();
        qt->setStyleSheet("border-image: url(:/images/cards/card-hidden.png)");
        qt->setProperty("type", cards[i].getType());
        qt->setProperty("owner", id);
        qt->setProperty("id", i);
        connect(qt, SIGNAL(clicked()), this, SLOT(cut_card()));
        card_index += 2;
    }
    this->repaint();

}

void Plateau::cut_card(){
    QPushButton *senderObj = (QPushButton * )sender();
    int type = senderObj->property("type").toInt();
    switch(type){
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

    sleep(2);

    int player_id = senderObj->property("owner").toInt();
    int card_index = senderObj->property("id").toInt();

    Player_Controller::cutCardTo(players[player_id], card_index);

    std::vector<CardJeu> c = players[player_id].getCards();


}


Plateau::~Plateau()
{
    delete ui;
}
