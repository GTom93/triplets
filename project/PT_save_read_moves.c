/**
 * Triplets Game - VIOPE 2014
 *
 * @creation date	2014-03-27
 *
 **/

/*=====================================
 * System includes
 *===================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*=====================================
 * Local includes
 *===================================*/
#include "board.h"
#include "data_structs.h"
#include "PT_save_read_moves.h"
#include "util.h"

/*=====================================
 * Prototypes of **private** functions
 *===================================*/
//static void example_of_private_function(int num_states);

/*=====================================
 * Public functions
 *===================================*/

/**
 * Brief description of the function
 *
 * @v info_s	string hold with some info
 * @return	what does this function returns
 * @date	2014-03-27
 * @author	name of the author of the function
 **/

/**
 * This function initializes the log file
 *
 * @v info_s	parameters to create the file
 * @return	void
 * @date	2014-04-14
 * @author	Eduardo Andrade (PT)
 **/

void createLogs(int gameCounter, int dimension)
{
    FILE *newLog;
    char logName[MAX_PLAYERNAME_LENGTH] = "TripletsLog-";
    char dateExtended[32] = "";

    getDate(dateExtended);

    sprintf(logName, "%s%d.txt", logName, gameCounter);

    newLog = fopen(logName, "w");
    if(newLog == NULL)
    {
        printf("\n\tERR: Unable to create Log!");
    }
    else
    {
        fprintf(newLog, "--Triplets Log--\n");
        fprintf(newLog, "Game #%d\n", gameCounter);
        fprintf(newLog, "Matrix Dimension: %d\n", dimension);
        fprintf(newLog, "Started on: %s\n", dateExtended);
    }
    fclose(newLog);
}

/**
 * This function is called every time the user makes a move, and saves it in the log file
 *
 * @v info_s	parameters to write on the file
 * @return	void
 * @date	2014-04-14
 * @author	Eduardo Andrade (PT)
 **/

void savePlayLog(char playerName[], int playNumber, int moveX, char moveY, int gameCounter)
{
    FILE *playLog;
    char logName[MAX_PLAYERNAME_LENGTH] = "TripletsLog-";

    sprintf(logName, "%s%d.txt", logName, gameCounter);

    playLog = fopen(logName, "a");
    if(playLog == NULL)
    {
        printf("\n\tERR: Couldn't write to %s", logName);
    }
    else
    {
        fprintf(playLog, "Player %s ; Play %d ; Move [%d][%c]", playerName, playNumber, moveX, moveY);
    }
    fclose(playLog);
}

/**
 * Closes the log file with the number of moves (it's needed to load moves)
 *
 * @v playNumber->number of moves to write ; logName->logfile name
 * @return	void
 * @date	2014-05-15
 * @author João Ramos (PT)
 **/

void closePlayLog(int playNumber, int gameCounter)
{
    FILE *playLog;
    char logName[MAX_PLAYERNAME_LENGTH] = "TripletsLog-";

    sprintf(logName, "%s%d.txt", logName, gameCounter);

    playLog = fopen(logName, "a");
    if(playLog == NULL)
    {
        printf("\n\tERR: Couldn't close %s", logName);
    }
    else
    {
        fprintf(playLog, "# Game closed successfully!\n");
        fprintf(playLog, "# Number of moves: %d", playNumber);
    }
    fclose(playLog);
}

/**
 * Makes a replay of the game (loads the logfile and then input every single move into the function designed to the user input)
 *
 * @v gameNum->the game number to load the respective logfile
 * @return	void
 * @date	2014-05-15
 * @author João Ramos (PT)
 **/

