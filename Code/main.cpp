#include "game.h"

using namespace std;

int main()
{
    srand (time(NULL));
    SetConsoleOutputCP( 65001 );

    int gamemode;
    clearScreen();
    cout <<"\t1 : Humain vs Humain\n"
            "\t2 : Humain vs IA\n"
            "\t3 : IA vs IA\n";
    cout << "Choississez un mode de jeu :";
    cin >> gamemode;
    while(gamemode<1 or gamemode>3)
    {
        clearScreen();
        cout << "ERREUR : Entrez un mode de jeu (nombre entre 1 et 3)\n";
        cout <<"\t1 : Humain vs Humain\n"
                "\t2 : Humain vs IA\n"
                "\t3 : IA vs IA\n";
        cout << "Choississez un mode de jeu :";
        cin >> gamemode;
    }
    Game game(gamemode);
    game.PlayAGame();



//    Board board(3);
//    board.initializeBoard();
//    board.displayBoard();

    return 0;
}
