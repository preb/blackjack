#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Card.h"

class Hand {
public:
    enum class Player {
        PLAYER,
        DEALER
    };
private:
    Player m_player;
    std::vector<Card> m_hand;
public:
    Hand(Player player = Player::PLAYER): m_player {player} {}
    void draw(const Card&);
    int handValue() const;
    void print();
};

#endif

