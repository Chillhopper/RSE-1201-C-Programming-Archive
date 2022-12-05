#include <stdio.h>
#include <stdlib.h>


int main()
{
    int initVal = 10000, initTest, endValue;
    float intRate = 11;
    int year = 0;

    endValue = 2*initVal;
    initTest = initVal;


    while (initTest<=endValue){
        initTest = initTest + intRate*initTest/100;
        year++;
        printf("%d year has passed\n", year);
    }

    return 0;
}