void loadLogs(int gameCounter)
{

    FILE *playLog;

    position_t posMove;
    char logName[30] = "TripletsLog-";
    int playNumber;
    char dateExtended[32];
    char playerName[30];
    int dimension;
    int i;
    int moveX;
    char moveY;
    int lineCounter=0;
    int headLinesNumber=6;
    int ch;

    sprintf(logName, "%s%d.txt", logName, gameCounter);

    playLog = fopen(logName, "r");
    if(playLog == NULL)
    {
        printf("\n\tERR: Unable to read Log!");
    }
    else
    {


        do
        {
            ch = fgetc(playLog);
            if( ch== '\n')
            {
                lineCounter++;
            }
        }
        while( ch != EOF );



        fclose(playLog);

        lineCounter-=headLinesNumber;
        lineCounter++; // to add the last line which doesn't have /n !!


    }
    playLog = fopen(logName, "r");
    if(playLog == NULL)
    {
        printf("\n\tERR: Unable to read Log!");
    }
    else
    {
        gameCounter=0;
        dimension=0;
        fscanf(playLog, "--Triplets Log--\n");
        fscanf(playLog, "Game #%d\n", &gameCounter);
        fscanf(playLog, "Matrix Dimension: %d\n", &dimension);
        fscanf(playLog, "Started on: %s\n", dateExtended);

        for (i=0; i<lineCounter; i++)
        {
            fscanf(playLog, "Player %s ; Play %d ; Move [%d][%c]\n", playerName, &playNumber, &moveX, &moveY);
//         printf("player %s, play number %d, moveX %d, moveY %c\n",playerName, playNumber, moveX, moveY); // was just to test if it's reading right
            posMove.X=moveX;
            posMove.Y=moveY;

            read_move(&posMove);
            board_print_raw();
        }

    }

    fclose(playLog);

}

void read_move(position_t *pos)
{

    /* Maximum size for the buffer to read a move: 3 characters + 1 \n + 1 \0 => 5 */
#define READ_MOVE_MAX_BUFF_LEN      (5)

   // int dimension = board_get_size();

    //The move_in_board (being the move read from the user) is 5 to verify the length of the input
//    char move_in_board[READ_MOVE_MAX_BUFF_LEN];
    char move_in_board[READ_MOVE_MAX_BUFF_LEN];

    // Maximum number of characters we want to read with fgets (includes '\n' and '\0')
    int maxLength = READ_MOVE_MAX_BUFF_LEN; //This allows one more character in order to verify the length of the input

    // Keep the number of char in the move_in_board string
   //size_t move_in_board_strlen;

    FILE *mov;
   // do
    //{
        //do
        //{
            startServer();
            printf("Write your move [3 characters max]: ");
            //fgets(move_in_board, maxLength, stdin);    //gets in the string move_in_board a maximum of maxLength characters coming from the STDIN
            mov = fopen("move.mv","r+");
            fgets(move_in_board, maxLength, mov);
            fclose(mov);
            //mov = fopen("move.mv", "w+");
            //fclose(mov);

            /* Terminate the string at the first \n */
            terminate_string_at_first_slash_n(move_in_board);

            /* Compute # of chars in move_in_board */
            //move_in_board_strlen = strlen(move_in_board);

         //   if( move_in_board_strlen > 3)
          //  {
          //      clean_buffer_keyboard();
          //      printf("The move has a maximum of three characters!\n");
          //  }

       // }
       // while(move_in_board_strlen > 3);

        pos->X = input_is_digit(move_in_board);
        pos->Y = input_is_char(move_in_board);
        pos->Y = toupper(pos->Y);
        pos->Y_int = board_col_to_matrix_idx(pos->Y);
        //extern int board_col_to_matrix_idx(char col);

       // if(pos->X < 1 || pos->X > dimension)
      //  {
      //      printf("Invalid number!\nThe number has to be between 1 - %d\n\n", dimension);
      //  }
      //  if(pos->Y_int == -1 || pos->Y_int >= dimension)
      //  {
      //      printf("Invalid letter!\nIt has to be between A - %c\n\n", 64+dimension);
      //  }

   // }
   // while(pos->Y_int == -1 || pos->Y_int >= dimension || pos->X < 1 || pos->X > dimension);

  //  printf("Part of the board! \n");

}
/**
 * This function read a string from the user and
 * separate the value of the column and the row
 *
 * @v info_s	Also validates the size of the string and limits
 * 			Of the row and column.
 * @return doesn't return anything, the struct position_t pass
 * 		by reference.
 * @date	2014-04-20
 * @author	Gabriel Rodrigues (PT Team)
 **/

