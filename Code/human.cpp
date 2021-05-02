#include "human.h"

Human::Human(Player aPlayer)
{
    Human::player=aPlayer;
}

/**
 * @brief Human::makeAMove CE QUE FAIT LA FOPNCTION
 * @param aBoard A QUOI CORRESPOND LE PARAMETRE
 * @param aPlayer A QUOI CORRESPOND LE PARAMETRE
 */
void Human::makeAMove(Board &aBoard)
{
    string userInput;
    Coordinates coordinates;
    Move aMove;

    do
    {
        clearScreen();
        aBoard.displayBoard();
        cout << "au tour de " << player.itsName;
        if (player.itsId==1)
        {cout << "(X).\n";}
        else
        {cout << "(O).\n";}


        cout << "Entrez des coordonnées :";
        cin >> userInput;
        while(userInput.length()>2 or userInput[0]<49 or userInput[0]>57 or userInput[1]<49 or userInput[1]>57)
        {
            clearScreen();
            aBoard.displayBoard();
            cout << "\t Erreur : coordonnées invalides.";
            cout << "Entrez des coordonnées. (exemple : 12 -> ligne 1, colonne 2) :";
            cin >> userInput;
        }
        coordinates.itsLine=userInput[0]-'1';
        coordinates.itsColumn=userInput[1]-'1';
    }
    while(!aMove.updateBoard(coordinates, aBoard, player));
}
