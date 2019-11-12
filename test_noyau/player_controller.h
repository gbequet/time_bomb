#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include <vector>
#include "player.h"

using namespace std;

class Player_Controller
{
public:
    static vector<Player> assignTeams(vector<QString> users);
    static Player getRandomPlayer(vector<Player> players);
    static vector<CardJeu> getPlayerCards(int index);
    static vector<Player> getPlayers();
    static void setPlayers(vector<Player> players);
    static void deal();

private :
    static vector<Player> players;
    Player_Controller() {};
};

#endif // PLAYER_CONTROLLER_H
