#include "move.h"

/**
 * @brief Move::moveIsCorrect vérifie si un coup est valide.
 * @param coord les coordonnées du coup
 * @param aBoard le plateau sur lequel on joue le coup
 * @return true si le coup est valide
 */
bool Move::moveIsCorrect(const Coordinates coord, Board &aBoard)
{
    return(coord.itsLine<aBoard.itsGridSize
           and coord.itsLine>=0
           and coord.itsColumn<aBoard.itsGridSize
           and coord.itsColumn>=0
           and aBoard.itsBoard[coord.itsLine][coord.itsColumn].state==BLANK);
}

/**
 * @brief Move::updateBoard modifie la valeur d'une case du plateau si le coup est valide
 * @param coordinates coordonées du coup
 * @param aBoard plateau sur lequel on joue le coup
 * @param aPlayer le joueur qui joue le coup
 * @return true si le coup à été joué
 */
bool Move::updateBoard(const Coordinates coordinates, Board &aBoard, Player aPlayer)
{
    bool boardUpdatedSuccesfully=false;
    if(moveIsCorrect(coordinates, aBoard))
    {
        if(aPlayer.itsId==1)
        {aBoard.itsBoard[coordinates.itsLine][coordinates.itsColumn].state=PLAYER1;}
        else if(aPlayer.itsId==2)
        {aBoard.itsBoard[coordinates.itsLine][coordinates.itsColumn].state=PLAYER2;}
        boardUpdatedSuccesfully=true;
        clearScreen();
        aBoard.displayBoard();
    }
    else {
        cout << "Erreur : Ce coup ne peut pas être joué\n";
        clearScreenAfterInput();
    }
    return boardUpdatedSuccesfully;
}
