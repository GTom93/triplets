/**
 * Triplets Game - VIOPE 2014
 * @file: data_structs.c
 *
 * @creation	2014-03-30
 *
 **/

/*=====================================
 * System includes
 *===================================*/
#include <stdio.h>

/*=====================================
 * Local includes
 *===================================*/
#include "data_structs.h"
#include "board.h"


/*=====================================
 * Private declarations
 * A **static** global variable is only
 * visible inside the file where it is
 * declared. Therefore, to access
 * G_current_game, we'll use the
 * function "get_current_game_ptr(...)".
 *===================================*/
/* Static variable that holds the current game
 * This variable should only be accessed through the function
 * get_current_game_ptr() that returns a pointer to the variable
 */
static game_t G_current_game;

/* Static array variable that holds the data regarding the players
 * This variable should only be accessed through the function
 * get_players_ptr() that returns a pointer to the variable
 */
static player_t G_players[2];

/*=====================================
 * Private prototypes
 *====================================*/
static void player_reset(player_t* const player_ptr);

/*=====================================
 * Public functions
 *===================================*/

/**
 * Getter for G_current_game
 * @return	the address of the global variable G_current_game
 * @date	2014-03-27
 **/
game_t* get_current_game_ptr(void){
	return &G_current_game;
}


/**
 * Getter for G_current_game
 * @return	the address of the global variable G_current_game
 * @date	2014-03-27
 * @author	Triplet VIOPE 2014
 **/
player_t* get_players_ptr(void){
	return &G_players[0];		// same as returning G_players
}

/**
 * Function that resets the data structs with invalid values
 * so that we can detect when we're using unitialized data members
 *
 * @return	void
 * @date	2014-03-31
 * @author	Triplet VIOPE 2014
 */
void reset_data_structs(void){
	game_t *game_ptr;
	int i;

	game_ptr = get_current_game_ptr();
	game_ptr->player_first = -1;
	game_ptr->board_columns = -1;
	game_ptr->board_rows = -1;
	game_ptr->game_mode = -1;

	/* Set the whole board as empty */
	board_set_empty();

	/* Deal with G_players */
	for(i=0;i<2;i++){
		player_reset(&(get_players_ptr()[i]));
	}
}


/*=====================================
 * Private functions
 *===================================*/
/*
 * Note: "const" is an indication to the compiler that the
 * player_ptr parameter (a pointer) is not changed by the function
 * player_reset(...).
 */
static void player_reset(player_t* const player_ptr) {
    player_ptr->name[0] = '\0';
    player_ptr->moves = 0;
}



