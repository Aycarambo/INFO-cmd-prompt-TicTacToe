#include "functions.h"

/**
 * @brief stateToChar renvoie un charactère en fonction d'un State
 * @param state
 * @return ' ' si state=BLANK ; 'X' si state=PLAYER1 ; 'O' si state=PLAYER2 (renvoie ' ' par défaut)
 */
char stateToChar(State state)
{
    switch (state) {
        case BLANK : return ' ';
        case PLAYER1 : return 'X';
        case PLAYER2 : return 'O';
    }
    return ' ';
}

/**
 * @brief clearScreen nettoie l'écran et affiche le menu du jeu
 */
void clearScreen()
{
    system("cls");
    cout << "A2 STANISLAS Lucas'\n";
    cout << " _____  _         _____              _____           \n";
    cout << "|_   _||_| ___   |_   _| ___  ___   |_   _| ___  ___ \n";
    cout << "  | |  | ||  _|    | |  | .'||  _|    | |  | . || -_|\n";
    cout << "  |_|  |_||___|    |_|  |__,||___|    |_|  |___||___|\n\n\n";
}

/**
 * @brief clearScreenAfterInput nettoie l'écran après l'appuie sur une touche du clavier et affiche le menu du jeu
 */
void clearScreenAfterInput()
{
    cout << "Appuyer sur une touche pour continuer";
    getch();
    system("cls");
    cout << "A2 STANISLAS Lucas'\n";
    cout << " _____  _         _____              _____           \n";
    cout << "|_   _||_| ___   |_   _| ___  ___   |_   _| ___  ___ \n";
    cout << "  | |  | ||  _|    | |  | .'||  _|    | |  | . || -_|\n";
    cout << "  |_|  |_||___|    |_|  |__,||___|    |_|  |___||___|\n\n\n";
}
