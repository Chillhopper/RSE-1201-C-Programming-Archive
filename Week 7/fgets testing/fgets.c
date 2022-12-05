#include <stdio.h>		// file and console I/O
#define MAX 1000
#include <string.h>
#include <stdlib.h>

	// include declarations and the decryption keyword

int main(void){
    
    FILE* filepter = fopen("fgets.txt", "r");
    FILE* outpter = fopen("output.txt", "w");
    char array[400];
    char storeArray[400];

    if(filepter == NULL){
        printf("error in in");
    }

    if(outpter == NULL){
        printf("error in out");
    }

    //fgets(array, 400, filepter);
    //fgets(array, 400, filepter);
    int i = 0;
    while (fgets(array, 400, filepter) != NULL) {
        fputs(array, outpter);
        //printf("%s\n", array);
        i++;
    }

    size_t len = strlen(array);
    printf("array contains: %s\n", array);
    printf("number of lines is: %d\n", i);
    //fputs(array, outpter);
	return 0;
}
