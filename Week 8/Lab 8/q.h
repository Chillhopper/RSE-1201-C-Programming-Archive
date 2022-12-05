/*!
@file q.h
@author Kaushik Thirumavalavan (2200927@sit.singaporetech.edu.sh)
@course RSE
@section Year 1
@Lab 8
@date 27/10/2022
@brief This file contains function declarations for void initialize(), void wc(), void print_freqs()
*//*________________________________________________________________*/

#include <stdio.h>

 void initialize(int latin_freq[], int size, int *ctrl_cnt, int *non_latin_cnt);

 void wc(FILE *ifs, int latin_freq[], int *ctrl_cnt, int *non_latin_cnt);

 void print_freqs(int const latin_freq[], int size, int const *ctrl_cnt, int const *non_latin_cnt); 
