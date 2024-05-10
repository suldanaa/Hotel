//working on 1 day (maybe incorporate time() function)
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;
#include "hotel.cpp"


// **** FORMATTING/TEXT FUNCTIONS ****
void mainMenu();
void banner(int);
void spacer();
void confirmationMsg(Rooms &r);
void error();
void namePrompt();

void menuOption1();
void menuOption2();
void menuOption3();
void menuOption4();
void menuOption5();
void roomOption1();

// **** ROOM NUMBER DETERMINING FUNCTIONS ****
void amountCheck(Rooms &r);

string date;
char deliminator = '/';
int total_rev;
const int TOTAL_ROOMS = 112;
const int SIZE = 4;
const int COURTYARD_MIN_ROOMNUM = 101;
const int COURTYARD_MAX_ROOMNUM = 170;
const int SCENIC_MIN_ROOMNUM = 201;
const int SCENIC_MAX_ROOMNUM = 235;
const int SUITE_MIN_ROOMNUM = 236;
const int SUITE_MAX_ROOMNUM = 250;
const int PENTHOUSE_MIN_ROOMNUM = 301;
const int PENTHOUSE_MAX_ROOMNUM = 302;
const int COURTYARD_AMNT = 70;
const int SCENIC_AMNT =35;
const int SUITE_AMNT =15;
const int PENT_AMNT = 2;

int name_Iterator=0;
int name_Room_Iterator=0;

Rooms* allRooms[SIZE];
string names[SIZE];
map<int,string> roomToNames;
int courtyardRoomNums[COURTYARD_AMNT];
int scenicRoomNums[SCENIC_AMNT];
int suiteRoomNums[SUITE_AMNT];
int penthouseRoomNums[PENT_AMNT];
int courtyardIterator = 0;
int scenicIterator = 0;
int suiteIterator = 0;
int penthouseIterator = 0;
int nameIterator = 0;

Hotel Hotel;
//THESE ARE SOLELY FOR MENU PURPOSES. 
Rooms Courtyard;
Rooms Scenic;
Rooms Deluxe_Suite;
Rooms Penthouse;

int main(){
    //instantiate hotel objects
    Hotel.setName("Golden Horizon Inn");
    Hotel.setTotalRev(0);

    Courtyard.setName("Standard Rooms, Courtyard");
    Scenic.setName("Standard Room, Scenic");
    Deluxe_Suite.setName("Deluxe Suite");
    Penthouse.setName("Penthouse");

    Courtyard.setPrice(125);
    Scenic.setPrice(145);
    Deluxe_Suite.setPrice(350);
    Penthouse.setPrice(1135);

    Courtyard.setAmount(COURTYARD_AMNT);
    Scenic.setAmount(SCENIC_AMNT);
    Deluxe_Suite.setAmount(SUITE_AMNT);
    Penthouse.setAmount(PENT_AMNT);

    for(int x=0;x<COURTYARD_AMNT;x++){
        courtyardRoomNums[x]=COURTYARD_MIN_ROOMNUM+x;
    }

    for(int x=0;x<SCENIC_AMNT;x++){
        scenicRoomNums[x]=SCENIC_MIN_ROOMNUM+x;
    }

    for(int x=0;x<SUITE_AMNT;x++){
        suiteRoomNums[x]=SUITE_MIN_ROOMNUM+x;
    }

    for(int x=0;x<PENT_AMNT;x++){
        penthouseRoomNums[x]=PENTHOUSE_MIN_ROOMNUM+x;
    }

    allRooms[0]=&Courtyard;
    allRooms[1]=&Scenic;
    allRooms[2]=&Deluxe_Suite;
    allRooms[3]=&Penthouse;

    //welcome message
    spacer();
    banner(45);
    cout << "*\tWelcome to " << Hotel.getName() << "       *" << endl;
    banner(45);

    //Ask for today's date
    cout << "\nPlease enter today's date (MM/DD/YYYY)" << endl;
    cout << ">> ";
    cin >> date;

    //produce menu
    mainMenu();
    return 0;
}

