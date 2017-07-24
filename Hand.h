#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Card.h"

class Hand {
private:
    bool m_isPlayer;
    std::vector<Card> m_hand;
public:
    Hand(bool isPlayer = true): m_isPlayer {isPlayer} {}
    void draw(const Card&);
    int handValue() const;
    void print();
};

#endif

