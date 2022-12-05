/*!
@file q.c
@author Kaushik Thirumavalavan (2200927@sit.singaporetech.edu.sh)
@course RSE
@section Year 1
@Lab 8
@date 27/10/2022
@brief This file contains functions void initialize(), void wc(), void print_freqs()
*//*________________________________________________________________*/
#include <stdio.h>
#include "q.h"

/*!
@brief sets an int array of the desired size with zeroes.
@param word - int latin_freq[], int size, int* ctrl_cnt, int* non_latin_cnt.
@return nothing
*//*_____________________________________________________________*/ 
 void initialize(int latin_freq[], int size, int *ctrl_cnt, int *non_latin_cnt){
    for(int i = 0; i<size; i++ ){
        *(latin_freq+i) = 0;
    }
    *ctrl_cnt = 0;
    *non_latin_cnt = 0;

 }

/*!
@brief reads file and its characters and counts number of latin letters, control letters and non-latin lettern as well as frequency of each latin letter.
@param word - FILE* ifs which is pointer of the file, int latin_freq[] which stores all frequency values, int* cntrl_cnt and int* non_latin_cnt.
@return nothing
*//*_____________________________________________________________*/
  void wc(FILE *ifs, int latin_freq[], int *ctrl_cnt, int *non_latin_cnt){
    int ch;
 
    while ((ch = fgetc(ifs)) != EOF){

        if(ch<=122 && ch>=97){
        latin_freq[ch-97]++;
        }else if(ch<=90 && ch>=65){
        latin_freq[ch-65]++;
        }else if(ch == '\a'|| ch == '\b' || ch == '\f' || ch == '\n' || ch == '\r' || ch == '\t' || ch == '\v'){
            (*ctrl_cnt)++;
        }else{
            (*non_latin_cnt)++;
        }
    }
    
  }

/*!
@brief prints list of all latin.
@param word - int const latin_freq[], int size, int const* ctrl_cnt, int const* non_latin_cnt.
@return nothing.
*//*_____________________________________________________________*/
  void print_freqs(int const latin_freq[], int size, int const *ctrl_cnt, int const *non_latin_cnt){
        char c;
        
        for (c = 'a'; c <= 'z'; ++c){
        printf("%5c", c);
        }
        printf("\n");
        
        
        for(int i = 0; i<size; i++){
            printf("%5d", latin_freq[i]);
        } 
        printf("\n");

        //for latin count
        int latincnt = 0;
         for(int i = 0; i<size; i++){
           latincnt+=latin_freq[i];
        } 

        printf("Latin chars             :%6d\n", latincnt);
        printf("Non-Latin non-ctrl chars:%6d\n", *non_latin_cnt);
        printf("Control chars           :%6d\n", *ctrl_cnt);


  }