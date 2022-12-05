/*!
@file       q.c
@author     Kaushik Thirumavalavan
@course     C Programming
@section    year 1
@assignment 3
@date       17/09/2022
@brief      converts fahrenheit to celcius
*//*_________________________________________________________________________*/

#include <stdio.h> // printf
void temperature_convertor(int fahrenheit){
    
    int farnclone = fahrenheit;
    double dfarn = (double)farnclone;
    double celcius = 5*(dfarn-32)/9;
    double kelvin = 273.15 + celcius;

    printf("Fahrenheit     Celsius        Kelvin\n");
    printf("---------------------------------------------\n");
    printf("%-15d%-15.2lf%.2lf\n", fahrenheit, celcius, kelvin);
}  


