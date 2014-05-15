/**
 * Triplets Game - VIOPE 2014
 *
 * @file: highscores.c
 *
 * @creation date	2014-05-14
 *
 **/

/*=====================================
 * includes
 *===================================*/
/* System includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* local includes */
#include "data_structs.h"
#include "highscores.h"
#include "PL_ui.h"
/*=====================================
 * Prototypes of **private** functions
 *===================================*/
//static void example_of_private_function(int num_states);


/*=====================================
 * Public functions
 *===================================*/

/**
 * Function that resets the highscores data and defaults them
 * Should be called at the start, before it attempts to load highscores
 *
 * @return	void
 * @date	2014-05-14
 * @author	Eduardo Andrade (PT Team)
 */

highscores_t init_highscores(highscores_t highscores[]){
    FILE *highscoresFile;
    int i;

    /* Set default highscores */
	for(i=0;i<MAX_HIGHSCORES;i++){
        strcpy(highscores[i].player_name, "DEFAULT");
        highscores[i].player_moves = 999;
	}

	highscoresFile = fopen("highscores.dat", "rb");
	if (highscoresFile == NULL){
        createHighscores(highscores);
	}
	else{
        fread(highscores,sizeof(highscores_t),MAX_HIGHSCORES,highscoresFile);
	}
	fclose(highscoresFile);

	return highscores[MAX_HIGHSCORES];
}

void createHighscores(highscores_t highscores[])
{
    int i;
    FILE *createHighscoresFile;

    createHighscoresFile = fopen("highscores.dat", "wb");
    for(i=0;i<MAX_HIGHSCORES;i++)
    {
        fwrite(highscores,sizeof(highscores_t),MAX_HIGHSCORES,createHighscoresFile);
    }

    fclose(createHighscoresFile);
}

/**
 * This function recieves the winning player info and checks if it's a new highscore
 * If yes, saves it in the new position, if not, discards it and doesn't inform the player
 *
 * @v info_s	Necessary after the game ends
 * @return	 an integer to show if it updated highscores or not
 * @date	2014-05-14
 * @author	Eduardo Andrade (PT Team)
 **/

 void verify_new_highscore(int new_player_moves, char new_player_name[], highscores_t highscores[]){
    int i, o;
    FILE *saveHighscores;

    for(i=0;i<MAX_HIGHSCORES;i++){
        if(new_player_moves < highscores[i].player_moves){
            /* New highscore found, adding to structure array */
            for(o=MAX_HIGHSCORES-2;o>i;o--){
                strcpy(highscores[o].player_name, highscores[o-1].player_name);
                highscores[o].player_moves = highscores[o-1].player_moves;
            }
            highscores[i].player_moves = new_player_moves;
            strcpy(highscores[i].player_name, new_player_name);
            i=MAX_HIGHSCORES; // sets i to max number, to skip verifying or replacing more highscores
        }
    }

    saveHighscores = fopen("highscores.dat", "wb");
    if (saveHighscores == NULL)
    {
        printf("\nERROR: Could not find/write to highscores.dat\nFailed to save the highscores.");
    }
    else{
        fwrite(highscores, sizeof(highscores_t), MAX_HIGHSCORES, saveHighscores);
    }
    fclose(saveHighscores);
 }

/**
 * This function shows highscores when called
 *
 * @v info_s	shows the highscores
 * @return	void
 * @date	2014-05-14
 * @author	PT Team
 **/


void show_highscores(){
    int i;
    FILE *loadHighscores;
    highscores_t highscores[MAX_HIGHSCORES];

    clearscr();
    loadHighscores = fopen("highscores.dat", "rb");
    if (loadHighscores == NULL)
    {
        printf("\nERROR: Couldn't read scores!");
    }
    else{
    for(i=0;i<MAX_HIGHSCORES;i++)
    {
        fread(highscores,sizeof(highscores_t),MAX_HIGHSCORES,loadHighscores);
    }
    printf("\t\t-- Triplets Highscores --\n");
    for(i=0;i<MAX_HIGHSCORES;i++)
    {
        printf("\n#%d - Player Name: %s / Player Score: %d", i+1, highscores[i].player_name, highscores[i].player_moves);
    }
    printf("\n\nPress any key to go back...\n");
    readchar();
    }
    fclose(loadHighscores);
}

/*=====================================
 * Private functions
 *===================================*/

