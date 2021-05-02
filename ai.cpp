#include "ai.h"
#include <vector>

Ai::Ai(Player aPlayer)
{
    itsPlayer=aPlayer;
}

/**
 * @brief Ai::calcTurn calcul le meilleur coup pour l'IA
 * @param aMove le coup
 * @param aBoard    le plateau sur lequel jouer le coup
 */

void Ai::calcTurn(/*Move &aMove, */Board &aBoard) {
    int size=aBoard.itsGridSize;
    int theMatrix[size][size];
    State *opponentState = nullptr;
    State *aiState = nullptr;

    if(itsPlayer.itsId==1)
    {
        *aiState=PLAYER1;
        *opponentState=PLAYER2;
    }
    else
    {
        *aiState=PLAYER2;
        *opponentState=PLAYER1;
    }

    // initialisation de la matrice
    for (int leA = 0; leA < size; leA++){
        for (int leB = 0; leB < size; leB++){
            theMatrix[leA][leB] = 0;
        }
    }
    for (int leA = 0; leA < size; leA++)
    {
        bool estVide = true;
        for (int leC = 0; leC < size; leC++)
        {
            if (aBoard.itsBoard[leA][leC].state == *opponentState)
            {
                estVide = false;
            }
        }
        if (estVide)
        {
            for (int leB = 0; leB < size; leB++)
            {
                if (aBoard.itsBoard[leA][leB].state != *aiState)
                {
                    //theMatrix[leA][leB] += calcBonus(aBoard.itsBoard[leA], *aiState, 15);
                }
            }
        }
        estVide = true;
        for (int leC = 0; leC < size; leC++)
        {
            if (aBoard.itsBoard[leA][leC].state == *aiState)
            {
                estVide = false;
            }
        }
        if (estVide)
        {
            for (int leB = 0; leB < size; leB++)
            {
                if (aBoard.itsBoard[leA][leB].state != *opponentState)
                {
                    //theMatrix[leA][leB] += calcBonus(aBoard.itsBoard[leA], *opponentState, 10);
                }
            }
        }
    }
    vector<char> theVector;
    for (int leA = 0; leA < size; leA++)
    {
        //theVector.push_back(aBoard.itsBoard[leA][leA]); // diff du java
    }
    bool estVide = true;
    for (int leC = 0; leC < size; leC++)
    {
        if (theVector[leC] == *opponentState)
        {
            estVide = false;
        }
    }
    if (estVide)
    {
        for (int leA = 0; leA < size; leA++)
        {
            if (aBoard.itsBoard[leA][leA].state != *aiState)
            {
                //theMatrix[leA][leA] += calcBonus(theVector, *aiState, 15);
            }
        }
    }
    estVide = true;
    for (int leC = 0; leC < size; leC++)
    {
        if (theVector[leC] == *aiState){
            estVide = false;
        }
    }
    if (estVide)
    {
        for (int leA = 0; leA < size; leA++)
        {
            if (aBoard.itsBoard[leA][leA].state != *opponentState)
            {
                //theMatrix[leA][leA] += calcBonus(theVector, *opponentState, 10);
            }
        }
    }
    for (int leA = 0; leA < size; leA++)
    {
        //theVector[leA] = aBoard.itsBoard[(size-1)-leA][leA];
    }
    estVide = true;
    for (int leC = 0; leC < size; leC++)
    {
        if (theVector[leC] == *opponentState)
        {
            estVide = false;
        }
    }
    if (estVide)
    {
        for (int leA = 0; leA < size; leA++)
        {
            if (aBoard.itsBoard[(size-1)-leA][leA].state != *aiState)
            {
                //theMatrix[(size-1)-leA][leA] += calcBonus(theVector, *aiState, 15);
            }
        }
    }
    estVide = true;
    for (int leC = 0; leC < size; leC++)
    {
        if (theVector[leC] == *aiState)
        {
            estVide = false;
        }
    }
    if (estVide)
    {
        for (int leA = 0; leA < size; leA++)
        {
            if (aBoard.itsBoard[(size-1)-leA][leA].state != *opponentState)
            {
                //theMatrix[(size-1)-leA][leA] += calcBonus(theVector, *opponentState, 10);
            }
        }
    }
    for (int leA = 0; leA < size; leA++)
    {
        for (int leB = 0; leB < size; leB++)
        {
            //theVector[leB] = aBoard.itsBoard[leB][leA];
        }
        estVide = true;
        for (int leC = 0; leC < size; leC++)
        {
            if (theVector[leC] == *opponentState)
            {
                estVide = false;
            }
        }
        if (estVide)
        {
            for (int leB = 0; leB < size; leB++)
            {
                if (aBoard.itsBoard[leB][leA].state != *aiState)
                {
                    //theMatrix[leB][leA] += calcBonus(theVector, *aiState, 15);
                }
            }
        }
        estVide = true;
        for (int leC = 0; leC < size; leC++)
        {
            if (theVector[leC] == *aiState)
            {
                estVide = false;
            }
        }
        if (estVide)
        {
            for (int leB = 0; leB < size; leB++)
            {
                if (aBoard.itsBoard[leB][leA].state != *opponentState)
                {
                    //theMatrix[leB][leA] += calcBonus(theVector, *opponentState, 10);;
                }
            }
        }
    }
int leMax = theMatrix[0][0];
//    int aX = 0;
//    int aY = 0;
    for (int leA = 0; leA < size; leA++){
        for (int leB = 0; leB < size; leB++){
            if (theMatrix[leA][leB] > leMax){
                leMax = theMatrix[leA][leB];
//                aX = leA;
//                aY = leB;
            }
        }
    }
}

/**
 * @brief Ai::calculerBonus
 * @param unVecteur
 * @param unJoueur
 * @param unCoeff
 * @return
 */

int Ai::calcBonus(char unVecteur[], char unJoueur, int unCoeff)
{
    int leBonus = 0;
    int leCompteur = 0;
    for (int leA = 0; leA < 3; leA++){
        if (unVecteur[leA] == unJoueur){
            leCompteur++;
        }
    }
    if (leCompteur == 1){
        leBonus = unCoeff / unCoeff;
    }
    if (leCompteur == 2){
        leBonus = unCoeff;
    }
    return leBonus;
}
