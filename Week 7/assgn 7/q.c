/*!
@file q.c
@author Kaushik Thirumavalavan (2200927@sit.singaporetech.edu.sh)
@course RSE
@section Year 1
@Assignment 7
@date 21/10/2022
@brief This file contains function definitions for void encrypt() and void decrypt()
*//*________________________________________________________________*/
#include <stdio.h>
#include <stdlib.h>

/*!
@brief gets character input and converts it to ascii value\
then adds the value with the corrospoing ascii value of its key to create encrypted letter
@param word - address of letter to be encrypted and its corrosponding key character.
@return nothing
*//*_____________________________________________________________*/

void encrypt(char* letter, char key){

    int asciiL = *letter;
    int encrypt = (int)asciiL + (int)key;
    while(encrypt<0){
        encrypt+=128;
    }
    while(encrypt>128){
        encrypt-=128;
    }  
    *letter = (char)encrypt;
    
}

/*!
@brief gets encrypted character input and converts it to ascii value\
then minus the value of the corrospoing ascii value of its key to decrypt the letter
@param word - address of encrypted letter and its corrosponding key character.
@return nothing
*//*_____________________________________________________________*/
void decrypt(char* letter, char key){

    int asciiL = *letter;
    int decrypt = asciiL - key;
    while(decrypt<0){
        decrypt+=128;
    }
    while(decrypt>128){
        decrypt-=128;
    }  

    *letter = (char)decrypt;

    //Debugging print statement IMPORTANT ↓↓↓↓↓↓↓↓↓
    //printf("start letter: %c start ascii: %d key: %c key ascii: %d ascii diff: %d looped value:%d outletter: %c\n", asciiL, asciiL, key, key, asciiDiff, decrypt, decrypt);

}