#include <stdio.h>
#include "q.h"
/*
const char* build_path(const char* parent, const char* separator, const char* const folders[],size_t count)
{
    char* str;
    size_t length = 0;
    length+=STRLEN(parent);
    for(size_t i = 0; i< count; i++)
    {
        length+=STRLEN(folders[i]);
        length++;
    }
    length--;
    str = (char*)debug_malloc(length+2); //45 bytes of space
    STRCPY(str,parent);
    for(size_t i =0; i < count;i++)
    {
        STRCAT(str,folders[i]);
        STRCAT(str,separator);
    }
    return str;
}
*/

const char* build_path(const char* parent, const char* separator, const char* const folders[], size_t count){
    //count is number of elements
    char street[200];
    STRCPY(street, parent);
    //printf("STRCPY IS %s\n", street);
    size_t i;
    size_t mem = 0;
    for(i = 0;i<count;i++){
        STRCAT(street, folders[i]);
        STRCAT(street, separator);
        //printf("STRCPY IS %s\n", street);
    }
    mem = STRLEN(street);
    char* idk = (char*)debug_malloc(mem+1);
    STRCPY(idk, street);
    //printf("street %s\n", street);
    //printf("idk is %s\n", idk);
    return idk;

}

void compare_string(const char* lhs, const char* rhs){
   int i = STRCMP(lhs, rhs);
   if(i>0){
    printf("Right string goes first.\n");
   }else if(i<0){
    printf("Left string goes first.\n");
   }else{
    printf("Both strings are equal.\n");
   }

}

void describe_string(const char* text){
    size_t len = STRLEN(text);
    if(len>0){
        len-=0;
    }
    printf("The length of the path \"%s\" is %ld.\n", text, len);
}

void find_string(const char* string, const char* substring){
    char* ptr = STRSTR(string, substring);
    printf("Searching for a string:\n");
    printf("\tText:     %s\n", string);
    printf("\tSub-text: %s\n", substring);
    if(ptr != NULL){
        int diff = (int)(ptr-string);
        if(diff>0){
            diff-=0;
        }
        printf("\tResult:   found %zu characters at a position %d.\n",STRLEN(substring), diff);
    }else{
        printf("\tResult:   not found\n");
    }
    


}