void read_move1(position_t *pos)
{

    /* Maximum size for the buffer to read a move: 3 characters + 1 \n + 1 \0 => 5 */
#define READ_MOVE_MAX_BUFF_LEN      (5)

    int dimension = board_get_size();

    //The move_in_board (being the move read from the user) is 5 to verify the length of the input
//    char move_in_board[READ_MOVE_MAX_BUFF_LEN];
    char move_in_board[READ_MOVE_MAX_BUFF_LEN];

    // Maximum number of characters we want to read with fgets (includes '\n' and '\0')
    int maxLength = READ_MOVE_MAX_BUFF_LEN; //This allows one more character in order to verify the length of the input

    // Keep the number of char in the move_in_board string
    size_t move_in_board_strlen;

    do
    {
        do
        {
            printf("Write your move [3 characters max]: ");
            fgets(move_in_board, maxLength, stdin);    //gets in the string move_in_board a maximum of maxLength characters coming from the STDIN
            /* Terminate the string at the first \n */
            terminate_string_at_first_slash_n(move_in_board);

            /* Compute # of chars in move_in_board */
            move_in_board_strlen = strlen(move_in_board);

            if( move_in_board_strlen > 3)
            {
                clean_buffer_keyboard();
                printf("The move has a maximum of three characters!\n");
            }

        }
        while(move_in_board_strlen > 3);

        pos->X = input_is_digit(move_in_board);
        pos->Y = input_is_char(move_in_board);
        pos->Y = toupper(pos->Y);
        pos->Y_int = board_col_to_matrix_idx(pos->Y);
        //extern int board_col_to_matrix_idx(char col);

        if(pos->X < 1 || pos->X > dimension)
        {
            printf("Invalid number!\nThe number has to be between 1 - %d\n\n", dimension);
        }
        if(pos->Y_int == -1 || pos->Y_int >= dimension)
        {
            printf("Invalid letter!\nIt has to be between A - %c\n\n", 64+dimension);
        }

    }
    while(pos->Y_int == -1 || pos->Y_int >= dimension || pos->X < 1 || pos->X > dimension);

    printf("Part of the board! \n");

}


/**
 * This function validates if the given position is already
 * occupied or if it's free
 *
 * @v info_s	This function is called after "read_move"
 * @return	An int "1" if the spot is occupied or "0" if it's not
 * @date	2014-04-15
 * @author	Gabriel Rodrigues (PT Team)
 **/

int function_validate_move(position_t pos)
{

    if(board_get_content_row_col(pos.X, pos.Y) == EMPTY)
    {

        printf("Valid move!\n");
        board_set_content_row_col(pos.X, pos.Y);
    }
    else
    {
        printf("That spot is occupied!!!\n");
        return 1;
    }
    return 0;
}


/**
 * This function cleans the buffer from useless
 * things that could be there after a read from the STDIN
 *
 * @v info_s	It erases all until get and '\n' or EOF
 * @return	 Anything
 * @date	2014-04-15
 * @author	(PT Team)
 **/

void clean_buffer_keyboard(void)
{
    char chr;
    do
    {
        chr = getchar();
        // printf("char = %c", chr);
    }
    while (chr != '\n' && chr != EOF);
}


/**
 * This function terminates the string when it finds the '\n'
 *
 * @v info_s	Necessary after the "fgets" function because
 * 			we don't want the '\0' at the end of the string
 * @return	 a pointer to the string
 * @date	2014-04-18
 * @author	(PT Team)
 **/

char* terminate_string_at_first_slash_n(char *str)
{
    char* ptr;
    ptr = strchr(str, '\n');
    if (ptr != NULL)
    {
        *ptr = '\0';
    }
    return str;
}


