/*!
@file q.c
@author Kaushik Thirumavalavan (2200927@sit.singaporetech.edu.sh)
@course RSE
@section Year 1
@tutorial Tutorial 6
@date 07/010/2022
@brief This file contains function definitions for int read_ints_stdin, void maximum, void minumum, void average.
*//*________________________________________________________________*/

#include "q.h"
#include <stdio.h>
/*!
@brief stores an unspecified number of inputs into an array and returns the total number of values.
@param word - the array and the maximum array size.
@return the totan number of values in the array.
*//*_____________________________________________________________*/
int read_ints_from_stdin(int array[], int max_array_size) {
    int i = 0, num;
    while ( (scanf("%d", &num) != EOF) && i < max_array_size) {
        array[i++] = num;
 
    }

    
return i;
}
/*!
@brief find the maximum value in an array.
@param word - the array and the number of values in the array.
@return the maximum value in an array.
*//*_____________________________________________________________*/
void maximum(int maxArray[], int total){
    int maxkeeper = maxArray[0];
    for(int i = 0; i<total; i++){
        int maxholder = maxArray[i];
        if (maxholder>maxkeeper){
            maxkeeper = maxholder;
        }else{
            continue;
        }
    }
    printf("Max of %d is %d\n", total, maxkeeper);
    
}
/*!
@brief find the minimum value in an array.
@param word - the array and the number of values in the array.
@return the minimum value in an array.
*//*_____________________________________________________________*/
void minimum(int minArray[], int total){
    int minkeeper = minArray[0];
    for(int i = 0; i<total; i++){
        int minholder = minArray[i];
        if (minholder<minkeeper){
            minkeeper = minholder;
        }else{
            continue;
        }
    }
    printf("Min of %d is %d\n", total, minkeeper);
    
}
/*!
@brief find the average value in an array.
@param word - the array and the number of values in the array.
@return the average value in an array.
*//*_____________________________________________________________*/
void average(int aveArray[], int total){
    int potOfGreed = 0;
    for(int i = 0; i<total; i++){
    potOfGreed +=aveArray[i];
    }

    float trueAve = ((float)potOfGreed)/((float)total);
    printf("Avg of %d is %.2lf\n", total, trueAve);
    
}