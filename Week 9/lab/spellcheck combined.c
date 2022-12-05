// TODO: Add file header documentation

#include <string.h>		// strcpy, strcmp, strlen                                   
#include <stdio.h>		// printf, fopen, fclose
#include <ctype.h>
#include "spellcheck.h"

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

/*!
@brief 
Open dictionary file. Loop through each character using fgetc. Convert all characters to uppercase. If characters match, increment word count. 

@return WordCount: unsigned long long int
*//*______________________________________________________________*/
WordCount words_starting_with(const char* dictionary, char letter) {

    FILE *file = fopen(dictionary, "r");

    if (file == NULL) {

        return FILE_ERR_OPEN;
    }

    int character;
    WordCount wordcount = 0;
    char backchar;
    int start = 0;

    str_to_upper(&letter);

    //Loop through the file character by character
    while ((character = fgetc(file)) != EOF) {

        char check = (char) character;

        str_to_upper(&check);
        start++;

        //Check if current character is a character and the previous character is a whitespace. If it is, it is a word
        if (isspace(backchar) || start == 1) {

            if (check == letter) {

                wordcount++;
            }
            
        }
        //Set back character to current character, so it will always be behind by 1 character.
        backchar = check;     
    }

    fclose(file);

    return wordcount;
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





















