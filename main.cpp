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

int main(){
    std::vector<Card> deck;
    createDeck(&deck);
    
    shuffleDeck(&deck);
    Card trump = drawCard(&deck);
    drawCard(&deck);
    drawCard(&deck);
    drawCard(&deck);
    drawCard(&deck);
    drawCard(&deck);
    drawCard(&deck);
    drawCard(&deck);
    drawCard(&deck);
    
    
    

    std::cout << trump.toString() << "\n";
    std::cout << deck.size() << "\n";

    /* Print the contents of the entire deck */
    for (auto i : deck)
    {
        std::cout << i.toString() << "\n";
    }

    

    return 0;
}
