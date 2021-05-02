#include "board.h"

/**
 * @brief Board::initializeBoard initialise les cases du plateau en leur donnant le state BLANK
 */
void Board::initializeBoard()
{
    for (int line=0; line<itsGridSize; line++)
    {
        for (int column=0; column<itsGridSize; column++)
        {
            itsBoard[line][column].state=BLANK;
        }
    }
}

Board::Board(int aSize)
{
    itsGridSize=aSize;
    initializeBoard();
}

/**
 * @brief Board::gameIsOver vérifie si la partie est finie. Si un joueur a gagné, change la valeur de son attribut 'hasWon' en true.
 * @param player1 Le joueur 1
 * @param player2 Le joueur 2
 * @return true si la partie est finie (il n'y a plus de cases vides et/ou un joueur à aligné assez de cases)
 */
bool Board::gameIsOver(Player &player1, Player &player2)
{
    bool gameIsOver=false;
    int BoxesOfSamePlayerInARow=1;
    string winningPlayer="";

    //checking every line
    for(int line=0; line<itsGridSize and !gameIsOver; line++)
    {
        if(itsBoard[line][0].state!=BLANK) //if the first box is blank, no need to check the whole line
        {
            for(int column=1; column<itsGridSize; column++)
            {
                if(itsBoard[line][column].state==itsBoard[line][0].state) //comparing the current box with the first box of the line
                {
                    BoxesOfSamePlayerInARow++;
                }
            }

            if(BoxesOfSamePlayerInARow==itsGridSize) //if all the boxes on a line have the same value (except BLANK)
            {
                gameIsOver=true;
                if(itsBoard[line][0].state==PLAYER1)
                {player1.hasWon=true;}
                else
                {player2.hasWon=true;}
            }
            else
            {
                BoxesOfSamePlayerInARow=1;
            }
        }
    }

    //checking every column
    for(int column=0; column<itsGridSize and !gameIsOver; column++)
    {
        if(itsBoard[0][column].state!=BLANK) //if the first box is blank, no need to check the whole column
        {
            for(int line=1; line<itsGridSize; line++)
            {
                if(itsBoard[line][column].state==itsBoard[0][column].state) //comparing the current box with the first box of the column
                {
                    BoxesOfSamePlayerInARow++;
                }
            }

            if(BoxesOfSamePlayerInARow==itsGridSize) //if all the boxes on a column have the same value (except BLANK)
            {
                gameIsOver=true;
                if(itsBoard[0][column].state==PLAYER1)
                {player1.hasWon=true;}
                else
                {player2.hasWon=true;}
            }
            else
            {
                BoxesOfSamePlayerInARow=1;
            }
        }
    }

    //checking upper left to bottom right diagonal
    for(int i=1; i<itsGridSize and !gameIsOver; i++)
    {
        if(itsBoard[i][i].state==itsBoard[0][0].state) //comparing the current box with the first box of the diagonal
        {
            BoxesOfSamePlayerInARow++;
        }

        if(BoxesOfSamePlayerInARow==itsGridSize) //if all the boxes on the diagonal have the same value (except BLANK)
        {
            gameIsOver=true;
            if(itsBoard[0][0].state==PLAYER1)
            {player1.hasWon=true;}
            else
            {player2.hasWon=true;}
        }
        else
        {
            BoxesOfSamePlayerInARow=1;
        }
    }

    //checking upper right to bottom left diagonal
    for(int i=1; i<itsGridSize and !gameIsOver; i++)
    {
        if(itsBoard[i][itsGridSize-i].state==itsBoard[0][itsGridSize].state) //comparing the current box with the first box of the diagonal
        {
            BoxesOfSamePlayerInARow++;
        }

        if(BoxesOfSamePlayerInARow==itsGridSize) //if all the boxes on the diagonal have the same value (except BLANK)
        {
            gameIsOver=true;
            if(itsBoard[0][itsGridSize].state==PLAYER1)
            {player1.hasWon=true;}
            else
            {player2.hasWon=true;}
        }
        else
        {
            BoxesOfSamePlayerInARow=1;
        }
    }

    //check for draw
    if(CountEmptyBoxes()==0)
    {
        gameIsOver=true;
    }
    return gameIsOver;
}

/**
 * @brief Board::displayBoard affiche le plateau de jeu
 */
void Board::displayBoard()
{
    cout <<"       colonnes >\t\n";
    cout <<"         lignes ˇ ";

    for (int column=0; column<itsGridSize; column++)
    {
        cout << column+1 << "   ";
    }
    cout << endl;

    for (int line=0; line<itsGridSize; line++)
    {
        cout << "\t\t" << line+1;
        for (int column=0; column<itsGridSize; column++)
        {
            cout << '[' << stateToChar(itsBoard[line][column].state) << "] ";
        }
        cout << endl << endl;

    }
}

/**
 * @brief Board::CountEmptyBoxes compte le nombre de cases vides. Utile pour vérifier si il y a une égalité
 * @return le nombre de cases vides
 */
int Board::CountEmptyBoxes()
{
    int count=0;
    for (int line=0; line<itsGridSize; line++)
    {
        for (int column=0; column<itsGridSize; column++)
        {
            if(itsBoard[line][column].state==BLANK)
            {count++;}
        }
    }
    return count;
}
