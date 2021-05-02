#ifndef GAME_H
#define GAME_H
#include "human.h"
#include "ai.h"


class Game
{
private:
    int chosenGamemode;
public:
    Game(int aChosenGamemode);
    void PlayAGame();
    void randomPlayerIDs(Player& player1, Player& player2);
};

#endif // GAME_H