void mainMenu(){
    int menuSelect;
    spacer();
    banner(20);
    cout << "*\tMENU       *" << endl;
    banner(20);

    cout << "1. Reserve Room" << endl;
    cout << "2. Available Rooms" << endl;
    cout << "3. Total Daily Revenue" << endl;
    cout << "4. End of Day Report" << endl;
    cout << "5. Any Day Report" << endl;
    cout << "Make selection: ";
    cin >> menuSelect;
    
    switch(menuSelect){
        case 1: menuOption1();
        break;
        case 2: menuOption2();
        break;
        case 3: menuOption3();
        break;
        case 4: menuOption4();
        break;
        case 5: menuOption5();
        break;
        default: error();
    }
}

void menuOption1(){
    int roomSelect;
    spacer();
    banner(35);
    cout << "*\tMENU > RESERVE_ROOM       *" << endl;
    banner(35);
    namePrompt();
    cin >> names[name_Iterator];
    banner(35);

    spacer();
    cout << "1. " << Courtyard.getName() << " - " << Courtyard.getAmount() << " - " << "$" << Courtyard.getPrice() << " a night - Rooms 101 thru 170" << endl;
    cout << "2. " << Scenic.getName() << " - " << Scenic.getAmount() << " - " << "$" << Scenic.getPrice() << " a night - Rooms 201 thru 235" << endl;
    cout << "3. " << Deluxe_Suite.getName() << " - " << Deluxe_Suite.getAmount() << " - " << "$" << Deluxe_Suite.getPrice() << " a night - Rooms 236 thru 250" << endl;
    cout << "4. " << Penthouse.getName() << " - " << Penthouse.getAmount() << " - " << "$" << Penthouse.getPrice() << " a night - Rooms 301 and 302" << endl;
    cout << "5. Back to Menu" << endl;

    do{

    if(name_Iterator==TOTAL_ROOMS){
        error();
    }

    cout << "Make selection: ";

    //type verification
    if (cin >> roomSelect){
        
    }
    else{
        cin.clear();
        cin.ignore();
    }
    spacer();
    switch(roomSelect){
        case 1: 
        amountCheck(Courtyard);
        Hotel.setTotalRev(Hotel.getTotalRev()+Courtyard.getPrice());
        roomToNames.insert(pair<int,string>(courtyardRoomNums[courtyardIterator],names[name_Iterator]));
        name_Iterator++;
        courtyardIterator++;
        break;

        case 2: 
        amountCheck(Scenic);
        Hotel.setTotalRev(Hotel.getTotalRev()+Scenic.getPrice());
        roomToNames.insert(pair<int,string>(scenicRoomNums[scenicIterator],names[name_Iterator]));
        name_Iterator++;
        scenicIterator++;
        break;

        case 3: 
        amountCheck(Deluxe_Suite);
        Hotel.setTotalRev(Hotel.getTotalRev()+Deluxe_Suite.getPrice());
        roomToNames.insert(pair<int,string>(suiteRoomNums[suiteIterator],names[name_Iterator]));
        name_Iterator++;
        suiteIterator++;
        break;


        case 4: 
        amountCheck(Penthouse);
        Hotel.setTotalRev(Hotel.getTotalRev()+Penthouse.getPrice());
        roomToNames.insert(pair<int,string>(penthouseRoomNums[penthouseIterator],names[name_Iterator]));
        name_Iterator++;
        penthouseIterator++;
        break;

        case 5: mainMenu();
        break;

        default: error();
    }
    }
    while(roomSelect!=5);
    
    
}

void menuOption2(){
    spacer();
    banner(38);
    cout << "*\tMENU > AVAILABLE_ROOMS       *" << endl;
    banner(38);

    for(int x=0; x<SIZE;x++){
        if(allRooms[x]->getAmount()!=0){
           cout << allRooms[x]->getName() << " - " << allRooms[x]->getAmount() << " - " << "$" << allRooms[x]->getPrice() << " a night" << endl;
        }
    }

    mainMenu();

}

void menuOption3(){

    spacer();
    banner(40);
    cout << "*\tMENU > TOTAL_DAILY_REV       *" << endl;
    banner(40);

    cout << "TOTAL REVENUE FOR " << date << ": $" << Hotel.getTotalRev() << endl;

    mainMenu();
    

}

