#include <stdio.h>
#include "my_string.h"

size_t my_strlen(const char* str){
    int i;
    for (i = 0; str[i] != '\0'; ++i);

    return((size_t)i);
}

char* my_strcpy(char* dest, const char* src){
    int i;
    for (i = 0; src[i] != '\0'; ++i) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}

/*
char* my_strcat(char* dest, const char* src){
    int i; 
    while(dest[i] != '\0'){
        i++;
    }
    for(int j =0; src[i] != '\0' ; j++, i++){
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
*/
int my_strcmp(const char* lhs, const char* rhs){

    for(int i = 0; lhs[i] != '\0' || rhs[i] != '\0';i++){
        //printf("lhs:%c rhs:%c\n", lhs[i], rhs[i]);
        if(lhs[i]!=rhs[i]){
            if(lhs[i]<rhs[i]){
                //printf("lhs:%c rhs:%c\n", lhs[0], rhs[0]);
                return -1;
            }
            if(lhs[i]>rhs[i]){
                //printf("lhs:%c rhs:%c\n", lhs[0], rhs[0]);
                return 1;
            }
        }

   }
   return 0;
}

char* my_strstr(const char* str, const char* substr)
{
    char*a = (char*)str;
    char*s1,*s2;
    while(*a)
    {
        s1 = a;
        s2 =(char*) substr;
        while(*s1 && *s2 &&!(*s1-*s2))
        {
            s1++;
            s2++;
        }
        if(!*s2)
        {
            return a;
        }
        a++;
    }
    return NULL;
}
char* my_strcat(char* dest, const char* src)
{   
    my_strcpy(dest + my_strlen(dest),src);
    return dest;
}
/*
char* my_strstr(const char* src, const char* str){
    int l, i, j;
    for (l = 0; str[l] != '\0'; l++);
    for (i = 0, j = 0; src[i] != '\0' && str[j] != '\0'; i++){
        if (src[i] == str[j]){
            j++;
        }else{
            j = 0;
        }
    }

    if (j == l){
        int diff = (int)(i - j + 1);
        char* returnpter = ((char*)src+diff);
        return returnpter;
    }
    else{
    return NULL;
    }
    return NULL;
}
*/
/*
  int i, j, firstOcc;
   i = 0, j = 0;
 
   while (src[i] != '\0') {
 
      while (src[i] != str[0] && src[i] != '\0')
         i++;
 
      if (src[i] == '\0')
         return (-1);
 
      firstOcc = i;
 
      while (src[i] == str[j] && src[i] != '\0' && str[j] != '\0') {
         i++;
         j++;
      }
 
      if (str[j] == '\0')
         return (firstOcc);
      if (src[i] == '\0')
         return (-1);
 
      i = firstOcc + 1;
      j = 0;
   }*/