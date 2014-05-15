#include <stdlib.h>
#include <time.h>

void random (char board[SIZE][SIZE])
//We must use #include<time.h> and #include<stdlib.h>.
{int randRow,randColumn;
 char columnName;
 srand(time (NULL));

    do
    {
      randRow=1+rand()%SIZE;
      randColumn=1+rand()%SIZE;
      columnName=turn_name(columnNumber);//This function turn the columnNumber in to a letter;

    }while(!validate(board,columnName,randRow));

    board[randRow-1][randColumn-1]=PIECE;//Piece is a constant define char '#'

}
