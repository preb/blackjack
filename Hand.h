#ifndef HAND_H
#define HAND_H

#include <iostream>
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
    Hand::Player getPlayer() const;
    void draw(const Card&);
    int handValue() const;
    friend std::ostream& operator<<(std::ostream&, const Hand&);
};

#endif

