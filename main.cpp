#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <cstring>
#include "Room.h"
using namespace std;

struct items {//struct of items w/ default locations
    int LPSet = 8;
    int key = 7;
    int textbook = 5;
    int beaker = 10; 
    int ball = 14;
};
//initialize functions
void printItem(Room** list, int current, items location); 
void dropItem(Room** list, int current, items &location); 
void pickItem(Room** list, int current, items &location); 
void printLocation(Room** list, int current, items location);
void printExits(Room** list, int current);
void move(Room** list, int &current);

int main() {//main method
    //initialize Rooms and variables 
    int current = 8;
    Room* list[15];
    list[0] = new Room("You are in Ms. Werner's room. Everyone is attentively watching a exceptional StarWars presentation.", 1, "Z", 0, "Z", 0, "S", 2, "Z", 0);
    list[1] = new Room("You are in Hallway 2. Someone is blasting their portable speaker.", 2, "N", 1, "E", 7, "S", 3, "W", 10);
    list[2] = new Room("You are in Hallway 1. A hallway monitor is coming torwards you.", 3, "N", 2, "E", 8, "S", 4, "W", 11);
    list[3] = new Room("You are in Hallway 3. Why is the Principal here.", 4, "N", 3, "E", 9, "S", 5, "W", 12);
    list[4] = new Room("You are in Ms. McNamee's room. Are they doing a test without the signature TI INSPIRE CXCalculator", 5, "N", 4, "Z", 0, "Z", 0, "Z", 0);
    list[5] = new Room("You are outside! Chiphttps://github.com/PujanHPatel/Zuulotle?", 6, "Z", 0, "Z", 0, "S", 7, "Z", 0);
    list[6] = new Room("You are in the Office. I thought the counselors wasn't here today?", 7, "N", 6, "E", 15, "Z", 0, "W", 2);
    list[7] = new Room("You are in the Computer Lab with Mr.Galbraith. Its a chill place, you should stay.", 8, "Z", 0, "Z", 0, "Z", 0, "W", 3);
    list[8] = new Room("You are in the library. Might want to leave before they find out you have an overdue book.", 9, "Z", 0, "Z", 0, "Z", 0, "W", 4);
    list[9] = new Room("You are in Ms. Riske's room. Was that an explosion?", 10, "Z", 0, "E", 2, "S", 11, "W", 13);
    list[10] = new Room("You are in the Lunch Room. Wanna eat?", 11, "N", 10, "E", 3, "S", 12, "W", 14);
    list[11] = new Room("You are in Ms. Taylo's room. Everyones chillin.", 12, "N", 11, "E", 4, "Z", 0, "Z", 0);
    list[12] = new Room("You are in Mr. Burg's room. Are they doing hurdles?", 13, "Z", 0, "E", 10, "S", 14, "Z", 0);
    list[13] = new Room("You are in the Gym. Should greet Mr. Salness.", 14, "Z", 0, "E", 11, "Z", 0, "Z", 0);
    list[14] = new Room("You are in the Teachers Lounge. Do they really get free donuts?", 15, "Z", 0, "Z", 0, "Z", 0, "W", 7);
    struct items location;
    char input[80];

    while(current != 6) {//while you haven't escaped, keep playing
        cout << "PICK, DROP, PRINT, MOVE" << endl;
        printLocation(list, current, location);
        cin >> input;
        if(strcmp(input, "PICK") == 0) {//if PICK, pick items
            pickItem(list, current, location);    
        }
        else if(strcmp(input, "DROP") == 0) {//if DROP, drop Items
            dropItem(list, current, location);    
        }
        else if(strcmp(input, "PRINT") == 0) {//if PRINT, print inventory
            printItem(list, current, location);    
        }
        else if(strcmp(input, "MOVE") == 0) {//if Move, print exits and move
            printExits(list, current);
            move(list, current);
        }
    }
    cout << "You are outside! Chipotle?" << endl; //Game Over
    return 0;
}
void printItem(Room** list, int current, items location) {//print Items
    if(location.LPSet == 0) {
        cout << "You have a Lock Pick Set" << endl;
    }
    if(location.key == 0) {
        cout << "You have a Key" << endl;
    }
    if(location.beaker == 0) {
        cout << "You have a Beaker" << endl;
    }
    if(location.textbook == 0) {
        cout << "You have a Textbook" << endl;
    }
    if(location.ball == 0) {
        cout << "you have a Basket Ball" << endl;
    }
}
void pickItem(Room** list, int current, items &location) {//pick Items
    if(location.LPSet == current) {
        location.LPSet = 0;
    }
    if(location.key == current) {
        location.key = 0;
    }
    if(location.beaker == current) {
        location.beaker = 0;
    }
    if(location.textbook == current) {
        location.textbook = 0;
    }
    if(location.ball == current) {
        location.ball = 0;
    }
}
void dropItem(Room** list, int current, items &location) {//drop Items
    if(location.LPSet == 0) {
        location.LPSet = current;
    }
    if(location.key == 0) {
        location.key = current;
    }
    if(location.beaker == 0) {
        location.beaker = current;
    }
    if(location.textbook == 0) {
        location.textbook = current;
    }
    if(location.ball == 0) {
        location.ball = current;
    }
}
void printLocation(Room** list, int current, items location) {//print current Location
    cout << list[current-1]->description << endl;
    if(location.LPSet == current) {
        cout << "There is a Lock Pick Set here. Maybe use it to break into the Office?" << endl;
    }
    if(location.key == current) {
        cout << "There is a Key here. Maybe use it to escape?" << endl;
    }
    if(location.beaker == current) {
        cout << "There is a Beaker here." << endl;
    }
    if(location.textbook == current) {
        cout << "There is a Textbook here" << endl;
    }
    if(location.ball == current) {
        cout << "There is a Basket Ball here" << endl;
    }
}
void printExits(Room** list, int current) {//print Exits
    map <string, int> currentExits;
    currentExits = list[current-1]->exits;
    for(map <string, int>::iterator itr = currentExits.begin(); itr != currentExits.end(); ++itr) {
        cout << itr->first << endl;
    }
}
void move(Room** list, int &current) {//move Rooms
    string input;
    cin >> input;
    map <string, int> currentExits;
    currentExits = list[current-1]->exits;
    for(map <string, int>::iterator itr = currentExits.begin(); itr != currentExits.end(); ++itr) {
        if(!input.compare(itr->first)) {
            current = itr->second;
        }
    }
}
