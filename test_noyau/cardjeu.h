#ifndef CARDJEU_H
#define CARDJEU_H

#define CABLE 0
#define DESAMORCAGE 1
#define BOMBE 2

#include "card.h"

class CardJeu
{
    public:
        CardJeu(bool cut, int type);

        void show();
        bool isCut();
        void setCut(bool c);
        int getType();
        void setType(int t);

    private:
        bool cut;
        int type;
};

#endif // CARDJEU_H
