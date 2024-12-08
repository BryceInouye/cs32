#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_set>
#include "Person.h"
#include "Exception.h"
#include "unorder_map.h"
#include "Item.h"
using namespace std;
namespace Location {
    char display() {
        cout << "What would you like to do?" << endl;
        cout << "\033[1m[A]: \033[0m Make a purchase\n"
            << "\033[1m[B]: \033[0m Show items sorted by cost\n"
            << "\033[1m[C]: \033[0m Show items sorted by name\n" 
            << "\033[1m[D]: \033[0m Leave the store" << endl;
        char input;
        cin >> input;
        input = tolower(input);
        if (input != 'a' && input != 'b' && input != 'c' && input != 'd') {
            throw customException::InvalidInputException();
        }
        return input;
    }

    class Store {
        public:
            Store(Person::Player* user) : user(user) { 
                product.incrItemCount("Burrito", 4);
                product.incrItemCount("Pokey Stick", 3);
                weapons.insert("Pokey Stick");
                product.incrItemCount("Floppy Fish", 3);
                product.incrItemCount("Short Sword", 5);
                weapons.insert("Short Sword");
                // product.incrItemCount("Clarinet", 4);
                // product.incrItemCount("Lantern", 3);
                // product.incrItemCount("Medicine", 3);
                // product.incrItemCount("Medicine", 3);
                // product.incrItemCount("Super Magical Potion", 10);
                active = true;
                // openStore();
            }
            void purchaseItem() {
                ostringstream oss;
                options = product.getSortedVec();
                if (options.size() == 0) {
                    cout << "Sorry, I'm don't have anything to sell you." << endl;
                    return;
                }
                int originalBalance = user->getBalance();
                product.dumpItemsSortedByItem(oss);
                cout << "What were you interested in buying? Enter \"L\" to leave\n"
                     << oss.str() << "\033[1m[L]: \033[0m" << "Cancel Purchase\n"
                     << "\033[1mCurrent Balance: \033[0m" << originalBalance << endl;
                char userPick;
                cin >> userPick;
                userPick = tolower(userPick);
                int maxChar = options.size();
                try {
                    if (userPick == 'l') {
                        cout << "No worries. I hope you find what you need." << endl;
                        return;
                    } else if (userPick > 'a' + maxChar - 1) {
                        throw customException::InvalidInputException();
                    }
                    std::pair<string, std::pair<int, double>> boughtItem = options[userPick - 'a'];
                    if (user->getBalance() < boughtItem.second.second) {
                        // Add haggle mechanic
                        cout << "Sorry friend. You don't have enough money to buy a " << "\033[1m" << boughtItem.first << "\033[0m." << endl;
                        return;
                    }
                    cout << "Congratulations! Enjoy your new \033[1m" << boughtItem.first << "\033[0m." << endl;
                    product.decrItemCount(boughtItem.first);
                    user->setBalance(originalBalance - boughtItem.second.second);
                    cout << "\033[1mOriginal Balance     :   \033[0m" << "\033[3m" << originalBalance << "\033[0m" << endl;
                    cout << "\033[1mCost of Item         :  -\033[0m" << boughtItem.second.second << endl;
                    cout << "____________________________\n"
                         << "\033[1mNew Balance          :   \033[0m" << user->getBalance() << endl;
                    if (weapons.find(boughtItem.first) != weapons.end()) {
                        // purchasedGoods.push_back(new Items::Food(boughtItem.first, boughtItem.second.second, "pussy"));
                        user->addItem(new Items::Weapon(boughtItem.first, boughtItem.second.second, "pussy"));
                    } else {
                        user->addItem(new Items::Food(boughtItem.first, boughtItem.second.second, "cock"));
                    }
                } catch (customException::InvalidInputException e) {
                    cout << "Please enter a valid input next time." << endl;
                }
            }
            void openStore() {
                cout << "Welcome in! We have everything you need!" << endl;
                active = true;
                while (active) {
                    try {
                    char res = display();
                    ostringstream oss;
                    if (res == 'd') {
                        active = false;
                        cout << "See you next time!" << endl;
                    } else if (res == 'a') {
                        // string itemBought = purchaseItem();
                        purchaseItem();
                    } else if (res == 'b') {
                        product.dumpItemsSortedByValue(oss);
                        cout << oss.str() << endl;
                    } else if (res == 'c') {
                        product.dumpItemsSortedByItem(oss);
                        cout << oss.str() << endl;
                    }
                    } catch (customException::InvalidInputException e) {
                        cout << "Please enter a valid value." << endl;
                    }
                    cin.get();
                    cin.get();
                }
            }
        private: 
            bool active;
            Person::Player *user;
            customDataStruct::UnorderedMap<string> product;
            std::unordered_set<string> weapons;
            std::vector<std::pair<string, std::pair<int, double>>> options;
    };
}

#endif