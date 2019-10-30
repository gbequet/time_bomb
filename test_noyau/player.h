#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <QString>
#include "cardjeu.h"
#include "cardperso.h"

class Player
{
    public:
        Player();
        Player(QString n, bool b);
        Player(int t, bool b);
        QString getName();
        void setName(QString n);
        int getTeam();
        void setTeam(int t);
        bool getHasPlayed();
        void setHasPlayed(bool b);
//        CardPerso getPerso();
//        void setPerso(CardPerso p);

        std::vector<CardJeu> getCards();
        void setCards(std::vector<CardJeu> c);
        void addCard(CardJeu& c);
        void removeHand();

        // coupe la carte numero id du joueur p
        // 0 <= id <= 5
        int cutCardTo(Player& p, int id);

        void show();
        void showCards();

    private:
//        CardPerso perso;
        QString name;
        int team;
        bool hasPlayed;
        std::vector<CardJeu> cards;
};

#endif // PLAYER_H
