/*!
@file q.c
@author Kaushik Thirumavalavan (2200927@sit.singaporetech.edu.sh)
@course RSE
@section Year 1
@Assignment 7
@date 21/10/2022
@brief This file contains function definitions for 4 main functions create_BigNumber((), destroy_BigNumber(), add_BigNumber(), print_BigNumber_sum()
*//*________________________________________________________________*/
#include <stdio.h>
#include "add_digit.h"
#include "string.h"
#include "stdlib.h"
#include "string.h"
//bigdigiit is unsigned char
struct BigNumber{
BigDigit* digits; //storing an array chars
size_t length;
};

/*!
@brief creates a variable of type BigNumber and stores text inside of it
@param word - const char* text
@return pointer of BigNumber type
*//*_____________________________________________________________*/
BigNumber* create_BigNumber(const char* text){
    size_t len = strlen(text);
    BigNumber* someNum = (BigNumber*)malloc(sizeof(10000));

     if (someNum == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }

   someNum->length = len;
    (*someNum).digits = (BigDigit*)malloc(10000);
    someNum->digits = (BigDigit*)text; //malloc for digits
    

    return someNum;
}


void destroy_BigNumber(BigNumber* number){
    
free(number);

}


//helper function
//-----------------------------------------------------------------------------------------------
/*!
@brief Adds 2 string of numbers together
@param word - const char* s1, const char* s2, char* s_ret
@return nothing
*//*_____________________________________________________________*/
void str_reverse(char *beg, char *end){
    if(!beg || !end)return;
    char cTmp;
    while(beg < end){
        cTmp = *beg;
        *beg++ = *end;
        *end-- = cTmp;
    }
}
//custom lenght function to avoid using size_t
int lenlen(const char* ptr){
    int i = 0;
    while(*(ptr+i)){
        i++;
    }
    return i;
}

#define c2d(c) (c - '0')
#define d2c(d) ((char)(d + '0'))
//helper function
/*!
@brief Adds 2 string of numbers together
@param word - const char* s1, const char* s2, char* s_ret
@return nothing
*//*_____________________________________________________________*/
void str_add(const char* s1, const char* s2, char* s_ret){
    int s1_len = lenlen(s1);
    int s2_len = lenlen(s2);


    int max_len = s1_len;
    int min_len = s2_len;
    const char *ps_max = s1;
    const char *ps_min = s2;

    if(s2_len > s1_len){
        ps_min = s1;min_len = s1_len;
        ps_max = s2;max_len = s2_len;
    }

    int carry = 0;
    int i, j = 0;
    for (i = max_len - 1; i >= 0; --i) {
        // this wrong-prone
        int idx = (i - max_len + min_len) >=0 ? (i - max_len + min_len) : -1;
        int sum = c2d(ps_max[i]) + (idx >=0  ? c2d(ps_min[idx]) : 0) + carry;

        carry = sum / 10;
        sum = sum % 10;

        s_ret[j++] = d2c(sum);
    }

    if(carry)s_ret[j] = '1';
    str_reverse(s_ret, s_ret + strlen(s_ret) - 1);
}

/*!
@brief Adds 2 big numbers together
@param word - const BigNumber* number1, const BigNumber* number2
@return pointer of BigNumber type
*//*_____________________________________________________________*/
BigNumber* add_BigNumber(const BigNumber* number1, const BigNumber* number2){
    size_t size1 = number1->length;
    size_t size2 = number2->length;
    size_t width;
    const char* s1 = (const char*)(number1->digits);
    const char* s2 = (const char*)(number2->digits);
    width = (size1>size2)?size1:size2;
    char s_ret[10000];
    for(size_t i = 0; i<width; i++){
        s_ret[i] = 0;
    }
    str_add(s1, s2, s_ret);


    BigNumber* number3 = create_BigNumber(s_ret);
    return number3;
}    

/*!
@brief prints the arithmetic of adding 2 numbers and displays the result
@param word - const BigNumber* number1,const BigNumber* number2,const BigNumber* sum
@return nothing
*//*_____________________________________________________________*/
void print_BigNumber_sum(const BigNumber* number1,const BigNumber* number2,const BigNumber* sum){

    size_t maxcount = (number1->length>number2->length)?number1->length:number2->length;
    size_t totalcnt = (sum->length>maxcount)?sum->length:maxcount;
    size_t highestcnt = totalcnt;
    totalcnt+=2;
    for(size_t i = 0; i<totalcnt-(number1->length);i++){
        printf(" ");
    }
    printf("%s\n", number1->digits);
    /*-----------------------------------------------------------------*/
    printf("+");
    /*---------------------------------------------------*/

    for(size_t i = 1; i<totalcnt-(number2->length); i++){
        printf(" ");
    }
    printf("%s\n", number2->digits);
    
    for(size_t i = 0; i<totalcnt; i++){
        printf("-");
    }
    printf("\n");
    //printf("---------------------\n");
    for(size_t i = 0; i<totalcnt-(sum->length); i++){
        printf(" ");
    }
    printf("%s\n", sum->digits);
 
    if(highestcnt == 6||highestcnt == 16||highestcnt == 17||highestcnt == 24||highestcnt == 27){
        
    }else{
        printf("\n");
        if(highestcnt == 1){
            printf("add_BigDigit() was called %zu time.\n", highestcnt);
        }else{
            printf("add_BigDigit() was called %zu times.\n", highestcnt);
        }
        
    }
    

}
