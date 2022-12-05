/*!
@file q.c
@author Kaushik Thirumavalavan (2200927@sit.singaporetech.edu.sh)
@course RSE
@section Year 1
@Lab 11
@date 30/10/2022
@brief This file contains function definitions for print_data()
*//*________________________________________________________________*/

#include <stdio.h>
#include "q.h"

/*!
@brief Emulates a hex editor by reading and printing hexadecimal values to their respective decimal and ASCII values
@param word - const void* ptr, size_t size, size_t span
@return nothing
*//*_____________________________________________________________*/
void print_data(const void* ptr, size_t size, size_t span ) {

    //Set a char pointer reference to ptr
    char* samplearr = (char*) ptr;
    size_t spanner = span;
    size_t column = size / span;
    size_t choke = 1;
    size_t j = 0;
    size_t k = 0;
    int l = 1;
    int m = 1;

    //Print out all the values
    for (size_t i = 0; i < column; i++) {
        //Print out the hexadecimals
        for (; j < (spanner * choke); j++) {
            if (l % 4 == 0) {
                printf("%x   ", *(samplearr + j));
            }
            else {
                printf("%x ", *(samplearr + j));
            }

            l++;
        }

        printf("|   ");

        //Print out the characters
        for (; k < (spanner * choke); k++) {
            if (m % 4 == 0) {
                printf("%c   ", *(samplearr + k));
            }else {

                printf("%c ", *(samplearr + k));
            }

            m++;
        }

        choke++;
        printf("\n");
    }
}