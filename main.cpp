#include <iostream>
#include "myDeck.hpp"

int main() {
    MyDeck<float> deck;

    deck.push_back(3.5);
    deck.push_front(4.6);

    //deck.displayFromBack();

    deck.push_back(7.324);
    deck.push_back(0.32);

    //deck.displayFromBack();

//    deck.pop_front();
//    deck.pop_front();
//
//    std::cout << deck << std::endl;

    std::cout << deck << " " << deck.size() << std::endl;
    return 0;
}
