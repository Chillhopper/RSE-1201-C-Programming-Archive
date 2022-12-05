/*!
@file q.c
@author Kaushik Thirumavalavan (2200927@sit.singaporetech.edu.sh)
@course RSE
@section Year 1
@Assignment 8
@date 30/10/2022
@brief This file contains function definitions for find() find_any() count() count_any() compare() exchange() copy()
*//*________________________________________________________________*/
#define NULL ((void*)0) 

/*!
@brief finds a char by matching it against a string.
@param word - char const* begin which is the start of string, char const *end which is end of string/
and char val which is the target letter to find
@return character address of desired character in string or NULL
*//*_____________________________________________________________*/
char const* find(char const *begin, char const *end, char val){
    //for loop cycles through the alphabet series
    for(long int i = 0; i < (end - begin) ; i++){
        if(*(begin+i) == val){
            return (begin+i);
        }else{
            
        }
    }
    return NULL;
}

/*!
@brief finds any char from a group by matching it against a string.
@param word - char const* begin which is the start of string, char const *end which is end of string/
and char const *vals which is the start of target string and int len which is length of target string.
@return character address of desired character in string or NULL
*//*_____________________________________________________________*/
char const* find_any(char const *begin, char const *end, char const *vals, int len){
    //for every char in the char group
    
        for(long int i = 0; i<(end-begin); i++){
            for(long int j = 0; j<(long int)len; j++){
                if(*(vals+j) == *(begin+i)){
                    return(begin+i);
                } 
            }
        }
    return NULL;
}

/*!
@brief finds a char by matching it against a string.
@param word - char const* begin which is the start of string, char const *end which is end of string/
and char val which is the target letter to count
@return int of number of target character present in string.
*//*_____________________________________________________________*/
int count(char const *begin, char const *end, char val){
    int count = 0;
    for(int i = 0;i<(end - begin); i++){
        if(*(begin+i)==val){
            count++;
        }else{
            continue;
        }
    }
    return count;
}

/*!
@brief counts any char from a group by matching it against a string.
@param word - char const* begin which is the start of string, char const *end which is end of string/
and char const *vals which is the start of target string and int len which is length of target string.
@return int of total number of target characters present in the string.
*//*_____________________________________________________________*/
int count_any(char const *begin, char const *end, char const *vals, int len){
    int totalCount = 0;
    for(int i = 0; i<len; i++){
        totalCount+=count(begin, end, *(vals+i));
    }
    return totalCount;
}

/*!
@brief compares 2 strings and sees if they are the same.
@param word - char const* begin1 which is the start of string1, char const* begin2 which is the start of string2 and length of comparison. 
@return 0 if strings are the same, -1 if begin1 is lesser than begin2 and returns 1 if begin1 is greater than begin2.
*//*_____________________________________________________________*/
int compare(char const *begin1, char const *begin2, int len){

    for(int i = 0; i<len; i++){
        if(*(begin1+i) == *(begin2+i)){
            continue;
        }else if(*(begin1+i) < *(begin2+i)){
            return -1;
        }else{
            return 1;
        }
    
    }
    return 0;
}

/*!
@brief exchanged the value of 2 locations in a string.
@param word - char const* begin1 which is the start of string1, char const* begin2 which is the start of string2 and length exchange. 
@return nothing
*//*_____________________________________________________________*/
void exchange(char *begin1, char *begin2, int len){
    for(int i = 0; i<len; i++){
        char holder = *(begin1+i);
    *(begin1+i) = *(begin2+i);
    *(begin2+i) = holder;
    }
    
}

/*!
@brief copies specified portion of a string to a desired location.
@param word - char* dst which is location to copy to, char* src which is location of source. 
@return nothing
*//*_____________________________________________________________*/
void copy(char *dst, char *src, int len){
    for(int i = len-1; i>=0; i--){
        *(dst+i) = *(src+i);
    }
}
