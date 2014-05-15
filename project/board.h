#ifndef __BOARD_H__
#define __BOARD_H__
/**
 * Header file for board.c
 *
 * @date: 2014-03-31
 *
 * Triplets Game - VIOPE 2014
 */

/*=====================================
 * includes
 *===================================*/
/* System includes */
//#include <...>

/* local includes */
#include "data_structs.h"

/*=====================================
 * macros and defines
 *===================================*/

/*=====================================
 * typedefs
 *===================================*/

/*=====================================
 * function prototypes
 *===================================*/
extern int board_get_size(void);
extern int board_set_size(const int board_size);
extern void board_set_empty(void);
extern int board_is_valid_size(const int board_size);
extern void board_print_raw(void);
extern void board_set_content_row_col(int row, char col);
extern char board_get_content_row_col(int row, char col);
extern int board_row_to_matrix_idx(int row);
extern int board_col_to_matrix_idx(char col);

extern char **board_get_board(void);

#endif
