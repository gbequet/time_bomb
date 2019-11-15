#include <iostream>
#include <vector>
#include <QDebug>
#include <QString>
#include "game.h"
#include "card_controller.h"
#include "player_controller.h"

#define BOMB 2
#define DEFUSING 1
#define CABLE 0

using namespace std;

bool Game::gameOver = false;

Game::Game(int nb_player, vector<QString> users) : nbPlayer(nb_player)
{
    int i,j,k;

    this->nbTour = 0;
    this->nbDefusingCut = 0;

    // creer les joueurs
    //TODO : pas d'argument hasPLayed dans le constructeur, initialisé à false
    /*for(i=0; i < this->nbPlayer; i++)
        this->players.push_back(Player(users[i], true));*/

    // on creer le paquet de cartes et on assigne un role a chacun
    // en fonction du nombre de joueurs
    Card_Controller::createDeck(this->nbPlayer);
    Player_Controller::assignTeams(users);


    // on melange et on distribue
    Player_Controller::deal();
    this->players = Player_Controller::getPlayers();
    // qui commence?
    this->curPlayer = Player_Controller::getRandomPlayer(this->players);

    //qDebug() << "tour de :";
    this->curPlayer.show();
    i = 0;

    vector<CardJeu> cards = Card_Controller::getCards();

    while(!this->isOver()) // main boucle
    {
        int player = 0;
        int card = 0;

        for(k=0; k < this->players.size(); k++) // nb de tour = nb de joueur
        {
            //TODO : modifier while par if

            for(i = 0; i < this->players.size(); i++){
                cout <<"[" << i+1 << "] " << this->players[i].getName().toStdString() << " ";
            }

            cout << endl << "Choisir quel joueur couper : " << endl;
            cin >> player;
            vector <CardJeu> playerCards = this->players[player-1].getCards();
            for(i = 0; i < playerCards.size(); i++){
                if(!playerCards[i].isCut())
                    cout <<"[" << i+1 << "]-"<< playerCards[i].getType() << " ";

            }
            cout << endl << "Choisir quelle carte couper : " << endl;
            cin >> card;
            if(playerCards[card - 1].getType() == DEFUSING)
                this->nbDefusingCut++;
                cout << "Cable de désamorçage" << endl;
                if(this->nbDefusingCut == this->nbPlayer){
                    cout << "Tous les câbles de désamorçage ont été trouvés, Big Ben est sauvé YOUPI !" << endl;
                    gameOver = true;
                    break;
                }
            if(playerCards[card - 1].getType() == CABLE)
                cout << "Cable normal" << endl;
            if(playerCards[card - 1].getType() == BOMB){
                gameOver = true;
                cout << "La bombe a été coupé, Big Ben a explosé.." << endl;
                break;
            }

            //TODO : supprimer id fixe (idéfix lol)
            Player_Controller::cutCardTo(this->players[player - 1], card - 1);
            if(i == this->players.size() -1){
                cout << "Tout le monde à joué" << endl;
                continue;
            }


            // on change de joueur courant (celui qui vient de se faire couper)
            this->curPlayer = this->players[player - 1];
            cout << "Au tour de " << this->curPlayer.getName().toStdString() << endl;
         }



//            this->players[i].showCards();

        /*for(j=0; j<this->nbPlayer; j++)
            this->players[i].removeHand();*/

        //this->deal();
    }
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

//TODO : revoir, bizarre de passer le nb de joueurs de chaque team
/*void Game::createDeck(int good, int bad)
{
    int i;

    //TODO : false valeur par défaut -> à bouger dans le constructeur
    for(i=0;i<good;i++)
        this->cards.push_back(CardJeu(false,CABLE));
    for(i=0;i<bad;i++)
        this->cards.push_back(CardJeu(false,DEFUSING));
    this->cards.push_back(CardJeu(false,BOMBE));
}*/

/*void Game::assignTeam(int good, int bad)
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
}*/

void Game::printPlayers()
{
    for(int i=0; i < this->nbPlayer; i++)
        this->players[i].show();
}

/*void Game::deal()
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
}*/

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
    bool res = gameOver;
    ++this->nbTour;
    if(this->nbTour >= 4)
        res = true;

    /*for(int i=0; i< (int)this->cards.size(); i++)
    {
        if(this->cards[i].getType() == BOMBE)
            res = true;
    }*/
    return res;
}
