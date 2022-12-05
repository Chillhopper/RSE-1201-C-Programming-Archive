/*!
@file main.c
@author t.kaushik
@course RSE
@section RSE1201-C Programming
@Lab 5
@date 28/09/2022
@brief This file contains a function calc.c that would use parameters x and y and op and matches is against a switch statment to carry out the evaluation used in main.c
*//*______________________________________________________________________*/
#include <stdio.h>
#include "calc.h"

void spacing(void){
  printf("\t\t");
}
void calculate(float x, float y, operation op){

    int intx = (int)x;
    int inty = (int)y;
  
    int fiveBase;
    float five;

    int sixBase;
    float six;
    
    switch(op) {
  case 1:
    spacing();
    printf("%f\n", x+y);
    break;
  case 2:
    spacing();
    printf("%f\n", x-y);
    break;
  case 3:
    spacing();
    printf("%f\n", x*y);
    break;
  case 4:
    if(y == 0.f){
    spacing();
    printf("Division by 0!\n");
    }else{
    spacing(); 
    printf("%f\n", x/y);
    }
    break;
  case 5:
    if(inty == 0){
        spacing();
        printf("Division by 0!\n");
    }else{
    fiveBase = intx/inty;  
    five = (float)fiveBase;
    spacing();
    printf("%f\n", five);
    }
    break;  
  case 6:
    if(inty == 0){
        spacing();
        printf("Division by 0!\n");
    }else{
    sixBase = intx%inty;
    six = (float)sixBase;  
    spacing();
    printf("%f\n", six);
    } 
    break;          
  default:
    spacing();
    printf("Invalid number of arguments!\n");
    // code block
}
}
