/* Noah Klein */

#include "cards.hpp"
#include <string>


std::string Card::rankToString(){
    static std::string ranks[13] = {"two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "jack", "queen", "king", "ace"};
    return ranks[this->rank];
}

std::string Card::suitToString(){
    static std::string suits[4] = {"heart", "diamond", "spade", "club"};
    return suits[this->suit];
}

std::string Card::toString(){
    return Card::rankToString() + " of " + Card::suitToString() + "s";
}

bool Card::beats(Card *opposing, Suit trump, Suit led){
    if(this->suit == trump){
        if(opposing->suit == trump){
            return this->rank > opposing->rank;
        }
        else return true;
    }
    else if(this->suit == led){
        if(opposing->suit == trump){
            return false;
        }
        else if(opposing->suit == led){
            return this->rank > opposing->rank; 
        }
    }

    // You cannot beat somebody if you do not play either trump or what is led
    return false;
}
