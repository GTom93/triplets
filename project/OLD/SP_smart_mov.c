void smart (char board[SIZE][SIZE])
{int i,j, m=3;
 char columnName;
   if(emptyboard(board)){
    random(board);
   }

   else
   for(i=1;i<SIZE&&m!=0;i++){
    for(j=1;j<SIZE&&m!=0;j++){
        if(board[i][j]!=PIECE){
           columnName=turn_name(j+1);//This function turn the columnNumber in to a letter;
           if(validate(board,columnName,i-2)){
            board[i-2][j-1]=PIECE;
            m=0;
            }
              else if (validate(board,j-1,i+2)){
                board[i+2][j-1]=PIECE;
                m=0;
              }

              columnName=turn_name(j+1);
                 else if (validate(board,columnName,i-2)){
                   board[i-2][j+1]=PIECE;
                   m=0;
                 }
                    else if (validate(board,j+1,i+2)){
                      board[i+2][j+1]=PIECE;
                      m=0;
                    }

                    columnName=turn_name(j+2);
                       else if (validate(board,columnName,i-1)){
                         board[i-1][j+2]=PIECE;
                         m=0;
                       }

                          else if (validate(board,j+2,i+1)){
                           board[i+1][j+2]=PIECE;
                           m=0;
                          }

                             columnName=turn_name(j-2);
                              else if (validate(board,j-2,i+1)){
                                board[i+1][j-2]=PIECE;
                                m=0;
                              }
                                    else if (validate(board,j-2,i-1)){
                                       board[i-1][j-2]=PIECE;
                                       m=0;
                                    }
        }

        }
    }
   }


int emptyboard(char board[SIZE][SIZE])
{ int i, j;

 for(i=1;i<13;i++){
    for(j=1;j<13;j++){
        if(board[i][j]!=EMPTY)
            return 0;
        }
    }
     return 1;

 } 

