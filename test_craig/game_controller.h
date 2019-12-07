#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include <vector>
#include "player.h"
#include "cardjeu.h"

class Game_Controller
{
public:
    Game_Controller(int nbPlayer, std::vector<QString> users);
    QString getPlayerName(int id);
    std::vector<Player> players;
    int nbPlayer;
    Player curPlayer;

private:
    int nbTour;
    int nbDefusingCut;
//    int nbPlayer;
//    std::vector<Player> players;
    std::vector<CardJeu> cards;
    static bool gameOver;

};

#endif // GAME_CONTROLLER_H
