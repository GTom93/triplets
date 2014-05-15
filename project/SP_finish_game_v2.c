#include "data_structs.h"
#include "SP.h"

/* Number of aligned pieces that are needed to finish the game */
#define NUM_ALIGNED_PIECES_FINISH  (3)




int finish_game (char board [MAX_BOARDSIZE][MAX_BOARDSIZE],int columnNumber,int rowNumber)
{
    // FIXME: not needed
    //int columnNumber,i,j;
    //columnNumber=turn_name(columnName);//This function turn the columnName in to a number;
  if(diagonally1(board,columnNumber,rowNumber)||diagonally2(board,columnNumber,rowNumber)||horizontal(board,columnNumber,rowNumber)||vertical(board,columnNumber,rowNumber))
    return 1;
  else
    return 0;
    }

int diagonally1 (char board [MAX_BOARDSIZE][MAX_BOARDSIZE],int columnNumber,int rowNumber)
{
    int contador = 0,i=columnNumber,j=rowNumber;
            while (board[i][j]==PIECE&&i>0&&j>0)
            {
               i--;
                j--;
            }

            while (board[i][j]==PIECE && contador < NUM_ALIGNED_PIECES_FINISH)
            {
                contador++;


                i++;
                j++;
            }
if (contador==3)
    return 1;
else return 0;

}

int diagonally2 (char board [MAX_BOARDSIZE][MAX_BOARDSIZE],int columnNumber,int rowNumber)
{
    int contador = 0,i=columnNumber,j=rowNumber;
            while (board[i][j]==PIECE&&i<MAX_BOARDSIZE&&j<MAX_BOARDSIZE)
            {
               i++;
                j--;
            }

            while (board[i][j]==PIECE && contador < NUM_ALIGNED_PIECES_FINISH)
            {
                contador++;


                i--;
                j++;
            }
if (contador==(NUM_ALIGNED_PIECES_FINISH-1)){
    return 1;
}
else{
    return 0;
}

}

 int horizontal (char board [MAX_BOARDSIZE][MAX_BOARDSIZE],int columnNumber,int rowNumber)
{
 if((((board[rowNumber][columnNumber-1]==PIECE)&&(columnNumber-1>0))&&((board[rowNumber][columnNumber-2]==PIECE)&&(columnNumber-2>0)))||(((board[rowNumber][columnNumber-1]==PIECE)&&(columnNumber-1>0))&&((board[rowNumber][columnNumber+1]==PIECE)&&(columnNumber+1<13)))||(((board[rowNumber][columnNumber+1]==PIECE)&&(columnNumber+1<13))&&((board[rowNumber][columnNumber+2]==PIECE)&&(columnNumber+2<13))))
    return 1;
 else
    return 0;
}
int vertical (char board [MAX_BOARDSIZE][MAX_BOARDSIZE],int columnNumber,int rowNumber)
{
 if((((board[rowNumber-1][columnNumber]==PIECE)&&(rowNumber-1>0))&&((board[rowNumber-2][columnNumber]==PIECE)&&(rowNumber-2>0)))||(((board[rowNumber-1][columnNumber]==PIECE)&&(rowNumber-1>0))&&((board[rowNumber+1][columnNumber]==PIECE)&&(rowNumber+1<13)))||(((board[rowNumber+1][columnNumber]==PIECE)&&(rowNumber+1<13))&&((board[rowNumber+2][columnNumber]==PIECE)&&(rowNumber+2<13))))
    return 1;
 else
    return 0;
}

