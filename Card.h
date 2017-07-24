#ifndef CARD_H
#define CARD_H

class Card {
public:
    enum class Rank {
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING,
        ACE,
        MAX
    };

    enum class Suit {
        CLUBS,
        DIAMONDS,
        HEARTS,
        SPADES,
        MAX
    };
private:
    Rank m_rank;
    Suit m_suit;
public:
    Card(Rank rank = Rank::TWO, Suit suit = Suit::CLUBS):
        m_rank {rank}, m_suit {suit} {}

    int getCardValue() const;
    char getRankName() const;
    char getSuitName() const;
    void print() const; 
};

#endif

