#include <iostream>
#include "Deck.h"
#include "Hand.h"

enum class GameResults {
    PLAYER_WIN,
    DEALER_WIN,
    TIE
};

void print(const Hand &hand) {
    std::string player;
    if (hand.getPlayer() == Hand::Player::PLAYER)
        player = "Player";
    else
        player = "Dealer";

    std::cout << '\n' << player << " hand: ";
    hand.print();
    std::cout << player << " hand value: " << hand.handValue() << '\n';
}

GameResults play() {
    Deck deck;
    deck.shuffle();
    Hand dealer(Hand::Player::DEALER), player(Hand::Player::PLAYER);

    dealer.draw(deck.dealCard());
    print(dealer);
    dealer.draw(deck.dealCard());

    player.draw(deck.dealCard());
    player.draw(deck.dealCard());
    print(player);

    std::cout << "\nPlayer turn\n";
    while(true) {
        std::cout << "Do you want to hit (y/n)? ";
        char hit;
        std::cin >> hit;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            continue;
        }
        if (hit != 'y' && hit != 'n')
            continue;
        else if (hit == 'n')
            break;
        player.draw(deck.dealCard());
        print(player);
        if (player.handValue() > 21)
            return GameResults::DEALER_WIN;
    }

    std::cout << "\nDealer turn\n";
    while(true) {
        if (dealer.handValue() >= 17)
            break;
        dealer.draw(deck.dealCard());
        print(dealer);
        if (dealer.handValue() > 21)
            return GameResults::PLAYER_WIN;
    }

    int playerValue {player.handValue()};
    int dealerValue {dealer.handValue()};

    if (playerValue > dealerValue)
        return GameResults::PLAYER_WIN;
    else if (playerValue < dealerValue)
        return GameResults::DEALER_WIN;
    else
        return GameResults::TIE;
}

int main() {
    GameResults winner {play()};
    if (winner == GameResults::PLAYER_WIN)
        std::cout << "Player wins!\n";
    else if (winner == GameResults::DEALER_WIN)
        std::cout << "Dealer wins!\n";
    else
        std::cout << "Tie!\n";
    return 0;
}
