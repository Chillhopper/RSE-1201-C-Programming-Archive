/*!
@file main.c
@author t.kaushik
@course RSE
@section RSE1201-C Programming
@Lab 5
@date 28/09/2022
@brief This file contains a main function that would take in user input in format float operator float and prints out the result.
*//*______________________________________________________________________*/
#include <stdio.h>
#include "calc.h"
#include "operation.h"

//main.c - the entry point of the program will handle user input, validation, and selection of the
//operation to be performed; a part of your task is to complete this program.
void mainSpacing(void){
    printf("\t\t");
}

int main(void)
{   
    printf("This program evaluates mathematical expressions.\n");
    printf("The format of an expression is:\n");
    printf("\tOPERAND1 SYMBOL OPERAND2\n");
    printf("Available operation symbols:\n");
    printf("\t+ addition\n");    
    printf("\t- subtraction\n");    
    printf("\t* multiplication\n");    
    printf("\t/ division\n");    
    printf("\t\\ integer division\n");
    printf("\t%% modulus\n");    
    printf("\n");
        int i = 1;
    while(i==1){    
        while(i==1){
            float a;
            float b;
            char oper;
            printf("Enter an expression:\n");
            int quantity = scanf( "%f%c%f", &a, &oper, &b);
            if(quantity != 3 && quantity >0 ){
                mainSpacing();
                printf("Invalid number of arguments!\n");
                //printf("%d\n", quantity);
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
                break;

            }else if (quantity == 3){
                switch(oper) {
                    case '+':
                    calculate(a, b, ADDITION);
                    break;
                    case '-':
                    calculate(a, b, SUBTRACTION);
                    break;
                    case '*':
                    calculate(a, b, MULTIPLICATION);
                    break;
                    case '/':
                    calculate(a, b, DIVISION);
                    break;
                    case '\\':
                    calculate(a, b, DIVISION_INTEGERS);
                    break;
                    case '%':
                    calculate(a, b, MODULUS);
                    break;
                    default :
                    mainSpacing();
                    printf("Unknown operation selected!\n");
                }
                
            }else{ 
                    i = 2;
                    printf("\t");
                    printf("Closing the program...\n");
                break;
            }
      
        }

    }     
}        