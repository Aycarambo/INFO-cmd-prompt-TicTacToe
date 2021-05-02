#ifndef HUMAN_H
#define HUMAN_H

#include "move.h"

class Human
{
private:
    Player player;
public:
    Human(Player aPlayer);
    void makeAMove(Board& aBoard);
};

#endif // HUMAN_H
