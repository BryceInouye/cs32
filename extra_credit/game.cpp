#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include "Item.h"
#include <sstream>
#include "Store.h"
#include "utility.h"
using std::cout, std::endl;
#include "Place.h"
#include "unorder_map.h"
#include "Person.h"

int main() {
    cout << "\033[1mWelcome to the Choose Your Adventure Game!\033[0m\n" 
         << "Good luck! (press 'enter' to continue)" << endl;
    cin.get();
    bool gameActive = true;
    Person::Player player;
    Location::Store store(&player);
    unordered_set<int> interactionRounds = {11, 9, 8, 6, 5, 2};
    helper::startDialogue();
    player.beginFight();
    cout << "Great work! Now go off and save things and other good stuff!" << endl;
    while (player.isAlive() && player.getRound() > 0) {
        char res;
        if (interactionRounds.count(player.getRound()) == 0) {
            helper::fightRoundMenu();
        } else {
            char action = player.beginInteraction();
            if (action == 'd') {
                store.openStore();
            } else if (action == 'e') {
                player.displayInventory();
            } else {
                break;
            }
        }
        cin >> res;
        cout << "Work in progress";
    }
    // handle end game logic
    
    return 0;
}