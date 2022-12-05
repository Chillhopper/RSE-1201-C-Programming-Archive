/*!
@file       @todo
@author     @todo
@course     @todo
@section    @todo
@assignment @todo
@date       @todo
@brief      @todo
*//*_________________________________________________________________________*/

#include <stdio.h>  // printf

void temperature_convertor(int fahrenheit)
{
    int farenheitClone = fahrenheit;
    double dfahrn = (double) farenheitClone;
	double celcius = 5*(dfahrn-32)/9;
    double celciusClone = celcius;
    double kelvin = celcius + 273.15;
    
    int freeSpace_one = 15;
    int count = 0;
    do {
    farenheitClone /= 10;
    ++count;
  } while (fahrenheitClone != 0);
    
    int freeSpace_two = 30;
    int wholeNum_celcius = (int)celciusClone;
    int count_two =0;
    do {
    wholeNum_celcius /= 10;
    ++count_two;
  } while (wholeNum_celcius != 0);
    count_two = count_two + 2;

    printf("Fahrenheit     Celsius        Kelvin\n");
    printf("---------------------------------------------\n");
    //printf("%d             %.2lf         %.2lf\n", fahrenheit, celcius, kelvin);
    printf("%d", fahrenheit);

    for(int i=0; i<15 - count;i++){
        printf(" ");
    }
    printf("%.2lf\n", celcius);
   
   for(int j=0; j<30 - (15 + count_two); j++){
        printf(" ");
   }
    printf("%.2lf\n", kelvin);
}


/*
Fahrenheit     Celsius        Kelvin
---------------------------------------------
0              -17.78         255.37
*/