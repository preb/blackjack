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

    int getRankValue() const {
        switch (m_rank) {
        case Rank::TWO: return 2;
        case Rank::THREE: return 3;
        case Rank::FOUR: return 4;
        case Rank::FIVE: return 5;
        case Rank::SIX: return 6;
        case Rank::SEVEN: return 7;
        case Rank::EIGHT: return 8;
        case Rank::NINE: return 9;
        case Rank::TEN:
        case Rank::JACK:
        case Rank::QUEEN:
        case Rank::KING: return 10;
        case Rank::ACE: return 11;
        default: return 0;
        }
    }

    char getRankName() const {
        switch (m_rank) {
        case Rank::TWO: return '2';
        case Rank::THREE: return '3';
        case Rank::FOUR: return '4';
        case Rank::FIVE: return '5';
        case Rank::SIX: return '6';
        case Rank::SEVEN: return '7';
        case Rank::EIGHT: return '8';
        case Rank::NINE: return '9';
        case Rank::TEN: return 'T';
        case Rank::JACK: return 'J';
        case Rank::QUEEN: return 'Q';
        case Rank::KING: return 'K';
        case Rank::ACE: return 'A';
        default: return '?';
        }
    }

    char getSuitName() const {
        switch (m_suit) {
        case Suit::CLUBS: return 'C';
        case Suit::DIAMONDS: return 'D';
        case Suit::HEARTS: return 'H';
        case Suit::SPADES: return 'S';
        default: return '?';
        }
    }
};
