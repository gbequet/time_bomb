#ifndef CARDPERSO_H
#define CARDPERSO_H

#define MORIARTY 0
#define SHERLOCK 1

#include "card.h"


class CardPerso
{
    public:
        CardPerso(int t);
        int getTeam();
        void setTeam(int t);

    private:
        int team;
};

#endif // CARDPERSO_H
