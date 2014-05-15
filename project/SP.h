#ifndef SP_H_INCLUDED
#define SP_H_INCLUDED

#include "data_structs.h"

int validate (char board [MAX_BOARDSIZE][MAX_BOARDSIZE], int column, int row);
void random_cpu (char board[MAX_BOARDSIZE][MAX_BOARDSIZE]);
int finish_game (char board [MAX_BOARDSIZE][MAX_BOARDSIZE],int columnName,int rowNumber);
int diagonally1 (char board [MAX_BOARDSIZE][MAX_BOARDSIZE],int columnNumber,int rowNumber);
int diagonally2 (char board [MAX_BOARDSIZE][MAX_BOARDSIZE],int columnNumber,int rowNumber);
int horizontal (char board [MAX_BOARDSIZE][MAX_BOARDSIZE],int columnNumber,int rowNumber);
int vertical (char board [MAX_BOARDSIZE][MAX_BOARDSIZE],int columnNumber,int rowNumber);
void smart (char board[MAX_BOARDSIZE][MAX_BOARDSIZE]);
void write(char board[MAX_BOARDSIZE][MAX_BOARDSIZE]);
int finish_gamePL(char board[MAX_BOARDSIZE][MAX_BOARDSIZE]);

#endif // SP_H_INCLUDED