/**
 *
 * @param
 * @return
 * 2014-04-18
 * Gabriel (PT)
 **/
char input_is_char(char position[3])
{

    char array_letters[24] = "aAbBcCdDeEfFgGhHiIjJkKlL"; //array to compare with the input

    char* ptr = NULL;
    int i, counter = 0;
    char first_character; // returns char ('\0' if no character found)

    for(i = 0; i < sizeof(array_letters); i++)
    {
        ptr = strchr(position, array_letters[i]);   //checks if in the vector position exists a character of the vector arrayLetters
        if(ptr != NULL)
        {
            first_character = *ptr;
            counter++;
            if(counter > 1)
            {
                printf("[WARNING] There is more that one Letter!\n");
                return '\0';
            }
        }
    }
    return first_character;
}

int input_is_digit(char position[3])
{

    int i, j;
    char * ptr = NULL;       // ptr: pointer LINE 82
    int numbersInString[2] = {-1, -1};      //vector that helps the return of two-digits numbers
    int aux = 0;        //auxiliar to position of the vector: numbersInString
    char arrayNumbers[10] = "0123456789";       //array to compare with the obtained input
    for(j=0; j < 3; j++)
    {
        for(i=0; i < 10; i++)
        {
            if(position[j] == arrayNumbers[i])
            {
                numbersInString[aux] = i;
                aux++;
            }
            if(aux > 2)
            {
                printf("[Warning] too much numbers in this move\n");
                return -1;
            }

        }
    }

    ptr = strchr(position, '-'); // In order to make sure that the user didn't write the "minus" symbol
    if(ptr != NULL)
    {
        numbersInString[0] = -1;  //To return -1 at the end
    }

    if(numbersInString[0] != -1 && numbersInString[1] != -1)   //Look if we gottwo numbers
    {
        numbersInString[0] = numbersInString[0]*10 + numbersInString[1];
        //printf("first if numberInString[0] = %d\n", numbersInString[0]);
    }
    else
    {
        if(numbersInString[0] != -1)   //Look if we got one number
        {
            //continue
            //printf("second if numberInString[0] = %d\n", numbersInString[0]);
        }
    }
    //if we didn't got any number it'll return -1 as we state at the beggining in numbersInString
    if(numbersInString[0] < 13)
    {
        return numbersInString[0];
    }
    else
    {
        return -1;
    }
}




/**
 * This function helps the test of reading, converting and
 * validating moves
 *
 * @v info_s	This represents the matrix (The Board)
 *
 * @return	 void
 * @date	2014-04-15
 * @author	Gabriel Rodrigues(PT Team)
 **/

void test_representation_matrix(char matrix[MAX_BOARDSIZE][MAX_BOARDSIZE], int dimension)
{
    int i, j;
    printf("GAME BOARD! %d x %d\n\n", dimension, dimension);
    printf("   \t A     B     C     D     E     F     G     H     I     J     K     L\n\n");
    for(i = 0 ; i < dimension; i++)
    {

        printf("  %d\t", i+1);

        for(j = 0; j < dimension; j++)
        {
            +
            printf("|%c|   ", matrix[i][j]);
        }
        printf("\n\n");

    }
}


/**
 * This TEST function represents the environment which the "reading,
 * validating and converting moves functionality" needs to work
 * properly.
 *
 * @v info_s	This is a test function
 *
 * @return	 void
 * @date	2014-04-25
 * @author	Gabriel Rodrigues(PT Team)
 **/

void test_reading_converting_validating()
{
    int counter = 1, check = 0;
    reset_data_structs();
    board_set_size(BOARD_MEDIUM);
    int dimension = board_get_size();
    position_t pos;

    while(counter == 1)
    {
        test_representation_matrix(get_current_game_ptr()->board, dimension);

        do
        {
            read_move(&pos);

            check = function_validate_move(pos);
        }
        while(check != 0);
        //arise the variable "int playNumber".
        //save in log
    }
}



/*=====================================
 * Private functions
 *===================================*/
