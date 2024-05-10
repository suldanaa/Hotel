//declare classes
#include <string>
#include <iostream>
using namespace std;

#ifndef HOTEL_H
#define HOTEL_H


//inheritance

class Hotel{
    protected:
    int price; //price per night
    int totalRev;
    string name;

    public:
    void setPrice(int);
    int getPrice();
    void setName(string);
    string getName();
    void setTotalRev(int);
    int getTotalRev();
    

};

class Rooms:public Hotel{
    protected:
    int amount;
    int roomNum;

    public:
    void setAmount(int);
    int getAmount();
    void setRoomNum(int);
    int getRoomNum();
    
};

class Courtyard: public Rooms{

};

class Scenic: public Rooms{

};

class Suite: public Rooms{

};

class Penthouse: public Rooms{

};

#endif