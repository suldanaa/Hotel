//define classes
#include <iostream>
using namespace std;
#include "hotel.h"

//HOTEL 
void Hotel::setPrice(int p){
    price = p;
};

int Hotel::getPrice(){
    return price;
};

void Hotel::setName(string n){
    name = n;
};

string Hotel::getName(){
    return name;
};

void Hotel::setTotalRev(int p){
    totalRev = p;
};

int Hotel::getTotalRev(){
    return totalRev;
};

//ROOM
void Rooms::setAmount(int a){
    amount = a;
};

int Rooms::getAmount(){
    return amount;
};

void Rooms::setRoomNum(int r){
    roomNum=r;
};

int Rooms::getRoomNum(){
    return roomNum;
};