void menuOption4(){


    spacer();
    banner(35);
    cout << "*\tMENU > EoD_REPORT\t*" << endl;
    cout << "*\tDATE: " << date << "\t*" << endl;
    banner(35);
    cout << "TOTAL REVENUE: $" << Hotel.getTotalRev() << endl;
    
    spacer();
    cout << "ROOMS COMPLETELY BOOKED:" << endl;
    for(int x=0; x<SIZE;x++){
    if(allRooms[x]->getAmount()==0){
        cout << allRooms[x]->getName() << " - " << allRooms[x]->getAmount() << " - " << "$" << allRooms[x]->getPrice() << " a night" << endl;
        }   
    }

    spacer();
    cout << "AVAILABLE ROOMS LEFT: " << endl;
    for(int x=0; x<SIZE;x++){
    if(allRooms[x]->getAmount()!=0){
        cout << allRooms[x]->getName() << " - " << allRooms[x]->getAmount() << " - " << "$" << allRooms[x]->getPrice() << " a night" << endl;
        }   
    }


    spacer();
    cout<< "BOOKING LIST: " << endl;
    string fileDate = date + ".txt";
    ofstream MyFile(fileDate);
    MyFile << "-----------------------------------\n";
    MyFile << "*\tMENU > EoD_REPORT\t*" << endl;
    MyFile << "*\tDATE: " << date << "\t*" << endl;
    MyFile << "-----------------------------------\n";
    MyFile << "TOTAL REVENUE: $" << Hotel.getTotalRev() << endl;
    MyFile << endl;
    MyFile << "ROOMS COMPLETELY BOOKED:" << endl;
    for(int x=0; x<SIZE;x++){
    if(allRooms[x]->getAmount()==0){
        MyFile << allRooms[x]->getName() << " - " << allRooms[x]->getAmount() << " - " << "$" << allRooms[x]->getPrice() << " a night" << endl;
        }   
    }
    MyFile << endl;
    MyFile << "AVAILABLE ROOMS LEFT: " << endl;
    for(int x=0; x<SIZE;x++){
    if(allRooms[x]->getAmount()!=0){
        MyFile << allRooms[x]->getName() << " - " << allRooms[x]->getAmount() << " - " << "$" << allRooms[x]->getPrice() << " a night" << endl;
        }   
    }
    MyFile << endl;
    MyFile << "BOOKING LIST: " << endl;
    map<int,string>::iterator it= roomToNames.begin();

    while (it != roomToNames.end()) {
        cout << "Room Number: " << it->first
             << ", Guest Name: " << it->second << endl;
      MyFile << "Room Number: " << it->first
             << ", Guest Name: " << it->second << endl;
        ++it;
    }   
    MyFile.close();

    mainMenu();

}

void menuOption5(){
    //need to work on this
    string myText;
    ifstream MyReadFile("fileDate");
    while (getline (MyReadFile, myText)) {
    cout << myText << endl;
    }
    MyReadFile.close();
}

void spacer(){
    cout << endl;
}

void banner(int total){
    for(int x = 0; x<total; x++){
        cout << "-";
    }
    spacer();
}

void confirmationMsg(Rooms &r){
    //will iterate name array and therefore produce the roomnumbers associated with them
    banner(30);
    cout << "* Reservation confirmed *" << endl;
    banner(30);
    cout << "Title: " << r.getName() << endl;
    cout << "Price: $" << r.getPrice() << endl;

    if(r.getName() == "Standard Rooms, Courtyard"){
        cout << "Room Number: " << courtyardRoomNums[courtyardIterator] << endl;
    }
    else if(r.getName() == "Standard Room, Scenic"){
        cout << "Room Number: " << scenicRoomNums[scenicIterator] << endl;
    }
    else if(r.getName() == "Deluxe Suite"){
        cout << "Room Number: " << suiteRoomNums[suiteIterator] << endl;
    }
    else{
        cout << "Room Number: " << penthouseRoomNums[penthouseIterator] << endl;
    }
    banner(30);
}
    
void error(){
    cout << "Invalid response. Please retry." << endl;
}

void amountCheck(Rooms &r){
    if(r.getAmount()!=0){
        r.setAmount(r.getAmount()-1);
        confirmationMsg(r);
    }
    else if(r.getAmount()==0){
        cout << "No rooms available." << endl;
    }
}

void namePrompt(){
    cout << "Enter name of guest: ";
    
}