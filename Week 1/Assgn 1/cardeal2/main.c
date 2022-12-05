#include <stdio.h>
#include <stdlib.h>

int main()
{
    const distance = 15000*10;
    const fuelprice = 4;

    //input
    int vCostA = 3, mpgA = 1, vCostB = 3, mpgB = 1;

    int fuelcostA = (distance/mpgA)*fuelprice;
    int fuelcostB = (distance/mpgB)*fuelprice;

    //Total cost
    int totalCostA = fuelcostA+vCostA;
    int totalCostB = fuelcostB+vCostB;

    if(totalCostA>totalCostB){
        printf("The car that costs %d is better", vCostB);
    }else if(totalCostB>totalCostA){
        printf("The car that costs %d is better", vCostA);
    }else{
        printf("They are worth the same in the long run");
    }

    return 0;
}
