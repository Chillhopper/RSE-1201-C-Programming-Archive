/*!
@file q.c
@author Kaushik Thirumavalavan (2200927@sit.singaporetech.edu.sh)
@course RSE
@section Year 1
@Assignment 11
@date 18/11/2022
@brief This file contains function definitions for read_data(), max(), min(), average(), variance(), std_dev(), selection_sort(), ltr_grade_pctg()
*//*________________________________________________________________*/


#include <stdio.h>
#include "string.h"
#include "q.h"
#include "stdlib.h"
#include "ctype.h"
#include "math.h"


/*!
@brief reads a line from the file and stores it into an allocated memory for future access
@param word - char const *file_name, int *ptr_cnt
@return pointer double to where data is stored 
*//*_____________________________________________________________*/
double* read_data(char const *file_name, int *ptr_cnt){
    char line[200];
    char temp[200];
    double data[2000];
    int count = 0;

    FILE* fpter = fopen(file_name,"r");
    while(fgets(line, sizeof(line),fpter) != NULL){
        size_t len = strlen(line);

        for(size_t i = 0; i<len; i++){
            
            if(i%6==0){
                strncpy(temp, (line+i), 5u);
                data[count] = atof(temp);                 
                count++;
            }
        }
        //COUNT NOT INCLUDED AT LAST SET NUMBER TO INCREMENT AT END OF WHILE LOOP
        
    }
    *ptr_cnt = count;
    double* memry = (double*)malloc(sizeof(data));
    
    for(int j=0;j <count; j++){
        memry[j] = data[j];
    }
    
    return memry;
    

}

/*!
@brief finds the maximum grade in the array
@param word - double const *begin, double const *end
@return type double value of maximum
*//*_____________________________________________________________*/
double max(double const *begin, double const *end){
    int index = end-begin;
    double maxim = 0.0;
    for(int i = 0; i<index; i++){
        if(maxim < *(begin+i)){
            maxim = *(begin+i);
        }
    }
    return maxim;
}

/*!
@brief finds the minimum grade in the array
@param word - double const *begin, double const *end
@return type double value of minimum
*//*_____________________________________________________________*/
double min(double const *begin, double const *end){
    int index = end-begin;
    double minimus = 100000000.0;
    for(int i = 0; i<index; i++){
        if(minimus > *(begin+i)){
            minimus = *(begin+i);
        }
    }
    return minimus;
}

/*!
@brief finds the average grade in the array
@param word - double const *begin, double const *end
@return type double value of average
*//*_____________________________________________________________*/
double average(double const *begin, double const *end){
        int index = end-begin;
        double avg = 0.0;
        for(int i = 0; i<index; i++){
            avg += *(begin+i);
        }
    return avg/((double)index);
}

/*!
@brief finds the variance in the array
@param word - double const *begin, double const *end
@return type double value of variance
*//*_____________________________________________________________*/
double variance(double const *begin, double const *end){
    double index = end-begin;
    double mean = average(begin, end);
    double sum = 0;
    for(int i = 0; i<index; i++){
        double ex = *(begin+i);
        sum += pow((ex-mean), 2);
    }
    double s = sum/(index-1.0);

    return s;
}

/*!
@brief finds the standard deviation in the array
@param word - double const *begin, double const *end
@return type double value of standard deviation
*//*_____________________________________________________________*/
double std_dev(double const *begin, double const *end){

    return pow(variance(begin, end),0.5);
}

/*!
@brief sorts the values in the array in ascending order
@param word - double* base, int size
@return nothing
*//*_____________________________________________________________*/
void selection_sort(double* base, int size) {
    {

        double tp;
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (*(base + i) > *(base + j))
                {
                    tp = *(base + i);
                    *(base + i) = *(base + j);
                    *(base + j) = tp;
                }
            }
        }
    }
}

/*!
@brief finds median value in the array
@param word - double* base, int size
@return type double of median value
*//*_____________________________________________________________*/
double median(double *base, int size){
    double midVal;
    selection_sort(base, size);
    if (size % 2 == 0)
        midVal = (*(base + (size / 2)) + *(base + (size / 2) - 1)) / 2.0;
    else
        midVal = *(base + (size / 2));

    return midVal;
}


/*!
@brief calculates percentage of varius grades A,B,C,D and F in the array
@param word - double const *begin, double const *end, double *ltr_grades
@return nothing
*//*_____________________________________________________________*/
void ltr_grade_pctg(double const *begin, double const *end, double *ltr_grades){

    double aCNT = 0, bCNT = 0, cCNT = 0, dCNT = 0, fCNT = 0;

    double index = end - begin;

  /*  for(int i = 0; i<index; i++){
        printf("array test: %lf", *(begin+i));
    }
*/
    for(int i = 0; i<index; i++){
        if(begin[i] >= 90.0 ){
            aCNT++;
        }else if(begin[i]<90.0 && begin[i]>=80.0){
            bCNT++;
        }else if(begin[i]<80.0 && begin[i]>=70.0){
            cCNT++;
        }else if(begin[i]<70.0 && begin[i]>=60.0){
            dCNT++;
        }else{
            fCNT++;
        }
    }
    *(ltr_grades) = (aCNT/index)*100.0;
    *(ltr_grades+1) = (bCNT/index)*100.0;
    *(ltr_grades+2) = (cCNT/index)*100.0;
    *(ltr_grades+3) = (dCNT/index)*100.0;
    *(ltr_grades+4) = (fCNT/index)*100.0;

}