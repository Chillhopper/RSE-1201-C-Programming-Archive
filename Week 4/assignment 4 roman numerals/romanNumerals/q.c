/*!
@file       q.c
@author     Kaushik Thirumavalavan
@course     C Programming
@section    year 1
@assignment 3
@date       24/09/2022
@brief      contains function decimal_to_roman() which converts decimal integers to roman numerals
*//*_________________________________________________________________________*/
#include <stdio.h> 

void decimal_to_roman(int num){    
while(num>0){
    while(num>0){
            if (num>=1000){
                printf("M");
                num -= 1000;
                break;
            }else if(num>=900){
                printf("CM");
                num -= 900;
                break;
            }else if(num>=500){
                printf("D");
                num -= 500;
                break;
            }else if(num>=400){
                printf("CD");
                num -= 400;
                break;
            }else if(num>=100){
                printf("C");
                num-=100;
                break;
            }else if(num>=90){
                printf("XC");
                num-=90;
                break;
            }else if(num>=50){
                printf("L");
                num-=50;
                break;
            }else if(num>=40){
                printf("XL");
                num-=40;
                break;
            }else if(num>=10){
                printf("X");
                num-=10;
                break;
            }else if(num>=9){
                printf("IX");
                num-=9;
                break;
            }else if(num>=5){
                printf("V");
                num-=5;
                break;
            }else if(num>=4){
                printf("IV");
                num-=4;
                break;
            }else if(num>=1){
                printf("I");
                num-=1;
                break;
            }
    }            
}
printf("\n");
}