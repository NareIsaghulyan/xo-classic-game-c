#include "tic_tac_toe.h"
#include <stdbool.h>

int row, column, playersTurn, playersNumber; 
char playBoard[3][3]; 

void startGame(){
    printf("Welcome! \nEnter the number  of players! \n"); 
    scanf("%d", &playersNumber); 

    if(playersNumber == 1)
        printf("Player 1 is X! \nComputer is O. \n"); 
    else if(playersNumber == 2)
        printf("Player 1 is X! \nPlayer 2 is O! \n"); 
    else{
        printf("Players' number is not valid. \n"); 
        return; 
    }
}

void printBoard(){
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if(j < 2)
                printf(" %c |", playBoard[i][j]); 
            else    
                printf(" %c ", playBoard[i][j]); 
        }

        printf("\n"); 
        if(i < 2) printf("--- --- --- \n");
    }

    return; 
}

void playersMove(){
    printf("Player %d, please enter the row and the column (0-2): \n", playersTurn); 
    if(scanf("%d %d", &row, &column) != 2){
        printf("Invalid input! Try again.\n");
        int c; while((c = getchar()) != '\n' && c != EOF); 
        playersMove();
        return;
    }

    if(row < 0 || row > 2 || column < 0 || column > 2){
        printf("Invalid field! Try again!\n"); 
        playersMove(); 
        return; 
    }

    if(playBoard[row][column] != ' '){
        printf("The spot is taken! Try again!\n"); 
        playersMove(); 
        return; 
    }

    playBoard[row][column] = (playersTurn == 1) ? 'X' : 'O';

    printBoard(); 
    printf("\n");  
}


bool isLineComplete(char mark){
    for(int i = 0; i < 3; ++i){
        if(playBoard[i][0] == mark && playBoard[i][1] == mark && playBoard[i][2] == ' '){ playBoard[i][2] = 'O'; return true; }
        if(playBoard[i][0] == mark && playBoard[i][2] == mark && playBoard[i][1] == ' '){ playBoard[i][1] = 'O'; return true; }
        if(playBoard[i][1] == mark && playBoard[i][2] == mark && playBoard[i][0] == ' '){ playBoard[i][0] = 'O'; return true; }
    }

    for(int i = 0; i < 3; ++i){
        if(playBoard[0][i] == mark && playBoard[1][i] == mark && playBoard[2][i] == ' '){ playBoard[2][i] = 'O'; return true; }
        if(playBoard[0][i] == mark && playBoard[2][i] == mark && playBoard[1][i] == ' '){ playBoard[1][i] = 'O'; return true; }
        if(playBoard[1][i] == mark && playBoard[2][i] == mark && playBoard[0][i] == ' '){ playBoard[0][i] = 'O'; return true; }
    }

    if (playBoard[0][0] == mark && playBoard[1][1] == mark && playBoard[2][2] == ' ') { playBoard[2][2] = 'O'; return true; }
    if (playBoard[0][0] == mark && playBoard[2][2] == mark && playBoard[1][1] == ' ') { playBoard[1][1] = 'O'; return true; }
    if (playBoard[1][1] == mark && playBoard[2][2] == mark && playBoard[0][0] == ' ') { playBoard[0][0] = 'O'; return true; }

    if (playBoard[0][2] == mark && playBoard[1][1] == mark && playBoard[2][0] == ' ') { playBoard[2][0] = 'O'; return true; }
    if (playBoard[0][2] == mark && playBoard[2][0] == mark && playBoard[1][1] == ' ') { playBoard[1][1] = 'O'; return true; }
    if (playBoard[1][1] == mark && playBoard[2][0] == mark && playBoard[0][2] == ' ') { playBoard[0][2] = 'O'; return true; }

    return false; 
}

void computersMove(){
    if(playersNumber == 1 && playersTurn == 2){
        if(isLineComplete('O')) return;

        if(isLineComplete('X')) return; 

        if(playBoard[1][1] == ' '){ playBoard[1][1] = 'O'; return; }

        int corners[4][2] = {{0,0},{0,2},{2,0},{2,2}};

        for (int i = 0; i < 4; ++i){
            int x = corners[i][0];
            int y = corners[i][1];
            if (playBoard[x][y] == ' '){
                playBoard[x][y] = 'O';
                return;
            }
        }

        for(int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (playBoard[i][j] == ' '){
                    playBoard[i][j] = 'O';
                    return;
                }
    }
}

bool isBoardFull(){
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (playBoard[i][j] == ' ')
                return false; 

    return true; 
}

bool areThreeInRow(char a, char b, char c){
    return (a != ' ' && a == b && a == c);
}


bool isThereWinner(){
    for(int i = 0; i < 3; ++i) 
        if(areThreeInRow(playBoard[i][0], playBoard[i][1], playBoard[i][2]) ||
            areThreeInRow(playBoard[0][i], playBoard[1][i], playBoard[2][i])){
            printf("Player %d won!\n", playersTurn);
            return true;
        }

    if(areThreeInRow(playBoard[0][0], playBoard[1][1], playBoard[2][2]) ||
        areThreeInRow(playBoard[0][2], playBoard[1][1], playBoard[2][0])){
        printf("Player %d won!\n", playersTurn);
        return true;
    }

    return false;
}