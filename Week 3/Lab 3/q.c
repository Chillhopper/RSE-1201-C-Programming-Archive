// file header required
#include <stdio.h> // for printf
// function header required

void dispense_change(int denom, int pennyPrice) {
    int pennyChange;
    pennyChange = denom*100 - pennyPrice;
/*
    int loony = 100;
    int halfLoony = 50;
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;
    */
    //count
    int changeClone = pennyChange;
    int loonyCount = 0;
    int halfLoonyCount = 0;
    int quarterCount = 0;
    int dimeCount = 0;
    int nickelCount =0;
    int oneCentCount =0;

    if (changeClone>=100){
        while (changeClone >= 100){
            changeClone = changeClone - 100;
            loonyCount++;
        }
    }
    if (changeClone>=50){
        while (changeClone >= 50){
             changeClone = changeClone - 50;
            halfLoonyCount++;
        }

    }
    if (changeClone>=25){
        while (changeClone>=25){
             changeClone = changeClone - 25;
            quarterCount++;
        }
    }
    if (changeClone>=10){
        while (changeClone>=10){
             changeClone = changeClone - 10;
            dimeCount++;
        }
    }
    if (changeClone>=5){
        while (changeClone>=5)
             changeClone = changeClone - 5;
            nickelCount++;
    }
    if (changeClone>=1){
        while (changeClone>=1){
             changeClone = changeClone - 1;
            oneCentCount++;
        }
    }

    printf("%d loonies + %d half-loonies + %d quarters + %d dimes + %d nickels + %d pennies\n",loonyCount,halfLoonyCount,quarterCount,dimeCount,nickelCount,oneCentCount);
    /*
    1 loony -> $1
    1 half loony -> 50 cents
    1 quarters -> 35 cents
    1 dime-> 10 cents
    1 nickel -> 5 cents
    1 penny -> 1 cent
    */


}
