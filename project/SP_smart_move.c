#include "board.h"

void smart (char board[MAX_BOARDSIZE][MAX_BOARDSIZE])
{
	int i,j, m=3;
	position_t pos;
	if(emptyboard(board)){
		random(board);
	}

	else{

		if(oneMovFinish(board))
			printf("\n You have lose the game, I win :) \n");

		else{
			for(i=0;i<MAX_BOARDSIZE&&m!=0;i++){
				for(j=0;j<MAX_BOARDSIZE&&m!=0;j++){
					if(board[i][j]=PIECE){
						pos.X=i-2;
						pos.Y_int=j-1;
						if(function_validate_move_cpu(pos)){
							board[i-2][j-1]=PIECE;
							m=0;
						}
						else{
							pos.X=i-2;
							pos.Y_int=j+1;
							if (function_validate_move_cpu(pos)){
								board[i-2][j+1]=PIECE;
								m=0;
							}
							else{
								pos.X=i-1;
								pos.Y_int=j+2;
								if (function_validate_move_cpu(pos)){
									board[i-1][j+2]=PIECE;
									m=0;
								}
								else{
									pos.X=i+1;
									pos.Y_int=j+2;
									if (function_validate_move_cpu(pos)){
										board[i+1][j+2]=PIECE;
										m=0;
									}
									else{
										pos.X=i-1;
										pos.Y_int=j+2;
										if (function_validate_move_cpu(pos)){
											board[i+2][j+1]=PIECE;
											m=0;
										}
										else{
											pos.X=i+2;
											pos.Y_int=j-1;
											if (function_validate_move_cpu(pos)){
												board[i+2][j-1]=PIECE;
												m=0;
											}
											else{
												pos.X=i+1;
												pos.Y_int=j+2;
												if (function_validate_move_cpu(board,j-2,i+1)){
													board[i+1][j-2]=PIECE;
													m=0;
												}
												else{
													pos.X=i-1;
													pos.Y_int=j-2;
													if (function_validate_move_cpu(board,j-2,i-1)){
														board[i-1][j-2]=PIECE;
														m=0;
													}
												}

											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

int oneMovFinish (char board [MAX_BOARDSIZE][MAX_BOARDSIZE])
{ int i,j;
    for(i=1;i<MAX_BOARDSIZE;i++){
      for(j=1;j<MAX_BOARDSIZE;j++){
        if(board[i][j]=EMPTY)
        {
             board[i][j]=PIECE;
            if (finish_game(board,j,i)){

                return 1;
            }
            else
                board[i][j]= EMPTY;
        }

    }

}
  return 0;
}

