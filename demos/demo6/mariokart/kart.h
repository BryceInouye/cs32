#ifndef KART_H
#define KART_H
#include<string>
#include<iostream>
using namespace std;

class Kart {
    public:
        Kart(const string& driver, 
             int maxSpeed, 
             float weight);
        
        void displayStats();
        virtual void specialMove();
        void useFuel(int amount);

        virtual ~Kart();

    protected:
        string driver;
        int maxSpeed;
        float weight;

    private:
        int fuel;  // Private field to manage internal fuel consumption
};

#endif