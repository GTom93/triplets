/**
 * Triplets Game - VIOPE 2014 
 *
 * @creation date	2014-05
 * SP
 **/

void smart (char board[SIZE][SIZE]){
	int i,j, m=3;
	if(emptyboard(board)){
		random(board);
	}
	else if(oneMovFinish(board)=1)
	{
			write(board);
        	printf("\n you have lost the game, I win \n \n");
	}
        else
		for(i=1;i<13&&m!=0;i++){
			for(j=1;j<13&&m!=0;j++){
				if(board[i][j]=PIECE){
					if(validate(board,j-1,i-2)){
						board[i-2][j-1]=PIECE;
						m=0;
					}
					else if (validate(board,j+1,i-2)){
						board[i-2][j+1]=PIECE;
						m=0;
					}
					else if (validate(board,j+2,i-1)){
						board[i-1][j+2]=PIECE;
						m=0;
					}
					else if (validate(board,j+2,i+1)){
						board[i+1][j+2]=PIECE;
						m=0;
					}
					else if (validate(board,j+1,i+2)){
						board[i+2][j+1]=PIECE;
						m=0;
					}
					else if (validate(board,j-1,i+2)){
						board[i+2][j-1]=PIECE;
						m=0;
					}
					else if (validate(board,j-2,i+1)){
						board[i+1][j-2]=PIECE;
						m=0;
					}
					else if (validate(board,j-2,i-1)){
						board[i-1][j-2]=PIECE;
						m=0;
					}
				}

			}/* for j */
		}/* for i */
}


int oneMovFinish(char board [SIZE][SIZE])
{
       int i,j;
       for(i=1;i<SIZE;i++){
	       for(j=1;j<SIZE;j++){
		       if(board[i][j]=EMPTY)
		       {
			       board[i][j]= PIECE;
			       if (finish_game(board,j,i)==1)
				       return 1;
			       else
				       board[i][j]= EMPTY;
		       }
	       }/*for j*/
       }/*for i*/
	       return 0;
}

