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
