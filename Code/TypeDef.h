#ifndef TYPEDEF_H
#define TYPEDEF_H
#include <iostream>
#include <map>
#include <cstdlib>
#include <time.h>
#include <conio.h>
#include <windows.h>

using namespace std;

enum State {
    BLANK,
    PLAYER1,
    PLAYER2
};

struct Box {
    State state;
};

struct Player {
    string itsName;
    bool hasWon=false;
    int itsId;
};

struct Coordinates {
    int itsLine;
    int itsColumn;
};


#endif // TYPEDEF_H
