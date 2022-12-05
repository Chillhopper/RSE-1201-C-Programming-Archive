#include <stdio.h>
#include "add_digit.h"
#include "string.h"
#include "stdlib.h"
#include "string.h"

#define c2d(c) (BigDigit)(c - '0')
#define d2c(d) ((char)(d + '0'))

struct BigNumber
{
    BigDigit* digits; //to store an array of characters
    size_t length; //number of characters in the input text
};

BigNumber* create_BigNumber(const char* text)
{
    BigNumber* Num = (BigNumber*)malloc(sizeof(BigNumber)); // allocate memory for the object created

    if (Num == NULL) // if memory cannot be allocated
    {
        printf("Memory not allocated.\n");
        exit(0);
    }

    (*Num).length = strlen(text); //assign the same value of the lenght of text into data member length

    size_t nbytes = sizeof(text); //getting the size of input text
    nbytes--; //removing the null at the end
    (*Num).digits = (BigDigit*)malloc(nbytes * sizeof(BigDigit)); //allocating the memory for data member digits

    (*Num).digits = (BigDigit*)text; //storing with digits derived from the text    

    return Num; //return the BigNumber object created
}


void destroy_BigNumber(BigNumber* number)
{
    free(number); //frees the heap of memory
}


void reverseString(char *begin, char *end) //custom string reverse function
{
    if(!begin || !end)
    {
        return;
    }

    char temp;
    while(begin < end)
    {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}


int findLength(const char* ptr) //custom find length function 
{
    int i = 0;
    while(*(ptr+i))
    {
        i++;
    }
    return i;
}

void addString(const char* s1, const char* s2, char* s_ret) //custom adding function
{
    int s1_len = findLength(s1); //length of first string
    int s2_len = findLength(s2); //length of second string

    int max_len = s1_len; //maximum length is set the same as s1_len
    int min_len = s2_len; //minimum length is set the same as s2_len
    const char *ps_max = s1; //declare constant char pointer pointing to same address as s1
    const char *ps_min = s2; //declare constant char pointer pointing to same address as s2

    if(s2_len > s1_len) //is length off s2 is greater than s1
    {
        ps_min = s1; //swap the pointee
        min_len = s1_len; //swap the minimum 

        ps_max = s2; //swap the pointee
        max_len = s2_len; //swap the maximum
    }

    BigDigit carry = 0; //declare BigDigit variable carry
    BigDigit* ptrcarry = &carry; //delclare BigDigit pointer pointing to carry variable
    int i, j = 0; //declare int i and j
    for (i = max_len - 1; i >= 0; --i) //run through the inputs
    {
        int idx = (i - max_len + min_len) >=0 ? (i - max_len + min_len) : -1;

        BigDigit firstdigi = c2d(ps_max[i]); //first digit 
        BigDigit seconddigi = (idx >=0  ? c2d(ps_min[idx]) : 0); //second digit
        BigDigit sum = add_BigDigit(firstdigi, seconddigi, ptrcarry); //

        s_ret[j++] = d2c(sum);
    }

    if(carry)s_ret[j] = '1';
    reverseString(s_ret, s_ret + strlen(s_ret) - 1);
}

BigNumber* add_BigNumber(const BigNumber* number1, const BigNumber* number2)
{
    size_t size1 = number1->length;
    size_t size2 = number2->length;

    size_t width;
    const char* s1 = (const char*)(number1->digits);
    const char* s2 = (const char*)(number2->digits);
    width = (size1>size2)?size1:size2;
    char s_ret[10000];
    for(size_t i = 0; i<width; i++){
        s_ret[i] = 0;
    }
    addString(s1, s2, s_ret);


    BigNumber* number3 = create_BigNumber(s_ret);
    return number3;
}    

void print_BigNumber_sum(const BigNumber* number1,const BigNumber* number2,const BigNumber* sum)
{
    size_t maxcount = (number1->length>number2->length)?number1->length:number2->length;
    size_t totalcnt = (sum->length>maxcount)?sum->length:maxcount;
   // size_t highestcnt = totalcnt;

    totalcnt+=2;

    for(size_t i = 0; i<totalcnt-(number1->length);i++)
    {
        printf(" ");
    }
    printf("%s\n", number1->digits);

    printf("+");

    for(size_t i = 1; i<totalcnt-(number2->length); i++)
    {
        printf(" ");
    }
    printf("%s\n", number2->digits);
    
    for(size_t i = 0; i<totalcnt; i++)
    {
        printf("-");
    }
    printf("\n");

    for(size_t i = 0; i<totalcnt-(sum->length); i++)
    {
        printf(" ");
    }
    printf("%s\n", sum->digits);
 
   // if(highestcnt == 6||highestcnt == 16||highestcnt == 17||highestcnt == 24||highestcnt == 27)
    ///{
        
    //}
    
    //else 
    //{
      //  printf("\n");
       // if(highestcnt == 1)
        //{
         //   printf("add_BigDigit() was called %zu time.\n", highestcnt);
        //}
        
        //else
        //{
         //   printf("add_BigDigit() was called %zu times.\n", highestcnt);
        //}
        
    //}
    

}
