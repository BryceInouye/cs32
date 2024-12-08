#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
using namespace std;
namespace helper {
    inline void startDialogue() {
    cout << "\033[3mLife was pretty good for you. There were no risks, and no family to take care of. You\n\033[0m"
    << "\033[3mhad a nice job flipping burgers and cleaning the fryer at a Rainforest Cafe.\n\033[0m"
    << "\033[3mHowever, this was all a lie-you convinced yourself stability was good. You saw all\n\033[0m"
    << "\033[3mof your friends get degrees, marry, start a family, get promoted, while you worked in the\n\033[0m"
    << "\033[3mvibrant, boisterous rainforest in the middle of a mall. You would always say you had everything\n\033[0m"
    << "\033[3myou needed, but there was something you wanted. You wanted a new start.\033[0m\033[0m" << endl;
    cin.get();
    cout <<"\033[3mA few cliches and overused character expositions later, you are reborn in\n\033[0m"
    << "\033[3ma magical world, where everything is magical. Like most other stories, there is a bad guy.\n\033[0m"
    << "\033[3mThis is like a dream world so the bad guy is \033[1mJim\033[0m, your manager from the cafe. Anyways\n\033[0m"
    << "\033[3mlet's not get too deep in the details and let you begin your adventure.\n" 
    << "\033[3mDo your best to save the world, and you will get the happy ending you always wanted! Good luck!\033[0m" << endl;
    cin.get();
    cout << "\033[1mTUTORIAL\033[0m" << endl;
    cout << "Let me tell you the basics. You beat bad guys with items. There are two types: \033[1mFood\033[0m and \033[1mWeapons\033[0m\n";
    cin.get();
    cout << "Food might have a stronger effect than weapon, but they are single use.\n";
    cin.get();
    cout << "Don't try to run away. It is always an option, but the whole point of the story is for you to face your fears.\nSo don't do it unless you really want to!\n";
    cin.get();
    cout << "You can only use one item per interaction, so choose wisely! Between fights, you will visit places.\n";
    cin.get();
    cout << "If you are lucky, you might find something awesome.\n";
    cin.get();
    cout << "There is also a store to buy things from in case you are into that. 10/10 would recommend.\n";
    cin.get();
    cout << "Last thing, pick an invalid choice, and you might die. Just keep that in mind. Not because I am a lazy coder. :)" << endl;
    cin.get();
    cout << "Now for your first opponent: \033[1mAn Innocent Fly\033[0m" << endl;
}
    inline void placeRoundMenu(string place1, string place2) {
        cout << "What would you like to do?" << endl;
        cout << "\033[1m[A]: \033[0m Go to the " << place1 << "\n"
            << "\033[1m[B]: \033[0m Go to the " << place2 << "\n"
            << "\033[1m[C]: \033[0m Go to the store\n"
            << "\033[1m[D]: \033[0m See Inventory\n"
            << "\033[1m[E]: \033[0m Give Up (bad idea!)\n";
    }
    inline void fightRoundMenu() {
        cout << "What would you like to do?" << endl;
        cout << "\033[1m[A]: \033[0m Engage in combat!\n"
            << "\033[1m[B]: \033[0m Go to the store\n"
            << "\033[1m[C]: \033[0m See Inventory\n"
            << "\033[1m[D]: \033[0m Give Up (bad idea!)\n";
    }
}
#endif