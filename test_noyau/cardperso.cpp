#include "cardperso.h"

CardPerso::CardPerso(int t) : team(t)
{

}

int CardPerso::getTeam()
{
    return this->team;
}

void CardPerso::setTeam(int t)
{
    this->team = t;
}
