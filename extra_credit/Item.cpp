#include "Item.h"
#include <iostream>
using namespace std;

Items::Item::Item(string name, int value, string description) : name(name), value(value), description(description) {}

Items::Food::Food(string name, int value, string description) : Item(name, value, description){
    cooked = false;
}
Items::Food::~Food() {}
void Items::Food::getDescription() {
    cout << "Name: \033[1m" << name << "\033[0m\n" 
         << "\033[3m\033[0m"
         << "Chef's Note: " << "\033[3m" << description << "\033[0m" << endl;
}

void Items::Food::getShortDescription() {
    cout << "\033[3m" << name << "\033[0m, Food Critic's Score = " << calcCombatPower() << endl;;
}

Items::Food& Items::Food::operator=(const Food& other) {
    if (this == &other) {
        return *this;
    }

    name = other.name;
    value = other.value;
    description = other.description;
    cooked = other.cooked;

    return *this;
}

int Items::Food::calcCombatPower() {
    int total = value;
    if (cooked) {
        total += 5;
    }
    return total;
}
bool Items::Food::use(int power) {
    int total = calcCombatPower();
    used = true;
    return total > power;
}
void Items::Food::upgrade() {
    cooked = true;
    cout << "Something smells good.";
}

Items::Weapon::Weapon(string name, int value, string description) : Item(name, value, description) {
    boost = 1;
    durability = value / 2;
    if (durability <= 0) durability = 1;
    damage = value;
}
Items::Weapon::~Weapon() {
    cout << "Your " << name << " broke!" << endl;
}
void Items::Weapon::getDescription() {
    cout << "Name: \033[1m" << name << "\033[0m\n" 
         << "Power: " <<  calcCombatPower()
         <<"\nUses: " << getDurability()
         << "\nBlacksmith's Review: " << "\033[3m" << description << "\033[0m" << endl;
}
void Items::Weapon::getShortDescription() {
    cout << "\033[3m" << name << "\033[0m, Power = " << calcCombatPower() << ", Uses = " << durability <<endl;
}
int Items::Weapon::calcCombatPower() {
    return damage * boost;
}

int Items::Weapon::getDurability() {
    return durability;
}

bool Items::Weapon::use(int power) {
    if (durability <= 0) {
        return false;
    }
    int total = calcCombatPower();
    durability -= 1;
    if (durability <= 0) {
        used = true;
    }
    cout << "Your power " << total << " vs " << power << endl;
    return total > power;
}

void Items::Weapon::upgrade() {
    durability++;
    boost *= 2;
}