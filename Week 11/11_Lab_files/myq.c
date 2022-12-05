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


    switch(realspan){

        case 4:;
            int a=0,b=0;

            for(int i = 0; i<4; i++){
                for(int cnt = 0; a<8; a++){
                    for(size_t j = 0; j<2; j++){
                        printf( "%x", cpter[a][j].upper);
                        printf( " %x", cpter[a][j].lower);
                        printf( " %x", cpter[a][j].lower);
                        printf( " %x", cpter[a][j].upper);
                        printf("   ");
                    }
                    cnt++;
                    if(cnt == 2){
                        a++;
                        printf("|  ");
                        break;
                    }
                }

                for(int cnt = 0; b<8; b++){
                    for(size_t j = 0; j<2; j++){
                        printf( " %c", cpter[b][j].upper);
                        printf( " %c", cpter[b][j].lower);
                        printf( " %c", cpter[b][j].lower);
                        printf( " %c", cpter[b][j].upper);
                        if(j!=1){
                            printf("  ");
                        }
                    }
                    cnt++;
                    if(cnt == 2){
                        b++;
                        printf("\n");
                        break;
                    }else{
                        printf("  ");
                    }
                }
            }
        break;    
        

        case 2:
            for(size_t i = 0; i<8; i++){
                for(size_t j = 0; j<2; j++){
                    if(j==1){
                        printf("  ");
                    }
                    printf( "%x ", cpter[i][j].upper);
                    printf( "%x ", cpter[i][j].lower);
                    printf( "%x ", cpter[i][j].lower);
                    printf( "%x ", cpter[i][j].upper);
                }
                printf("  |   ");
                for(size_t j = 0; j<2; j++){
                    if(j==1){
                        printf("  ");
                    }
                    printf( "%c ", cpter[i][j].upper);
                    printf( "%c ", cpter[i][j].lower);
                    printf( "%c ", cpter[i][j].lower);
                    if(j==1){
                        printf( "%c", cpter[i][j].upper);
                    }else{
                    printf( "%c ", cpter[i][j].upper);
                    }
                }

                printf("\n");
            }
                break;

        case 1:
           for(size_t i = 0; i<8; i++){
                for(size_t j = 0; j<2; j++){
                    printf( "%x ", cpter[i][j].upper);
                    printf( "%x ", cpter[i][j].lower);
                    printf( "%x ", cpter[i][j].lower);
                    printf( "%x ", cpter[i][j].upper);
                    printf("  |   ");
                    printf( "%c ", cpter[i][j].upper);
                    printf( "%c ", cpter[i][j].lower);
                    printf( "%c ", cpter[i][j].lower);
                    printf( "%c", cpter[i][j].upper);

                    printf("\n");
                }

            }     
    }
span++;      
size++; 
}    
       


