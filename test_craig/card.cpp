#include "card.h"

Card::Card(int id): m_id(id)
{

}

void Card::showCard()
{
    this->hiden = true;
}

void Card::hideCard()
{
    this->hiden = false;
}
