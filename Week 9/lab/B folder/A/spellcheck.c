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

char* str_to_upper(char* string)
{
   for (int i = 0; string[i]; i++)
        if (string[i] >= 'a' && string[i] <= 'z')
            string[i] -= 32;
    
    return string;
}

//char and a struct
//info is a pointer to a struct
//fopen want5s a pointer to a string
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
     //   FILE* boardpter = stdout;//fopen("board.txt", "w");
        if(fpter == NULL){
            return FILE_ERR_OPEN;
        }
        
        char line[50];
        char wordArr[50];
        strcpy(wordArr, word);
        //every line in dictionary
        int i = 0;
        while(fgets(line, sizeof(line), fpter) != NULL){

            str_to_upper(line);
            str_to_upper(wordArr);
      //      fprintf(boardpter, "upper line is: %s\n", line);
       //     fprintf(boardpter, "upper word is: %s\n", wordArr);
            //fprintf(boardpter, "INIT    line is: %s| word is: %s\n", line, wordArr);
            /* for(int i = 0; line[i] != EOF; i++){
                //fprintf(boardpter, "line[i] is: %c| word clone is: %c\n", line[i], *(wordArr+i));
                if(line[i] == '\n'){
                    line[i] = '\0';
                }
                
             */   
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

                
         //       fprintf(boardpter, "line: %s, length: %lu\n", line, linelen);
        //        fprintf(boardpter, "Word Arr: %s, length: %lu\n", wordArr, wordlen);

            if(linelen == wordlen && line[0] == wordArr[0]){
                for(size_t i = 0; i < wordlen; i++){
                    //fprintf(boardpter, "line[i] pos: %c| word Arr pos: %c\n", line[i], *(wordArr+i));
                    if(line[i] == wordArr[i] && i == linelen-1u){
                    return WORD_OK;
                    fclose(fpter);
                    }
                }
            
                    
                //fprintf(boardpter, "i count 2 is %d\n", i);       
            }
            fclose(fpter);
            return WORD_BAD;
        i++;    
        }

    fclose(fpter);
  //  fclose(boardpter);
    return WORD_OK;    
    }
    



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
        
        if(linelen > 0u && (unsigned char)linelen <= count){
            lengths[linelen]++;
        }
        //because pos is where null is, so it actually ends on
    /*    size_t pos = strcspn(line, target);
        if((pos - 1U) == count){
            lengths[pos-1U] = 0;
            lengths[pos-1U] +=1;
        }else{
            continue;
        } */

    }
    //lengths[((int)count)-1] = i;

    return FILE_OK;
}

