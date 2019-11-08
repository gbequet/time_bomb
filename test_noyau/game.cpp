#include <iostream>
#include <vector>
#include <QDebug>
#include <QString>
#include "game.h"

#define BOMB 2
#define DEFUSING 1
#define CABLE 0

using namespace std;

Game::Game(int nb_player, vector<QString> users) : nbPlayer(nb_player)
{
    int i,j,k;

    this->nbTour = 0;

    // creer les joueurs
    //TODO : pas d'argument hasPLayed dans le constructeur, initialisé à false
    for(i=0; i < this->nbPlayer; i++)
        this->players.push_back(Player(users[i], true));

    // on creer le paquet de cartes et on assigne un role a chacun
    // en fonction du nombre de joueurs
    switch(this->nbPlayer)
    {
        case 4:
            this->createDeck(15,4);
            this->assignTeam(3,2);
            break;
        case 5:
            this->createDeck(19,5);
            this->assignTeam(3,2);
            break;
        case 6:
            this->createDeck(23,6);
            this->assignTeam(4,2);
            break;
        case 7:
            this->createDeck(27,7);
            this->assignTeam(5,3);
            break;
        case 8:
            this->createDeck(31,8);
            this->assignTeam(5,3);
            break;

        default:
            qDebug() << "nombre de joueur invalide" << endl;
    }

    // on melange et on distribue
    this->deal();

    // qui commence?
    this->curPlayer = this->players[rand()%this->nbPlayer];

    //TODO : on s'en fout si il a joué ou pas, il peut jouer plusieurs fois
    this->curPlayer.setHasPlayed(false);
    qDebug() << "tour de :";
    this->curPlayer.show();
    i = 0;

//    while(!this->isOver()) // main boucle
//    {
        for(k=0; k < this->nbPlayer; k++) // nb de tour = nb de joueur
        {

            //TODO : modifier while par if
            while(!this->curPlayer.getHasPlayed()) // tant que le joueur n'a pas choisi qui il allait couper
            {
                // quand le joueur courant coupe le 3eme fil du joueur i par exemple
//                i = 3;

                //TODO : supprimer id fixe (idéfix lol)
                int tmp = this->curPlayer.cutCardTo(this->players[i], 3);
                this->removeCard(tmp);

                this->curPlayer.setHasPlayed(true);
            }
            // on change de joueur courant, ca devient le ieme (celui qui vient de se faire couper)
            this->curPlayer = this->players[i];
            this->curPlayer.setHasPlayed(false);
            qDebug() << this->cards.size();
            i++;

//            this->players[i].showCards();
        }
        for(j=0; j<this->nbPlayer; j++)
            this->players[i].removeHand();

        this->deal();
//    }
}

void Game::printDeck()
{
    for(int i=0; i < (int) this->cards.size(); i++)
    {
        this->cards[i].show();
    }
    qDebug() << this->cards.size() << endl;
}

vector<CardJeu> Game::getCards()
{
    return this->cards;
}

void Game::createDeck(int cable, int defusing)
{
    int i;

    for(i=0;i<cable;i++)
        this->cards.push_back(CardJeu(CABLE));
    for(i=0;i<defusing;i++)
        this->cards.push_back(CardJeu(DEFUSING));
    this->cards.push_back(CardJeu(BOMB));
}

void Game::assignTeam(int good, int bad)
{
    int i;
    vector<int> b;

    for(i=0; i<good; i++)
        b.push_back(1);
    for(i=0; i<bad; i++)
        b.push_back(0);

    random_shuffle(b.begin(), b.end());

    for(i=0; i < this->nbPlayer; i++)
    {
        this->players[i].setTeam(b[i]);
    }
}

void Game::printPlayers()
{
    for(int i=0; i < this->nbPlayer; i++)
        this->players[i].show();
}

void Game::deal()
{
    random_shuffle(this->cards.begin(), this->cards.end());
    int k = 0;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<this->nbPlayer; j++)
        {
            this->players[j].addCard(this->cards[k]);
            k++;
        }
    }
}

//TODO utiliser objet card et pas id
void Game::removeCard(int t)
{
    int i;
    bool tmp = false;
    for(i=0; i < (int) this->cards.size() && !tmp; i++)
    {
        if(this->cards[i].getType() == t)
            tmp = true;
    }

    this->cards.erase(this->cards.begin()+i);
}

//TODO à revoir
bool Game::isOver()
{
    bool res = false;
    ++this->nbTour;
    if(this->nbTour >= 4)
        res = true;

    for(int i=0; i< (int)this->cards.size(); i++)
    {
        if(this->cards[i].getType() == BOMBE)
            res = true;
    }
    return res;
}
