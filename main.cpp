/* Noah Klein */

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#include "cards.hpp"


void createDeck(std::vector<Card> *deck){
    deck->clear();

    for(int suit = 0; suit <= club; suit++){
        for(int rank = 0; rank <= ace; rank++){
            deck->emplace_back(Card(static_cast<Suit>(suit), static_cast<Rank>(rank)));
        }
    }
}

void shuffleDeck(std::vector<Card> *deck){
    auto rd = std::random_device {}; 
    auto rng = std::default_random_engine { rd() };
    std::shuffle(std::begin(*deck), std::end(*deck), rng);
}

Card drawCard(std::vector<Card> *deck){
    Card drawn = deck->front();
    deck->erase(deck->begin());
    return drawn;
}

// Passing the cards as a copy here is not performant but makes things much simpler
Card trickWinner(std::vector<Card> cards, Suit trump, Suit led){
    std::sort(cards.begin(), cards.end(), 
    [trump, led](Card a, Card b) {
        // Determine if each card is trump, led, or neither
        bool aIsTrump = (a.suit == trump);
        bool bIsTrump = (b.suit == trump);
        bool aIsLed = (a.suit == led);
        bool bIsLed = (b.suit == led);

        // Compare based on the suit category
        if (aIsTrump && !bIsTrump) {
            return true; // a is trump, b is not trump -> a should come before b
        } else if (!aIsTrump && bIsTrump) {
            return false; // b is trump, a is not trump -> b should come before a
        } else if (aIsLed && !bIsTrump && !bIsLed) {
            return true; // a is led, b is not trump or led -> a should come before b
        } else if (!aIsLed && bIsLed && !aIsTrump) {
            return false; // b is led, a is not trump or led -> b should come before a
        }

        // If both cards belong to the same category (both trump or both led),
        // then sort them by rank in descending order (higher rank comes first)
        return a.rank > b.rank;
    }
    );

    // The card at the front of the vector is the winner
    return cards[0];
}


int main(){
    const int players = 2;

    std::vector<Card> deck;
    createDeck(&deck);
    
    /* Drawn card before a shuffle will always be the two of hearts */
    Card trump = drawCard(&deck);

    /* This is the ace of hearts */
    Card mine = deck[11];
    //deck.erase(deck.begin() + 11);

    
    

    shuffleDeck(&deck);

    Card led = deck[23];

    
    std::vector<Card> table = {deck[3], deck[0], deck[1], deck[2]};

    for (auto i : table)
    {
        std::cout << i.toString() << "\n";
    }

    std::cout << "\nTrump: " << trump.suitToString() << "\tLed: " << deck[0].suitToString() << "\n";;
    std::cout << "Winner: " << trickWinner(table, trump.suit, deck[0].suit).toString() << "\n";
    

    return 0;
}
