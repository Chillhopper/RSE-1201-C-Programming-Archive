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
void print_data(const void* ptr, size_t size, size_t span){
    //char char val
    //1 hexadecimal number is 4 bytes
   //i is which data[2] AKA number of elements in first set of array
   //j is which sub data[2][j]
    //span is 16, 8, 4
   size_t realspan = span/4;
 //  size_t counter = 0;
   Data* cpter = (Data*)ptr;
   //printf("size is %zu\n", sizeof(cpter));///sizeof(*cpter));



int a=0,b=0,c=0,d=0;


    for(int cnt = 0; a<8; a++){
        for(size_t j = 0; j<1; j++){
            printf( "%x", cpter[a][j].upper);
            printf( " %x", cpter[a][j].lower);
            printf( " %x", cpter[a][j].lower);
            printf( " %x", cpter[a][j].upper);
            printf("   ");
        }

    }

    



    for(int cnt = 0; b<8; b++){
        for(size_t j = 0; j<1; j++){
            printf( " %c", cpter[b][j].upper);
            printf( " %c", cpter[b][j].lower);
            printf( " %c", cpter[b][j].lower);
            printf( " %c", cpter[b][j].upper);
            if(j!=1){
                printf("  ");
            }
        }


    }

    for(int cnt = 0; c<8; c++){
        for(size_t j = 1; j<2; j++){
            printf( "%x", cpter[c][j].upper);
            printf( " %x", cpter[c][j].lower);
            printf( " %x", cpter[c][j].lower);
            printf( " %x", cpter[c][j].upper);
            printf("   ");
        }

    }

    for(int cnt = 0; d<8; d++){
        for(size_t j = 1; j<2; j++){
            printf( " %c", cpter[d][j].upper);
            printf( " %c", cpter[d][j].lower);
            printf( " %c", cpter[d][j].lower);
            printf( " %c", cpter[d][j].upper);
            printf("   ");

        }


    }


}