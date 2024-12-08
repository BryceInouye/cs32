#ifndef PLACE_H
#define PLACE_H
#include <string>
#include "Item.h"
using namespace std;
namespace Location {
    class Place {
        public:
            Place(string name, string description) : name(name), description(description) {}
            virtual ~Place() {}
            const string getName() { return name; }

        private:
            string description;
            string name;
    };
    class itemChance : public Place {
        public:
            itemChance(string name, string description, Items::Item* item) : Place(name, description), item(item) {}
            ~itemChance() {}
            Items::Item* getItem();
        private:
            Items::Item* item;
    };
    class Chest : public Place {
        public:
            Chest(string name, string description, int value, bool cursed) : Place(name, description), value(value), cursed(cursed) {}
            ~Chest() {}
        private:
            int value;
            bool cursed;
    };
}
#endif