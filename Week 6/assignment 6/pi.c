/*!
@file pi.c
@author Kaushik Thirumavalavan (2200927@sit.singaporetech.edu.sg)
@course RSE
@section Year 1
@tutorial Tutorial 6
@date 09/010/2022
@brief This file contains functions calculus_pi() and leibniz_pi() which both approximates for value of pi based on user input.
*//*______________________________________________________________*/
#include <stdio.h>
#include <math.h>
#include "pi.h"

/*!
@brief calculus_pi() takes in number of slices and fits them on the 2 unit radius 
quadrant and sums the area of all rectangles that fit in the quadrant.
@param word - double slices which is the number of rectangles to fit in the quadrant.
@return - returns the total area of all rectangled in the quadrant.
*//*______________________________________________________________*/
double calculus_pi(double slices){
    double r = 2;
    double n = slices;
    double xWidth = 2/n; //width of each rectangle
    double rectArea = 0;
    for(double i = 1; i<=n; i++){
        //x is a coordinate
        double xPoint = xWidth*i; //edge of each rectangle
        double offset = xWidth/2.0;
        double trueX = xPoint - offset; //center of each rectangle
        double h = sqrt((r * r) - (trueX * trueX));
        rectArea += xWidth*h;

    }
    
    return rectArea;

}

/*!
@brief leibniz_pi() is a function that uses the leibniz algorithm to approximate the value of pi based on the number of terms.
@param word - double terms which are the number of terms in the leiniz algorithm formula.
@return - returns the result of the leibniz formula which is the approximation of pi.
*//*______________________________________________________________*/
double leibniz_pi(double terms){
    int flip = 1;
    double result = 0;
    for(double i = 0; i<terms; i++){
        if(((int)i)%2!=0){
              if(flip == 1){
                result += 1/i;
                flip = 0;
                //printf("for plus: %lf\n", i);
                
    
              }else{
                result -= 1/i;
                flip = 1;
                //printf("for minus: %lf\n", i);
        
                }    
        }else{
            terms++;
        }    
    }    
return result*4;
}