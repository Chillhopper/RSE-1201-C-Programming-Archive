/*!
@file       q.c
@author     Kaushik Thirumavalavan
@course     RSE
@section    RSE1201-C Programming
@assignment 5
@date       06/10/22
@brief      This file contains a function sleeping_bag() where inputs temperature and humidity is fed in to determining suitable bag type and insulation 
*//*__________________________________________________________________________*/

#include <stdio.h>	// printf


/*!
@brief This function void sleeping_bag() takes in temperature and humidity to determining suitable bag type and insulation .
@param word - sleeping_bag(signed char temperature, unsigned char humidity)
@return void
*//*______________________________________________________________*/
void sleeping_bag(signed char temperature, unsigned char humidity)
{
	
if(temperature>=-15 && temperature<=100 && humidity<=100){	
		int bag_type;
		int insulation_type;

		if(temperature>=30){
			bag_type = 0;
		}else if(temperature>=15 && temperature<30){
			bag_type = 1;
		}else if(temperature<15){
			bag_type = 2;
		}else{
			printf("Invalid input!\n");
		};

		if(humidity>40){
			insulation_type = 0;
		}else if (humidity<=40){
			insulation_type = 1;
		}else{
			printf("Invalid input!\n");
		}; 
		char sleepydreepy[][20] = {"Summer", "3-Season", "Winter"};
		char insulin[][20] = {"Synthetic", "Down"};
        printf("The temperature is %d*C, humidity is %d%%.\n", temperature, humidity);
		printf("The best sleeping bag is %s type insulated with %s.\n",sleepydreepy[bag_type], insulin[insulation_type]);
	}else{
		printf("Invalid input!\n");
	}
}