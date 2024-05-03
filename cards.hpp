/* Noah Klein */

#include <string>

enum Suit{
    heart, diamond, spade, club
};

enum Rank{
    two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace
};


class Card {
private:

public:
    enum Suit suit;
    enum Rank rank;

    Card(enum Suit suit, enum Rank rank) {
        this->suit = suit;
        this->rank = rank;
    }

    std::string rankToString();
    std::string suitToString();
    std::string toString();

    bool beats(Card *opposing, Suit trump, Suit led);
};
