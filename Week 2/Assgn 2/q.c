/*!
@file q.c
@author t.kaushik
@course RSE
@section RSE1201-C Programming
@tutorial Tutorial2
@date 08/09/2022
@brief This file contains functions that will output text art when called.
*//*______________________________________________________________________*/

#include <stdio.h> // for printf
/*!
@brief draw_tree() will output a text art of a pointy triangular tree when called
*//*______________________________________________________________*/

void draw_tree(void) {
        printf("    *\n");
        printf("   ***\n");
        printf("  *****\n");
        printf(" *******\n");
        printf("*********\n");
        printf("    #\n");
        printf("    #\n");
        printf("    #\n");
        printf("    #\n");
}
/*!
@brief draw_animal() outputs text art of a small cat with a poker face saying "Hello Junior Coder!"
*//*______________________________________________________________*/

void draw_animal(void) {
// equivalently standard library function puts can be
// used to write text to standard output

printf("  /\\     /\\\n");
printf(" /  \\___/  \\\n");
printf("(           )    -------\n");
printf("(   '   '   )   / Hello  \\\n");
printf("(     _     )  <  Junior  |\n");
printf("(           )   \\ Coder! /\n");
printf(" |         |     -------\n");
printf(" |    |    |\n");
printf(" |    |    |\n");
printf("(_____|_____)\n");
}
