#ifndef BOARD_H
#define BOARD_H
#include "functions.h"

class Board
{
    friend class Game;
    friend class Ai;
    friend class Move;
protected:
    int itsGridSize;
    Box itsBoard[9][9];
private:
public:
    Board(int aSize);
    bool gameIsOver(Player& player1, Player& player2);
    void displayBoard();
    void initializeBoard();
    void save();
    int CountEmptyBoxes();
};

#endif // BOARD_H
