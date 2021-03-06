#include "cardjeu.h"
#include <QDebug>

CardJeu::CardJeu(int t) : type(t), cut(false)
{

}

void CardJeu::show()
{
    qDebug() << this->cut << this->type << endl;
}

bool CardJeu::isCut()
{
    return this->cut;
}

void CardJeu::setCut(bool c)
{
    this->cut = c;
}

int CardJeu::getType()
{
    return this->type;
}

void CardJeu::setType(int t)
{
    this->type = t;
}
