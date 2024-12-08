#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include <memory>
#include "Person.h"
#include "Exception.h"
#include "utility.h"
using namespace std;

Person::Enemy::Enemy(int power, string name, string line) : power(power), name(name), line(line) { alive = true; }
const string& Person::Enemy::getline() { return line; }
const string& Person::Enemy::getName() { return name; }
int Person::Enemy::getPower() const { return power; }
bool Person::Enemy::isAlive() const { return alive; }
void Person::Enemy::setAlive(bool state) { alive = state; }

Person::Player::Player(){
    srand(time(nullptr));
    inventory.push_back(new Items::Weapon("SUPER SWORD", 2, "Gets the job done."));
    inventory.push_back(new Items::Food("Carrot", 3, "(Batteries not included)"));
    balance = 5;
    alive = true;
    enemiesLeft = 6;
    round = 12; // counts down to zero
    enemies.push(Person::Enemy(0, "An Innocent Fly", "Buzz off nerd!"));
    enemies.push(Person::Enemy(2, "Ribbetus the Frog", "Toad-ally not cool!"));
    enemies.push(Person::Enemy(3, "Kyle", "I went easy on you. Go on little one!"));
    enemies.push(Person::Enemy(5, "Alice", "Bob! Do something!"));
    enemies.push(Person::Enemy(5, "Bob", "This is so lame! Whatever."));
    enemies.push(Person::Enemy(8, "Jimmy", "NOOOOOOOO!"));
    
    Items::Food taco("Taco Supreme", 7, "Packs a punch of flavor!");
    Location::itemChance* tacoTruck = new Location::itemChance("Bert's Tacos", "Free taco day! Come grab a bite.", &taco);
    places.push(tacoTruck);
    Location::Chest* chester = new Location::Chest("A Shiny Chest", "OPEN ME", 5, false);
    places.push(chester);
} 

Person::Player::~Player() {
    for (auto item : inventory) {
        delete item;
    }
    for (auto place : usedPlaces) {
        delete place;
    }
}

void Person::Player::beginFight() {
    Person::Enemy minion = enemies.front();
    enemies.pop();
    handleFight(minion);
    round--;
}

void Person::Player::visitPlace(Location::Place* place) {
    if (auto itemSpot = dynamic_cast<Location::itemChance*>(place)) {
        // auto taco = itemSpot->getItem();
        // int counter = 0;
        // for (auto item : inventory) {
        //     if (auto thing = dynamic_cast<Items::Food*>(item)) {
        //         *thing = *taco;
        //     }
        // }
        // displayInventory();
        cout << "STUB" << endl;


    } else if (auto chestSpot = dynamic_cast<Location::Chest*>(place)) {
        cout << "Treasure chest area! You get money!" << endl;
    } else {
        cout << "Welcome to Imagination Land! AKA You messed up." << endl;
    }
}

char Person::Player::beginInteraction() {
    if (places.size() >= 2) {
        place1 = places.front();
        usedPlaces.push_back(place1);
        places.pop();
        place2 = places.front();
        usedPlaces.push_back(place2);
        places.pop();
    }
    string place1Name = place1->getName(), place2Name = place2->getName();
    helper::placeRoundMenu(place1Name, place2Name);
    
    char choice;
    while (choice != 'a' && choice != 'b' && choice != 'c' && choice != 'd') {
        cin >> choice;
        choice = tolower(choice);
    }

    if (choice == 'a') {
        visitPlace(place1);
        round--;
    } else if (choice == 'b') {
        visitPlace(place2);
        round--;
    } else if (choice == 'c') {
        choice = 'd';
    } else {
        choice = 'e';
    }
    // cin.get();

    return choice;
}

bool flipCoin() {
    char choice = 'a';
    cout << "Choose wisely! Your life depends on it, at least in this game!\n" 
         << "\033[1m[A]:\033[0m Heads!\n"
         << "\033[1m[B]:\033[0m Tails!" << endl;
    cin >> choice;
    if (choice != 'a' && choice != 'b') choice = 'a';
    string coin[2] = {"heads", "tails"};
    int res = choice - 'a';
    int randomNum = (rand() % 2);
    cout << "The coin flips in the air and... (press 'enter' see results)" << endl;
    cin.get();
    cout << "You chose: " << "\033[1m" << coin[res] << "\033[0m and the coin says " << "\033[1m" << coin[randomNum] << "\033[0m." << endl;
    return res == randomNum;
}
void Person::Player::playerLose() {
    alive = false;
    cout << "Game Over!" << endl; // cause of death
}
void Person::Player::enemyDefeated(const string& name, const string& line) {
    cout << name << " has been defeated. Victory!" << endl;
    cout << name << " says " << line << endl;
}
void Person::Player::handleFight(Person::Enemy foe) {
    cout << "A \033[1m" << foe.getName() << "\033[0m" << " appears!" << endl;
    cin.get();
    cout << "What will you do?\n"
         << "\033[1m[A]:\033[0m Fight!\n"
         << "\033[1m[B]:\033[0m Run away!\n"
         << "\033[1m[C]:\033[0m See Inventory" << endl;
    char choice;
    cin >> choice;
    choice = tolower(choice);
    try {
        if (choice == 'a') {
            char letter = 'A';
            cout << "____________________________" << endl;
            cout << "Options:" << endl;
            for (auto item : inventory) {
                cout << "\033[1m[" << letter << "]:\033[0m Use ";
                item->getShortDescription();
                letter++;
            }
            letter = tolower(letter);
            cout << "\033[1m[" << letter << "]:\033[0m Flip a Coin" << endl;
            cin >> choice;
            choice = tolower(choice);
            if (choice == letter) {
                bool res = flipCoin();
                if (res) {
                    enemyDefeated(foe.getName() ,foe.getline());
                } else {
                    playerLose();
                }
            } else if (choice > letter || choice < 'a') {
                cout << "Choose something next time. And you lost!" << endl;
                playerLose();
            } else {
                cout << "Let's Duel!\n";
                Items::Item* item = inventory[choice - 'a'];
                bool playerWin = item->use(foe.getPower());
                if (!playerWin) {
                    playerLose();
                } else {
                    enemyDefeated(foe.getName(), foe.getline());
                    foe.setAlive(false);
                }
            }

        } else if (choice == 'b') {
            throw customException::InvalidInputException();
        } else if (choice == 'c') {
            displayInventory();
        } else {
            throw customException::InvalidInputException();
        }
    } catch (customException::InvalidInputException e) {
        cout << "Undecisiveness doesn't look good on you." << endl;
        playerLose();
    }
    cin.get();
    cin.get();
}


void Person::Player::displayMenu() {
    // if (Boss->isAlive()) {
    //     handleFight(*Boss);
    // }
}

void Person::Player::displayInventory() {
    cout << "______________________\n"
         << "Here's what you got:\n";
    for (auto item : inventory) {
        item->getDescription();
    }
    cout << "______________________" << endl;
}

bool Person::Player::isAlive() { return alive; }

int Person::Player::getBalance() const { return balance; }
void Person::Player::setBalance(int payment) { balance = payment; }

void Person::Player::addItem(Items::Item* item) {
    inventory.push_back(item);
    cout << "New Item Acquired:\n";
    item->getDescription();
}

int Person::Player::getRound() {
    return round;
}