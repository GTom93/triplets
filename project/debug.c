/**
 * Triplets Game - VIOPE 2014
 * Some debug-related functions
 * @creation date	2014-05-12
 **/

/*=====================================
 * System includes
 *===================================*/
#include <stdio.h>


/*=====================================
 * Public functions
 *===================================*/
/**
 * Simple function that **appends** msg to the file 'fname'
 * It serves as a simple debug to file
 * Patricio, 2014.05.12
 */
void debug_append_to_file(char *fname, char *msg){

    FILE *f_to_append = fopen(fname,"at");
    fprintf(f_to_append, "[INFO] %s", msg);
    fclose(f_to_append);
}

