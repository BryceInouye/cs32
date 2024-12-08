#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>
using namespace std;

namespace Items {
    class Item {
        public:
            Item(string name, int value, string description);
            virtual ~Item(){}
            virtual void getDescription() = 0;
            virtual void getShortDescription() = 0;
            virtual int calcCombatPower() = 0;
            virtual bool use(int power) = 0; // returns how much it is worth
            virtual void upgrade() = 0;
            

        protected:
            string name;
            int value;
            string description;
            bool used;
    };
    class Food : public Item {
        public:
            Food(string name, int value, string description);
            ~Food();
            Food& operator=(const Food& other);
            void getDescription();
            void getShortDescription();
            int calcCombatPower();
            bool use(int power); // offer food
            // void eat();
            void upgrade(); // cook food
        private:
            bool cooked; // game over if not cooked
    };
    class Weapon : public Item {
        public:
            Weapon(string name, int value, string description);
            ~Weapon();
            void getDescription();
            void getShortDescription();
            int calcCombatPower();
            int getDurability();
            bool use(int power);
            void upgrade(); // increase stats
        private:
            int durability;
            int boost;
            int damage;
    };
    // class Instrument : public Item {
    //     public:
    //         Instrument();
    //         ~Instrument();
    //         void getDescription();
    //         void use();
    //         void upgrade(); // get better at playing
    //     private:
    //         bool mastered;
    // };   
}


#endif // ITEM_H
