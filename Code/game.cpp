#include "game.h"

Game::Game(int aChosenGamemode)
{
    chosenGamemode=aChosenGamemode;
}

/**
 * @brief Game::PlayAGame Déroulement d'une partie
 */
void Game::PlayAGame()
{
    string boardSize;
    Player alpha;
    Player bravo;

    cout << "Entrez la taille de la grille :";
    cin >> boardSize;

    while (boardSize.length()>1 or stoi(boardSize)>9 or stoi(boardSize)<1)
    {
        cout << "Erreur : Entrez une taille de grille entre 1 et 9\n";
        cout << "Entrez la taille de la grille :";
        cin >> boardSize;
    }
    Board board(stoi(boardSize));
    board.displayBoard();


    cout << "Entrez le nom du joueur1/IA1 :";
    cin >> alpha.itsName;
    cout << "Entrez le nom du joueur2/IA2 :";
    cin >> bravo.itsName;
    clearScreenAfterInput();


    randomPlayerIDs(alpha, bravo);
    Player* firstPlayer;
    Player* secondPlayer;
    if(alpha.itsId==1)
    {
        cout << "Le hasard a décidé que ce serait à "  << alpha.itsName << " de commencer !\n";
        firstPlayer=&alpha;
        secondPlayer=&bravo;
    }
    else
    {
        cout << "Le hasard a décidé que ce serait à "  << bravo.itsName << " de commencer !\n";
        firstPlayer=&bravo;
        secondPlayer=&alpha;
    }
    clearScreenAfterInput();

    if(chosenGamemode!=1)
    {
        cout << "Malheureusement seul le mode humain vs humain fonctionne. Redirection vers ce mode de jeu.";
        chosenGamemode=1;
    }
    if(chosenGamemode==1)
    {
        Human human1(*firstPlayer);
        Human human2(*secondPlayer);

        while(!board.gameIsOver(alpha, bravo))
        {
            human1.makeAMove(board);
            clearScreenAfterInput();
            if(!board.gameIsOver(alpha, bravo))
            {
                human2.makeAMove(board);
                clearScreenAfterInput();
            }
        }
        if(alpha.hasWon)
        {
            cout << alpha.itsName;
            if(alpha.itsId==1)
            {cout << "(X) a gagné !\n";}
            else
            {cout << "(O) a gagné !\n";}
            board.displayBoard();
        }
        else if(bravo.hasWon)
        {
            cout << bravo.itsName;
            if(bravo.itsId==1)
            {cout << "(X) a gagné !\n";}
            else
            {cout << "(O) a gagné !\n";}
            board.displayBoard();
        }
        else
        {
            cout << "égalité !\n";
            board.displayBoard();
        }

    }




}

/**
 * @brief Game::randomPlayerIDs Modifie l'attribut itsId des joueurs en choississant aléatoirement qui sera le joueur 1 et qui sera le joueur 2
 * @param player1 un joueur
 * @param player2 un joueur
 */
void Game::randomPlayerIDs(Player &player1, Player &player2)
{
    if(rand()%2==0)
    {
        player1.itsId=1;
        player2.itsId=2;
    }
    else
    {
        player1.itsId=2;
        player2.itsId=1;
    }
}


