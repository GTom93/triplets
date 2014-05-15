/**
 * Triplets Game - VIOPE 2014
 * @file main.c
 * @creation date 2014-03-27
 *
 **/

/*=====================================
 * System includes
 *===================================*/
#include <stdio.h>
#include <stdlib.h>

/*=====================================
 * Local includes
 *===================================*/
#include "data_structs.h"
#include "board.h"
#include "PL_ui.h"
#include "PT_save_read_moves.h"
#include "SP.h"
#include "debug.h"

int finish_game_wrapper(position_t current_pos){
	char S[1024];
	sprintf(S,"Calling finish_game: X=%d,Y=%d",current_pos.X, current_pos.Y_int);
	// debug_append_to_file("debug.txt", S);
	return finish_gamePL(get_current_game_ptr()->board);
}


/*=====================================
 * main
 *===================================*/
int main(void){
	reset_data_structs();
	clearscr();
	welcome_screen();
	show_menu();

	int check=0;
	if(G_current_game.game_mode==pvp){ //pvp mode

		if(G_current_game.player_first==1){  
			// who first start game,  first move
			cmp.current_player_move=G_players[0];
			cmp.previous_player_move=G_players[1];
		}
		else{
			cmp.current_player_move=G_players[1];
			cmp.previous_player_move=G_players[0];
		}

		while( !finish_game_wrapper(pos)){
			clearscr();
			board_print_raw();
			do{
				printf("%s your move! (all your moves: %d)\n",
				  cmp.current_player_move.name,
				  cmp.current_player_move.moves);
				read_move(&pos);
			}while(function_validate_move(pos));

			cmp.current_player_move.moves+=1;
			cmp.tmp=cmp.current_player_move;
     			//swap current player
			cmp.current_player_move=cmp.previous_player_move; 
			cmp.previous_player_move=cmp.tmp;
		}//end while()...

		cmp.tmp=cmp.current_player_move;                   //swap current player
		cmp.current_player_move=cmp.previous_player_move;  
		cmp.previous_player_move=cmp.tmp;
		board_print_raw();
		printf("%s wins! (In %d moves!)\n",cmp.current_player_move.name,cmp.current_player_move.moves);
	}// end pvp mode

	if(G_current_game.game_mode==pvc){ //pvc mode

		if(G_current_game.player_first==1){  
			// who first start game,  first move
			cmp.current_player_move=G_players[0];
			cmp.previous_player_move=G_players[1];// G_players[1] is cpu player
		}
		else{
			cmp.current_player_move=G_players[1];
			cmp.previous_player_move=G_players[0];
		}

		while(!finish_game_wrapper(pos)){
			clearscr();
			board_print_raw();
			if(G_current_game.player_first==1)
			{
				do{
					printf("%s your move! (all your moves: %d)\n",cmp.current_player_move.name,cmp.current_player_move.moves);
					read_move(&pos);
				}while( function_validate_move(pos));
			}
			else
			{
				printf("Computers move was: ");
				random_cpu(get_current_game_ptr()->board);

			}
			cmp.current_player_move.moves+=1;
			cmp.tmp=cmp.current_player_move;                   //swap current player
			cmp.current_player_move=cmp.previous_player_move;  //
			cmp.previous_player_move=cmp.tmp;
			G_current_game.player_first=(G_current_game.player_first+1)%2;
		}

		cmp.tmp=cmp.current_player_move;                   //swap current player
		cmp.current_player_move=cmp.previous_player_move;  //
		cmp.previous_player_move=cmp.tmp;
		board_print_raw();
		printf("%s wins! (In %d moves!)\n",cmp.current_player_move.name,cmp.current_player_move.moves);
	}


	return 0;
}
