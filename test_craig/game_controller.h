#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include <vector>
#include "player.h"
#include "cardjeu.h"

class Game_Controller
{
public:
    Game_Controller(int nbPlayer, std::vector<QString> users);

private:
    int nbTour;
    int nbDefusingCut;
    int nbPlayer;
    Player curPlayer;
    std::vector<Player> players;
    std::vector<CardJeu> cards;
    static bool gameOver;

};

#endif // GAME_CONTROLLER_H
