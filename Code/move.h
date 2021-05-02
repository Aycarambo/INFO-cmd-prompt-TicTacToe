#ifndef MOVE_H
#define MOVE_H
#include "board.h"

class Move
{
    friend class Human;
public:
    virtual bool moveIsCorrect(const Coordinates coord, Board& aBoard);
    virtual bool updateBoard(const Coordinates coordinates, Board& aBoard, Player aPlayer);
};

#endif // MOVE_H
