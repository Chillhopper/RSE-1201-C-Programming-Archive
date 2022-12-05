/*!
@file       q.c
@author     Kaushik Thirumavalavan
@course     C Programming
@section    year 1
@assignment 3
@date       17/09/2022
@brief      converts fahrenheit to celcius
*//*_________________________________________________________________________*/

#include <stdio.h>  // printf
#include <string.h>

void temperature_convertor(int fahrenheit)
{
    int farenheitClone = fahrenheit;
    double dfahrn = (double) farenheitClone;
	double celcius = 5*(dfahrn-32)/9;
    double kelvin = celcius + 273.15;
    
    // snprintf(buffer, t_size, str*);
    char bufferFarn[50];
    snprintf(bufferFarn,50,"%d",fahrenheit); 
    size_t fSpacing = strlen(bufferFarn);
    
    char bufferCelc[50];
    snprintf(bufferCelc,50,"%.2lf",celcius);
    size_t cSpacing = strlen(bufferCelc);

    printf("Fahrenheit     Celsius        Kelvin\n");
    printf("---------------------------------------------\n");
    //printf("%d             %.2lf         %.2lf\n", fahrenheit, celcius, kelvin);
    printf("%d", fahrenheit);
    
    size_t spaceNeutralizerOne = 15-fSpacing;
    for(size_t i = 0; i < spaceNeutralizerOne; i++){
        printf(" ");
    }
    printf("%.2lf", celcius);
   
   size_t spaceNeutralizerTwo = 30-(15+cSpacing);
   for(size_t j = 0; j < spaceNeutralizerTwo; j++){
    printf(" ");
   }
    printf("%.2lf\n", kelvin);
}

