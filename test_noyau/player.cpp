#include <iostream>
#include <vector>
#include <QDebug>
#include "player.h"


using namespace std;

Player::Player()
{

}

Player::Player(QString n, bool b) : name(n), hasPlayed(b)
{

}

Player::Player(int t, bool b) : team(t), hasPlayed(b)
{

}

QString Player::getName()
{
    return this->name;
}

void Player::setName(QString n)
{
    this->name = n;
}

int Player::getTeam()
{
    return this->team;
}

void Player::setTeam(int t)
{
    this->team = t;
}

bool Player::getHasPlayed()
{
    return this->hasPlayed;
}

void Player::setHasPlayed(bool b)
{
    this->hasPlayed = b;
}

vector<CardJeu> Player::getCards()
{
    return this->cards;
}

void Player::setCards(vector<CardJeu> c)
{
    this->cards = c;
}

void Player::addCard(CardJeu& c)
{
    if(this->cards.size() < 5)
        this->cards.push_back(c);
}

void Player::removeHand()
{
    for(int i=0; i < int(this->cards.size()); i++)
        this->cards.pop_back();
}

void Player::show()
{
    QString team;
    if(this->team == 0)
        team = "Moriarty";
    else
        team = "Sherlock";

    qDebug() << this->name << "equipe de" << team << "à joué?" << this->hasPlayed << endl;
}

void Player::showCards()
{
    qDebug() << "cartes de" << this->name << endl;
    for(int i=0; i < int(this->cards.size()); i++)
    {
        if(!this->cards[i].isCut())
            this->cards[i].show();
    }
}

int Player::cutCardTo(Player& p, int id)
{
    if(!p.cards[id].isCut())
    {
        p.cards[id].setCut(true);
        return p.cards[id].getType();
    }
}
