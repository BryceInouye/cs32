#ifndef PERSON_H
#define PERSON_H
#include <queue>
#include "unorder_map.h"
#include <unordered_set>
#include "Place.h"
#include "Item.h"
#include "utility.h"
namespace Person
{
    class Enemy {
        public:
            Enemy(int power, string name, string line);
            ~Enemy(){}
            const string& getline();
            const string& getName();
            int getPower() const;
            bool isAlive() const;
            void setAlive(bool state);
        private:
            string name;
            int power;
            string line;
            bool alive;
    };
    class Player {
        public:
            Player();
            ~Player();
            void playerLose();
            void enemyDefeated(const string& name, const string& line);
            void beginFight();
            void visitPlace(Location::Place* place);
            char beginInteraction();
            void displayMenu();
            void displayInventory();
            bool isAlive();
            int getBalance() const;
            void setBalance(int payment);
            void addItem(Items::Item* item);
            int getRound();
        private:
            void handleFight(Person::Enemy foe);
            vector<Items::Item*> inventory;
            int balance;
            bool alive;
            queue<Person::Enemy> enemies;
            int enemiesLeft;
            int round;
            queue<Location::Place*> places; 
            vector<Location::Place*> usedPlaces;
            Location::Place* place1;
            Location::Place* place2;
    };
} // namespace Person


#endif

