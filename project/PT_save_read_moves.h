#ifndef __PT_SAVE_READ_MOVES_H__
#define __PT_SAVE_READ_MOVES_H__
/**
 * Header file for PT_save_read_moves.c
 *
 * @creation date: 2014.05.01
 *
 * Triplets Game - VIOPE 2014
 */

/*=====================================
 * includes
 *===================================*/
/* local includes */
#include "board.h"

/*=====================================
 * macros and defines
 *===================================*/
#define MAX_NAME	(20)  /* to be erase, already exists on data_structs.h */

/*=====================================
 * typedefs
 *===================================*/
 #ifdef __ERASE__
typedef struct example{
	int 	field_A;	/* a comment about the field */
	int	field_B;
}example_t;
#endif /* __ERASE__ */

/*=====================================
 * function prototypes
 *===================================*/

extern void read_move(position_t *pos);
extern int function_validate_move(position_t pos);
extern void clean_buffer_keyboard(void);
extern char * terminate_string_at_first_slash_n(char *str);
extern void createLogs(int gameCounter, int dimension);
extern void savePlayLog(char playerName[], int playNumber, int moveX, char moveY, int gameCounter);
extern void closePlayLog(int playNumber, int gameCounter);
extern void loadLogs(int gameCounter);
int input_is_digit(char position[3]);
char input_is_char(char position[3]);
/* Testing functions */
extern void test_reading_converting_validating();
extern void test_representation_matrix(char matrix[MAX_BOARDSIZE][MAX_BOARDSIZE], int dimension);

#endif /* __PT_SAVE_READ_MOVES_H__ */
