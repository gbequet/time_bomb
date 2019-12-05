#include "plateau.h"
#include "ui_plateau.h"
#include "game_controller.h"
#include "player_controller.h"
#include "fenetreprincipale.h"

Plateau::Plateau(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Plateau)
{
    ui->setupUi(this);
    //connect(ui->player_button, SIGNAL(clicked()), this, SLOT(click_home()));
    std::vector<QString> users;
    users.push_back("Craig");
    users.push_back("Joren");
    users.push_back("Guillaume");
    users.push_back("Sam");
    users.push_back("Arthur");
    int nbPlayers = 6;



    Game_Controller game_ctrl(5, users);
    std::vector<Player> players;
    players = Player_Controller::getPlayers();
    qDebug() << "nbPlayers : " << nbPlayers;

    QLayout * line_top = ui->players_line_top;
    QLayout * line_bot = ui->players_line_bot;
    QLayout * line_left = ui->players_line_left;
    QLayout * line_right = ui->players_line_right;

    std::vector<QLayout *> layouts;
    layouts.push_back(line_top);
    layouts.push_back(line_bot);
    layouts.push_back(line_left);
    layouts.push_back(line_right);


    for(int i = 0; i <= 8; i++){
        if(i > nbPlayers){
            QLayout  * layout = layouts[i%4];
            QPushButton *qp = (QPushButton *)layout->itemAt(3)->widget();
            QWidget *sp = layout->itemAt(2)->widget();
            delete qp;
            layout->removeWidget(sp);
        }
    }




    ;

}

void Plateau::click_home(){
}


Plateau::~Plateau()
{
    delete ui;
}
