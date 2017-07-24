#ifndef DECK_H
#define DECK_H

#include <array>
#include "Card.h"

class Deck {
private:
    std::array<Card, 52> m_deck;
    int nextCard = 0;
    static int getRandomNumber(int, int);
    static void swapCards(Card&, Card&);
public:
    Deck();
    void shuffle();
    const Card& dealCard();
    void print() const;
};

#endif
