#ifndef GAME_H
#define GAME_H

#include <vector>
#include "player.h"
//#include "card.h"
#include "cardjeu.h"
//#include "deck.h"

class Game
{
    public:
        // main
        Game(int nb_player, std::vector<QString> users);

        // creer le paquet en fonction du nombre de cables
        void createDeck(int cable, int defusing);

        // donne a chaque joueur une equipe
        void assignTeam(int good, int bad);

        // distribue 5 cartes par joueur
        void deal();

        void printPlayers();
        void printDeck();

        std::vector<CardJeu> getCards();

        bool isOver();

        // Retire une carte de type t du paquet
        // Le paquet doit contenir au moins une carte de type t
        void removeCard(int t);

//        void initGame(int nb_player);
//        bool turnIsOver();
//        void nextTurn();
//        int nbCardForGame();

    private:
        int nbTour;
        int nbCut;
        int nbPlayer;
        int winner;
        Player curPlayer;
        std::vector<Player> players;
        std::vector<CardJeu> cards;
};

#endif // GAME_H
