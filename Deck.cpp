#include <iostream>
#include <array>
#include <random>
#include "Card.h"

class Deck {
private:
    std::array<Card, 52> m_deck;

    static int getRandomNumber(int min, int max) {
        static std::random_device rd;
        static std::mt19937 mersenne(rd());
        static const uint32_t RANDMAX {0};
        static const double fraction {1.0 / (~RANDMAX + 1.0)};
        return static_cast<int>(mersenne() * fraction * (max - min + 1) + min);
    }

    static void swapCards(Card &card1, Card &card2) {
        Card temp {card1};
        card1 = card2;
        card2 = temp;
    }
public:
    Deck() {
        for (int rank {0}; rank < 13; ++rank) {
            for (int suit {0}; suit < 4; ++suit)
                m_deck[rank * 4 + suit] = Card(static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit));
        }
    }

    void shuffle() {
        for (Card &card: m_deck)
            swapCards(card, m_deck[getRandomNumber(0, 51)]);
    }

    void print() const {
        for (const Card &card: m_deck) {
            card.print();
            std::cout << ' ';
        }
        std::cout << '\n';
    }
};
