#ifndef TIC_TAC_TOE_H  
#define TIC_TAC_TOE_H  

#include <stdio.h>
#include <stdbool.h>


void startGame(); 
void printBoard(); 
void computersMove(); 
void playersMove(); 

bool isBoardFull(); 
bool areThreeInRow(char, char, char); 
bool isThereWinner(); 
bool isLineComplete(char); 

#endif  
