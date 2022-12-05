/*!
@file main.c
@author Kaushik Thirumavalavan (2200927@sit.singaporetech.edu.sh)
@course RSE
@section Year 1
@Assignment 7
@date 21/10/2022
@brief This file contains function isBlank() and main()
*//*________________________________________________________________*/
#include <stdio.h>		
#define MAX 300
#include <string.h>
#define INCLUDE_KEYWORD
#include "q.h"			
#include <stdlib.h>

/*!
@brief returns 0 if space character is inputted and returns 0 for non-space characters
@param word - char c which is the letter that will be evaluated
@return 0 for space character or 1 for non-space character
*//*_____________________________________________________________*/
int isBlank(char c){
	//if c is a space 1 in returned
	if(c == '\t' || c == '\n' ||c == '\v' || c == '\f' || c == '\r' || c == ' '){
		return 1;
	}else{
		return 0;
	}
}

/*!
@brief main function where the programme will be executed. For encryption it retrives lines from plain.txt\
and passes them into a loop for the encryption of all characters and ouputs to cipher.txt\
For decryption it retrieves lines from cipher.txt and passes them into a loop for it to be fully decrypted and counts number of words.
@param word - void
@return nothing
*//*_____________________________________________________________*/
int main(void)
{
	


	#ifdef ENCRYPT

	FILE* fpointer = fopen("plain.txt", "r");
	FILE* outpter = fopen("cipher.txt", "w");

	char line[MAX];
	size_t s = 0;
	//loops until all characters lines are read.
	while(fgets(line, MAX, fpointer) != NULL){    
		size_t len = strlen(line);
		//loops until all characters are encrypted.
		for(size_t i = 0; i<(len); i++){
			size_t k = s%7u;			
			char* arrVarAddress = &line[i];
			encrypt(arrVarAddress, key[k]); 
			fputc(*arrVarAddress, outpter);
			s++;

		}
	}
	//i is to pin point the char
	//s is to keep racking up the char count (for DigiPen looping)
	fclose(fpointer);
	fclose(outpter);
	
	#else
	
	FILE* countpointer = fopen("cipher.txt", "r");

	char ciline[MAX];
	size_t j = 0;   //keeping track for decryption
	size_t jst = 0; //keeping track for word count
	char a;
	int wordCount = 0;

	while(fgets(ciline, MAX, countpointer) != NULL){
		
		size_t cilen = strlen(ciline);
		//loops for every character and checks if it is a white space and determines number of words
		for(size_t i = 0; i<cilen; i++){
			size_t k = jst%7u;
			char* arrCiAddress = &ciline[i]; 
			decrypt(arrCiAddress, key[k]);
			char b = *arrCiAddress;
			if((isBlank(b) == 0) && isBlank(a)){
				wordCount++;
			}
			a = b; //so as will keep trailing after be emulating a situation of array[i] and array[i-1]
			
			jst++;
			//i is to pin point the char
			//j is to keep racking up the char count (for DigiPen looping)
		}
	}
	fclose(countpointer);
	wordCount++; //Add 1 to wordCount as the last word is excluded from counting.
	fprintf(stderr, "Words: %d\n", wordCount);


	FILE* fpointer = fopen("cipher.txt", "r");
	FILE* outpter = fopen("out_plain.txt", "w");
	//loops until all characters lines are read.
	while(fgets(ciline, MAX, fpointer) != NULL){
	
		size_t cilen = strlen(ciline);
		//loops until all characters are decrypted.
		for(size_t i = 0; i<cilen; i++){
			size_t k = j%7u;
			char* arrCiAddress = &ciline[i]; 
			decrypt(arrCiAddress, key[k]);
			fputc(*arrCiAddress, outpter); 
			j++;
			//i is to pin point the char
			//j is to keep racking up the char count (for DigiPen looping)
		}

	}
	fclose(fpointer);
	fclose(outpter);


	#endif

	return 0;
}
