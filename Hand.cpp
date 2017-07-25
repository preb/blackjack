#include <iostream>
#include "Card.h"
#include "Hand.h"

Hand::Player Hand::getPlayer() const {
    return m_player;
}

void Hand::draw(const Card &card) {
    m_hand.push_back(card);
}

int Hand::handValue() const {
    int sum {0}, aceCount {0};
    for (const Card &card: m_hand) {
        int value {card.getCardValue()};
        sum += value;
        if (value == 11)
            ++aceCount;
        if (sum > 21 && aceCount) {
            --aceCount;
            sum -= 10;
        }
    }
    return sum;
}

void Hand::print() const {
    for (const Card &card: m_hand) {
        card.print();
        std::cout << ' ';
    }
    std::cout << '\n';
}

