#include <stdio.h>
#include <stdbool.h>
#include "tic_tac_toe.h"

extern int row, column, playersTurn, playersNumber;
extern char playBoard[3][3];

int main() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            playBoard[i][j] = ' ';

    startGame();
    printBoard();

    playersTurn = 1;
    while(true){
        if(playersTurn == 1)
            playersMove();
        else{
            if(playersNumber == 2) 
                playersMove();   
            else{
                computersMove(); 
                printf("Computer's move:\n");
                printBoard();
            }
        }
        if(isThereWinner())
            break;

        if(isBoardFull()){
            printf("It's a draw!\n");
            break;
        }

        playersTurn = (playersTurn == 1) ? 2 : 1;
    }

    printf("Game over!\n");
    return 0;
}
