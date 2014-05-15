#include "data_structs.h"


int finish_game (char board [MAX_BOARDSIZE][MAX_BOARDSIZE],int columnName,int rowNumber)
{
	int columnNumber,i,j;
	columnNumber = turn_name(columnName);//This function turn the columnName in to a number;
	if(diagonally(board,columnNumber-1,rowNumber-1)||horizontal(board,columnNumber-1,rowNumber-1)||vertical(board,columnNumber-1,rowNumber-1))
		return 1;
	else
		return 0;
}

int diagonally (char board [MAX_BOARDSIZE][MAX_BOARDSIZE],int columnNumber,int rowNumber)
{
  if((((board[rowNumber-1][columnNumber-1]==PIECE)&&(rowNumber-1>=0)&&(columnNumber-1>=0))&&((board[rowNumber-2][columnNumber-2]==PIECE)&&(rowNumber-2>=0)&&(columnNumber-2>=0)))||(((board[rowNumber-1][columnNumber-1]==PIECE)&&(rowNumber-1>=0)&&(columnNumber-1>=0))&&((board[rowNumber+1][columnNumber+1]==PIECE)&&(rowNumber+1<MAX_BOARDSIZE)&&(columnNumber+1<MAX_BOARDSIZE)))||(((board[rowNumber+1][columnNumber+1]==PIECE)&&(rowNumber+1<MAX_BOARDSIZE)&&(columnNumber+1<MAX_BOARDSIZE))&&((board[rowNumber+2][columnNumber+2]==PIECE)&&(rowNumber+2<MAX_BOARDSIZE)&&(columnNumber+2<MAX_BOARDSIZE)))||(((board[rowNumber-1][columnNumber+1]==PIECE)&&(rowNumber-1>=0)&&(columnNumber+1<MAX_BOARDSIZE))&&((board[rowNumber-2][columnNumber+2]==PIECE)&&(rowNumber-2>=0)&&(columnNumber+2<MAX_BOARDSIZE)))||(((board[rowNumber-1][columnNumber+1]==PIECE)&&(rowNumber-1>=0)&&(columnNumber+1<MAX_BOARDSIZE))&&((board[rowNumber+1][columnNumber-1]==PIECE)&&(rowNumber+1<MAX_BOARDSIZE)&&(columnNumber-1>=0)))||(((board[rowNumber+1][columnNumber-1]==PIECE)&&(rowNumber+1<MAX_BOARDSIZE)&&(columnNumber-1>=0))&&((board[rowNumber+2][columnNumber-2]==PIECE)&&(rowNumber+2<MAX_BOARDSIZE)&&(columnNumber-2>=0))))
     return 1;
  else
     return 0;
}
 int horizontal (char board [MAX_BOARDSIZE][MAX_BOARDSIZE],int columnNumber,int rowNumber)
{
 if((((board[rowNumber][columnNumber-1]==PIECE)&&(columnNumber-1>=0))&&((board[rowNumber][columnNumber-2]==PIECE)&&(columnNumber-2>=0)))||(((board[rowNumber][columnNumber-1]==PIECE)&&(columnNumber-1>=0))&&((board[rowNumber][columnNumber+1]==PIECE)&&(columnNumber+1<MAX_BOARDSIZE)))||(((board[rowNumber][columnNumber+1]==PIECE)&&(columnNumber+1<MAX_BOARDSIZE))&&((board[rowNumber][columnNumber+2]==PIECE)&&(columnNumber+2<MAX_BOARDSIZE))))
    return 1;
 else
    return 0;
}
int vertical (char board [MAX_BOARDSIZE][MAX_BOARDSIZE],int columnNumber,int rowNumber)
{
 if((((board[rowNumber-1][columnNumber]==PIECE)&&(rowNumber-1>=0))&&((board[rowNumber-2][columnNumber]==PIECE)&&(rowNumber-2>=0)))||(((board[rowNumber-1][columnNumber]==PIECE)&&(rowNumber-1>=0))&&((board[rowNumber+1][columnNumber]==PIECE)&&(rowNumber+1<MAX_BOARDSIZE)))||(((board[rowNumber+1][columnNumber]==PIECE)&&(rowNumber+1<MAX_BOARDSIZE))&&((board[rowNumber+2][columnNumber]==PIECE)&&(rowNumber+2<MAX_BOARDSIZE))))
    return 1;
 else
    return 0;
}

