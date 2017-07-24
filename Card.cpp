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
        SPADE,
        MAX
    };
private:
    Rank m_rank;
    Suit m_suit;
public:
    Card(Rank rank = Rank::TWO, Suit suit = Suit::CLUBS):
        m_rank {rank}, m_suit {suit} {}
};
