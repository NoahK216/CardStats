/* Noah Klein */

#include <stdio.h>
#include <iostream>
#include <vector>

#include "cards.hpp"


void createDeck(std::vector<Card> *deck){
    deck->clear();

    for(int suit = 0; suit <= club; suit++){
        for(int rank = 0; rank <= ace; rank++){
            deck->emplace_back(Card(static_cast<Suit>(suit), static_cast<Rank>(rank)));
        }
    }
}

int main(){
    Card card(diamond, two);
    std::vector<Card> deck;
    createDeck(&deck);


    /* Print the contents of the entire deck */
    for (auto i : deck)
    {
        std::cout << i.toString() << "\n";
    }

    return 0;
}
