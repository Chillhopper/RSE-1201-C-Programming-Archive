/*!
@file       qdriver.c 
@author     Swavek Wlodkowski (swavek.wlodkowski)
@course     CSD1120F20
@section    AB
@assignment 3
@date       28/9/2020
@brief      This file contains unit tests that exercise
            the temperature_convertor() function.
            Do not modify or submit this file.
*//*_________________________________________________________________________*/

#include <stdio.h>  // printf

void temperature_convertor(int fahrenheit);

int main(void)
{
	// test case 1
	temperature_convertor(0);
	printf("\n");

	// test case 2
	temperature_convertor(20);
	printf("\n");

	// test case 3
	temperature_convertor(300);
	printf("\n");

	// test case 4
	temperature_convertor(-20);
	printf("\n");

	// test case 5
	temperature_convertor(137);
	printf("\n");

	// test case 6
	temperature_convertor(-300);
	printf("\n");

	return 0;
}