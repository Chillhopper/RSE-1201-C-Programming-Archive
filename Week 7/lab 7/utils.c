/*!
@file utils.c
@author Kaushik Thirumavalavan (2200927@sit.singaporetech.edu.sg)
@course RSE
@section Year 1
@tutorial Lab 7
@date 18/10/2022
@brief This file contains functions to read total count, read 3 numbers, swap 2 values, sort 3 numbers and maintain largest 3 numbers.
*//*______________________________________________________________*/
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

/*!
@brief reads input and displays an error if less than 3 integers are entered.
@param word - void
@return - returns the size_t num which is the number of inputs.
*//*______________________________________________________________*/
size_t read_total_count(void){
    printf("Please enter the number of integers: ");
    size_t num;
    scanf("%zu", &num);
    if(num<3){
        printf("There is no third largest number.\n");
        exit(0);
    }else{
        return num;
    }
}

/*!
@brief reads 3 numbers 
@param word - int* first, int* second, int* third which are 3 pointer variables containing addresses.
@return - void
*//*______________________________________________________________*/
void read_3_numbers(int* first, int* second, int* third){
    scanf("%d %d %d", first, second, third);
}

/*!
@brief swaps 2 values in their location
@param word - int* lhs and int* rhs which contain addresses of the variables to be swapped
@return - void
*//*______________________________________________________________*/
void swap(int* lhs, int* rhs){
    int holder = *lhs;
    *lhs = *rhs;
    *rhs = holder;
}

/*!
@brief sorts 3 numbers from highest to lowest
@param word - int* first, int* second, int* third which are addresses of variables.
@return - void
*//*______________________________________________________________*/
void sort_3_numbers(int* first, int* second, int* third){
    for(int i = 0; i<10;i++){
        if(*third>*second){
            swap(third, second);
        }
        
        if(*second>*first){
            swap(second, first);
        }
    }    
}

/*!
@brief maintains the 3 largest numbers from highest to lowest and discards the remaining values.
@param word - int number which is an integer value, int* first, int* second, int* third which are addresses of variables.
@return - void
*//*______________________________________________________________*/
void maintain_3_largest(int number, int* first, int* second, int* third){
    int a = *first; int b = *second; int c = *third;
    int* fourth = &number;

    if(number>a){
        swap(fourth, first);
        swap(fourth, second);
        swap(fourth, third);
    }else if(number>b){
        swap(fourth, second);
        swap(fourth, third);
    }else if(number>c){
        swap(fourth, third);
    }else{
    }
    
}