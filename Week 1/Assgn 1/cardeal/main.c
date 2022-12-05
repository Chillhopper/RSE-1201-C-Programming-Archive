
#include <stdio.h>
#include <stdlib.h>

const distanceT = 10*15000;
const fuelprice = 4;
struct car {
        int mpg; //input
        int vCost; //input
        int gallonsT; // distanceT/mpg;
        int fuelCost; // gallonsT*fuelprice;
};
void kachow(int priceOne,int priceTwo,int mpgOne,int mpgTwo);

int main()
{
    int fstCarPrice = 110000, scndCarPrice = 10000,fstCarmpg = 9, scndCarmpg = 4;

    if(fstCarPrice>scndCarPrice){
        kachow(fstCarPrice,scndCarPrice,fstCarmpg,scndCarmpg);
    }else{
        kachow(scndCarPrice,fstCarPrice,scndCarmpg,fstCarmpg);
    }


};

void kachow(int priceOne,int priceTwo,int mpgOne,int mpgTwo){
    //assignment
    struct car carA;
    carA.mpg = mpgOne;
    carA.vCost = priceOne;
    carA.gallonsT = distanceT/carA.mpg;
    carA.fuelCost = carA.gallonsT*fuelprice;
    struct car carB;
    carB.mpg = mpgTwo;
    carB.vCost = priceTwo;
    carB.gallonsT = distanceT/carB.mpg;
    carB.fuelCost = carB.gallonsT*fuelprice;
    //comparison
    int vCostdiff = carA.vCost - carB.vCost;
    int fuelCostdiff = carA.fuelCost - carB.fuelCost;
    int worthdiff = vCostdiff - fuelCostdiff;

    if(worthdiff>vCostdiff){
        printf("The expensive car is worth it");
    }else{
        printf("The cheaper car is better");
    }


}
