#include <iostream>
#include <vector>
#include <QDebug>
#include <QString>
#include "game_controller.h"
#include "card_controller.h"
#include "player_controller.h"

#define BOMB 2
#define DEFUSING 1
#define CABLE 0

using namespace std;

bool Game_Controller::gameOver = false;

Game_Controller::Game_Controller(int nbPlayer, std::vector<QString> users) : nbPlayer(nbPlayer)
{
    this->nbTour = 0;
    this->nbDefusingCut = 0;

    Card_Controller::createDeck(this->nbPlayer);
    Player_Controller::assignTeams(users);
    Player_Controller::deal();

    this->players = Player_Controller::getPlayers();
    this->curPlayer = Player_Controller::getRandomPlayer(this->players);
}
