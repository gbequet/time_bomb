#ifndef CARD_CONTROLLER_H
#define CARD_CONTROLLER_H

#include <vector>

#include "cardjeu.h"
#include "player.h"

using namespace std;

class Card_Controller
{
    public:
        Card_Controller();
        static vector<CardJeu> createDeck(int nbPlayer);
        static vector<CardJeu> getAllCards();
        static void deal();
        static vector<CardJeu> getCards();

    private:
        static vector<CardJeu> cards;

};

#endif // CARD_CONTROLLER_H
