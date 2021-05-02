#ifndef AI_H
#define AI_H
#include "move.h"

using namespace std;

class Ai
{
private:
    Player itsPlayer;
public:
    Ai(Player aPlayer);
    void calcTurn(/*Move &aMove, */Board &aBoard);
    int calcBonus(char unVecteur[], char unJoueur, int unCoeff);
};

#endif // AI_H
