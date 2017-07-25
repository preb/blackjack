CC = g++
STANDARD = -std=c++11
CFLAGS = -Wall -c $(STANDARD)
LFLAGS = -Wall $(STANDARD)

blackjack: blackjack.o Card.o Deck.o Hand.o
	$(CC) $(LFLAGS) blackjack.o Card.o Deck.o Hand.o -o blackjack

blackjack.o: blackjack.cpp Deck.h Hand.h
	$(CC) $(CFLAGS) blackjack.cpp

Card.o: Card.cpp Card.h
	$(CC) $(CFLAGS) Card.cpp

Deck.o: Deck.cpp Deck.h Card.h
	$(CC) $(CFLAGS) Deck.cpp

Hand.o: Hand.cpp Hand.h Card.h
	$(CC) $(CFLAGS) Hand.cpp

clean:
	\rm *.o *~ blackjack

