// TODO: Add file header documentation

#include <string.h>		// strcpy, strcmp, strlen                                   
#include <stdio.h>		// printf, fopen, fclose

#include "spellcheck.h"

// TODO: Provide function definitions

/*
typedef unsigned long long int WordCount;
typedef unsigned char WordLength;
typedef WordCount ErrorCode;
*/

//Given a string, converts all lowercase letters to uppercase, and returns a pointer to the first character of the string

char* str_to_upper(char* string) {

    for(int i = 0; string[i]; i++)
    {
        if(*(string + i) >= 'a'&& *(string + i) <= 'z')
        {
            *(string + i) =  (char)((int)*(string+i) - 32); 
        }
    }

    return string;
}
//char and a struct
//info is a pointer to a struct
//fopen want5s a pointer to a string

ErrorCode info(const char* dictionary, DictionaryInfo* info) {

    FILE *file = fopen(dictionary, "r");

    if (file == NULL) {

        return FILE_ERR_OPEN;
    }

    char filearray[100];
    int shortest = -1;
    int longest = -1;
    int wordcount = 0;

    //Loop through the file string by string and store in filearray. Stops when \n or EOF is encountered.
    while (fgets(filearray, 100, file) != NULL) {
        
        //Set last element, which is \n, in filearray to NULL
        filearray[strlen(filearray) - 1] = '\0';

        //Get the length of the string
        size_t len = strlen(filearray);
        int length = (int)len;
        
        //If the length of the string is more than 0, there must be a word inside
        if (length > 0) {

            wordcount++;

            if (shortest == -1 || length < shortest) {

                shortest = length;
            }

            if (longest == -1 || length > longest) {

                longest = length;
            } 
        }

    }

    info->count = (long long unsigned int)wordcount;
    info->shortest = (unsigned char)shortest;
    info->longest = (unsigned char)longest;

    fclose(file);

    return FILE_OK;
}

/*
ErrorCode info(const char* dictionary, DictionaryInfo* info){

    
    FILE* fpter = fopen(dictionary, "r");

    if(fpter == NULL){
        return FILE_ERR_OPEN;
    }
    WordLength maxcharCnt = 0;
    WordLength mincharCnt = 0;
    WordLength overall = 0;
    char line[50];
    while(fgets(line, sizeof(line), fpter) != NULL){
        
        for(WordLength i = 0; line[i] != EOF; i++){

           if(maxcharCnt < i){
                    maxcharCnt = i;
            }

             if(mincharCnt > i){
                    mincharCnt = i;
             }
        }  
        overall++;
    }
    (*info).shortest = mincharCnt;
    (*info).longest = maxcharCnt;
    (*info).count = overall;
    fclose(fpter);
    return FILE_OK;
}
*/
//need to account for case sensitivity
WordCount words_starting_with(const char* dictionary, char letter){
    FILE* fpter = fopen(dictionary, "r");
    //FILE* boardpter = fopen("board.txt", "w");
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
        //fprintf(boardpter,"debgug|| temp: %c, letter: %c\n", temp, letter);
        if(temp == letter ){
            count++;
        }
      
    }
    fclose(fpter);
   // fclose(boardpter);
    return count;

}

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

    fclose(fpter);
    //fclose(boardpter);
    return WORD_BAD;    
}
    
ErrorCode word_lengths(const char* dictionary, WordCount lengths[], WordLength count) {

    FILE *file = fopen(dictionary, "r");

    if (file == NULL) {

        return FILE_ERR_OPEN;
    }

    char filearray[100];

    //Loop through the file string by string and store in filearray. Stops when \n or EOF is encountered.
    while (fgets(filearray, 100, file) != NULL) {

        //Set last element in filearray to NULL
        filearray[strlen(filearray) - 1] = '\0';

        //Get the length of the string
        size_t lengthofstring = strlen(filearray);

        //If length of string is below count
        if (lengthofstring > 0 && lengthofstring <= count) {

            //Store in lengths array
            lengths[lengthofstring]++;
        }
    }

    fclose(file);

    return FILE_OK;
}


/*
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
        //because pos is where null is, so it actually ends on
        size_t pos = strcspn(line, target);
        if((pos - 1U) == count){
            lengths[pos-1U] = 0;
            lengths[pos-1U] +=1;
        }else{
            continue;
        } */

    //}
    //lengths[((int)count)-1] = i;

    //return FILE_OK;
//} */