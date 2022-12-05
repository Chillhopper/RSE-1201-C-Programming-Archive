/*!
@file q.c
@author Kaushik Thirumavalavan (2200927@sit.singaporetech.edu.sh)
@course RSE
@section Year 1
@Lab 9
@date 3/11/2022
@brief This file contains functions str_to_upper(), info(), words_starting_with(), spell_check, word_lengths()
*//*________________________________________________________________*/
#include <string.h>		// strcpy, strcmp, strlen                                   
#include <stdio.h>		// printf, fopen, fclose
#include "spellcheck.h"

/*!
@brief reads a string and converts all of its letters to UPPERCASE
@param word - const char* string
@return char string
*//*_____________________________________________________________*/
char* str_to_upper(char* string) {
    for(size_t i = 0; i<=strlen(string); i++)
    {
        if(*(string + i) >= 'a'&& *(string + i) <= 'z'){
            *(string + i) =  (char)((int)*(string+i) - 32); 
        }
    }

    return string;
}

/*!
@brief reads file and its characters and provides the shortest, longest and number of words in a dictionary.
@param word - const char* dictionary, DictionaryInfo* info
@return FILE_OK or FILE_ERR_OPEN
*//*_____________________________________________________________*/
ErrorCode info(const char* dictionary, DictionaryInfo* info){

    
    FILE* fpter = fopen(dictionary, "r");

    if(fpter == NULL){
        return FILE_ERR_OPEN;
    }
    ErrorCode maxcharCnt = 0;
    ErrorCode mincharCnt = 100;
    ErrorCode overall = 0;
    char line[100];

    while(fgets(line, sizeof(line), fpter) != NULL){

        
        if(maxcharCnt < strlen(line)-1){
            maxcharCnt = (ErrorCode)(strlen(line)-1);
        }

        if(mincharCnt > strlen(line)-1){
            mincharCnt = (ErrorCode)(strlen(line)-1);
        }

        overall++;


            
    }  
          
    (*info).shortest =(WordLength)mincharCnt;
    (*info).longest = (WordLength)maxcharCnt;
    (*info).count = overall;
    fclose(fpter);
    return FILE_OK;

}

/*!
@brief reads file and provides number of all words starting with indicated character.
@param word - const char* dictionary, char letter
@return count of words or FILE_ERROR_OPEN
*//*_____________________________________________________________*/
WordCount words_starting_with(const char* dictionary, char letter){
    FILE* fpter = fopen(dictionary, "r");
    if(fpter == NULL){
        return FILE_ERR_OPEN;
    }
    WordCount count = 0;
   //convert letter to upper
       if(letter >= 'a' && letter <= 'z'){
        letter = (char)((int)letter - 32);
    }

    char line[50];
    while(fgets(line, sizeof(line), fpter) != NULL){
        char temp = line[0];
        if(temp >= 'a' && temp <= 'z'){
        temp = (char)((int)temp - 32);
        }
        if(temp == letter ){
            count++;
        }
      
    }
    fclose(fpter);
    return count;

}

/*!
@brief reads file and matches selected word against dictionary
@param word - const char* dictionary, const char* word
@return WORD_OK or WORD_BAD
*//*_____________________________________________________________*/
ErrorCode spell_check(const char* dictionary, const char* word){
        FILE* fpter = fopen(dictionary, "r");
        if(fpter == NULL){
            return FILE_ERR_OPEN;
        }
        
        char line[50];
        char wordArr[50];
        strcpy(wordArr, word);
        //every line in dictionary
        
        while(fgets(line, sizeof(line), fpter) != NULL){

            str_to_upper(line);
            str_to_upper(wordArr);
   
            size_t linelen = strlen(line);
            size_t wordlen = strlen(wordArr);
            
            //findings: line has 1 extra char
            if(line[linelen-1] == '\n'){
                line[linelen-1] = '\0';
            }
            if(wordArr[wordlen-1] == '\n'){
                wordArr[wordlen-1] = '\0';
            }
            //RE-calibrating length after null char addition
            linelen = strlen(line);
            wordlen = strlen(wordArr);


            if(strcmp(line, wordArr) == 0){
                return WORD_OK;
            }else{
                continue;
            }

        }

    fclose(fpter);;
    return WORD_BAD;    
}

/*!
@brief reads file and counts number of words with a length in a specific range
@param word - const char* dictionary, WordCount lengths[], WordLength count
@return FILE_OK or FILE_ERR_OPEN
*//*_____________________________________________________________*/
ErrorCode word_lengths(const char* dictionary, WordCount lengths[], WordLength count){
    FILE* fpter = fopen(dictionary, "r");
    //FILE* outpter = stdout;
    if(fpter == NULL){
        return FILE_ERR_OPEN;
    }
    
    //WordCount i = 0;
    char line[50];
    //char target[1] = {'\n'};
    while(fgets(line, sizeof(line), fpter) != NULL){
        size_t linelen = strlen(line);
        if(line[linelen-1] == '\n'){
            line[linelen-1] = '\0';
            }
        linelen = strlen(line);
        
        if(linelen > 0u && (unsigned char)linelen <=  count){
            lengths[linelen]++;
        }

    }


    return FILE_OK;
} 