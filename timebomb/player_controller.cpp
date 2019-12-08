#include <vector>
#include <iostream>
#include "player_controller.h"
#include "card_controller.h"
#include "player.h"
#include <QDebug>


#define SHERLOCK 1
#define MORIARTY 0

using namespace std;



vector<Player> Player_Controller::players;


vector<Player> Player_Controller::assignTeams(vector<QString> users)
{
    vector<int> b;


    int nbSherlock;
    int nbMoriarty;

    switch(users.size())
    {
        case 4:
            nbSherlock = 3;
            nbMoriarty = 2;
            break;
        case 5:
            nbSherlock = 3;
            nbMoriarty = 2;
            break;
        case 6:
            nbSherlock = 4;
            nbMoriarty = 2;
            break;
        case 7:
            nbSherlock = 5;
            nbMoriarty = 3;
            break;
        case 8:
            nbSherlock = 5;
            nbMoriarty = 3;
            break;

        default:
            cout << "nombre de joueur invalide" << endl;
    }


    int i;

    for(i=0; i<nbSherlock; i++)
        b.push_back(SHERLOCK);
    for(i=0; i<nbMoriarty; i++)
        b.push_back(MORIARTY);

    random_shuffle(b.begin(), b.end());

    for(i=0; i < users.size(); i++)
    {
        Player p(users[i], b[i]);
        players.push_back(p);
    }

    return players;
}


void Player_Controller::deal(int nbPlayers)
{
    vector<CardJeu> cards = Card_Controller::getCards();
    random_shuffle(cards.begin(), cards.end());
    for(int i = 0; i < cards.size(); i++)
    {
        players[i % nbPlayers].addCard(cards[i]);
    }



}


Player Player_Controller::getRandomPlayer(vector<Player> players)
{
    return players[rand()%players.size()];
}


vector<CardJeu> Player_Controller::getPlayerCards(int index)
{
    cout << players[index].getName().toStdString() << endl;
    return players[index].getCards();
}


vector<Player> Player_Controller::getPlayers()
{
    return players;
}


void Player_Controller::setPlayers(vector<Player> players)
{
    players = players;
}


void Player_Controller::cutCardTo(Player& p, int index)
{
    vector<CardJeu> cards = p.getCards();
    if(!cards[index].isCut())
    {
        cards[index].setCut(true);
        p.setCards(cards);
    }
}



