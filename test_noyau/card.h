#ifndef CARD_H
#define CARD_H

class Card
{
    public:
        Card(int id);
        void showCard();
        void hideCard();

    private:
        int m_id;
        bool hiden;
};

#endif // CARD_H
