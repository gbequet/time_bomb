#include "card_controller.h"
#include "player_controller.h"
#include "cardjeu.h"
#include "player.h"
#include <vector>
#include <iostream>

#define BOMB 2
#define DEFUSING 1
#define CABLE 0

using namespace std;
vector <CardJeu> Card_Controller::cards;

Card_Controller::Card_Controller()
{
}

vector<CardJeu> Card_Controller::createDeck(int nbPlayer)
{
    int nbDefusing;
    int nbNormal;

    if(nbPlayer > 8 || nbPlayer < 4){
        cout << "nombre de joueur invalide" << endl;
        exit(0);
    }

    nbNormal = (nbPlayer * 5) - nbPlayer - 1;
    nbDefusing = nbPlayer;


    int i;

    //TODO : false valeur par défaut -> à bouger dans le constructeur

    for(i=0;i<nbNormal;i++){
        cards.push_back(CardJeu(CABLE));
    }
    for(i=0;i<nbDefusing;i++){
        cards.push_back(CardJeu(DEFUSING));
    }
    cards.push_back(CardJeu(BOMBE));

    return cards;
}

vector<CardJeu> Card_Controller::getCards(){
    return cards;
}

/*void Card_Controller::deal(){
    vector<Player> players = Player_Controller::getPlayers();
    random_shuffle(cards.begin(), cards.end());
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<players.size(); j++)
        {
            players[j].addCard(cards[i]);
        }
    }

    Player_Controller::setPlayers(players);
}*/
