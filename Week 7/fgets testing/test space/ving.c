#include <stdio.h>		// file and console I/O
#define MAX 300
#include <string.h>
#define INCLUDE_KEYWORD
		// include declarations and the decryption keyword

const char key[] = { 'D','i','g','i','P','e','n' };

//const char key[] = { 'D','D','D','D','D','D','D' };


void encrypt(char* letter, char key) {
	int asciiL = *letter;
	//int crypt = ((asciiL + key)%128);
	int encrypt = (int)asciiL + (int)key;
	while (encrypt < 0) {
		encrypt += 128;
	}
	while (encrypt > 128) {
		encrypt -= 128;
	} 
	//printf("encrypt is: %d", encrypt);
	printf("%c", encrypt);
}



void decrypt(char* letter, char key) {
	int asciiL = *letter;
	int decrypt = asciiL - key;
	while (decrypt < 0) {
		decrypt += 128;
	}
	while (decrypt > 128) {
		decrypt -= 128;
	}
	//*letter = ((char)decrypt);
	printf("%c", decrypt);
}



int main(void)
{



#ifdef ENCRYPT

	FILE* fpointer = fopen("plain.txt", "r");

	char line[MAX];

	while (fgets(line, sizeof(line), fpointer) != NULL) {
		size_t len = strlen(line);
		for (size_t i = 0; i < (len - 1); i++) {
			size_t k = i%7;
			char* arrVarAddress = &line[i];
			encrypt(arrVarAddress, key[k]);


			printf("i is : %zu \n", i);
			printf("key is : %c ", key[k]);

		}
	}



#else

	FILE* fpointer = fopen("expected-cipher.txt", "r");

	char ciline[MAX];
	//printf("Words: %zu\n", cilen);
	while (fgets(ciline, sizeof(ciline), fpointer) != NULL) {
		size_t cilen = strlen(ciline);

		for (size_t i = 0; i < (cilen - 1u); i++) {
			size_t k = i % 7;
			char* arrCiAddress = &ciline[i];
			decrypt(arrCiAddress, key[k]);
		}

	}

	// TODO: decrypt cipher.txt into out_plain.txt
	// TODO: write count of words into stderr

#endif

	return 0;
}
