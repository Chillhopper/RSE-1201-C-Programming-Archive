// header file q.h
#include <stdio.h>
void decimal_to_roman(int num){
printf("%d: ", num);    
while(num>0){
    while(num>0){
            if (num>=1000){
                printf("M");
                num -= 1000;
                break;
            }else if(num>=900){
                printf("CM");
                num -= 900;
                break;
            }else if(num>=500){
                printf("D");
                num -= 500;
                break;
            }else if(num>=400){
                printf("CD");
                num -= 400;
                break;
            }else if(num>=100){
                printf("C");
                num-=100;
                break;
            }else if(num>=90){
                printf("XC");
                num-=90;
                break;
            }else if(num>=50){
                printf("L");
                num-=50;
                break;
            }else if(num>=40){
                printf("XL");
                num-=40;
                break;
            }else if(num>=10){
                printf("X");
                num-=10;
                break;
            }else if(num>=5){
                printf("V");
                num-=5;
                break;
            }else if(num>=4){
                printf("IV");
                num-=4;
                break;
            }else if(num>=1){
                printf("I");
                num-=1;
                break;
            }
    }            
}
}
      /*          
            case num>=900:
                printf("CM")
                num - 900;
                break;
            case num>= 500:
                printf("D");
                num-500;
                break;
            case num>=400:
                printf("CD");
                num-400;
                break;
            case num>=100:
                printf("C");
                num-100;
                break;
            case num>=90:
                printf("XC");
                num-90;
                break;
            case num>=50:
                printf("L");
                num-50;
                break;
            case num>=40:
                printf("XL");
                num-40;
                break;
            case num>=10:
                printf("X");
                num-10;
                break;
            case num>=5:
                printf("V");
                num-5;
                break;
            case num>=4:
                printf("IV");
                num-4;
                break;
            case num>=1:
                printf("I");
                num-1
                break;                        

        }
        
    }
       */ 
/*
   int m = num/1000;
        num -= m*1000;

        int cm = num/900;
        num -= cm*900;

        int d = num/500;
        num -= d*500;

        int cd = num/400;
        num -= cd*400;

        int xc = num/90;
        num -= xc*90;

        int l= num/50;
        num -= l*50;

        int xl = num/40;
        num -= xl*40;

        int x = num/40;
        num -= x*40;

        int ix = num/9;
        num -= ix*9;

        int v = num/5;
        num -= v*5;

        int iv = num/4;
        num -= num*4;

        int iii = num/3;
        num -= iii*3;

        int ii = num/2;
        num -= ii*2;

        int i = num/1;
        num -= i*1;

    int counterArray[] {m, cm, d, cd, xc, l, xl, x, ix, v, iv, iii, ii, i};

    for(int k = 0; k<13 ; k++ ){
        if counterArray[k] == 0
    }else{
        for(int j = 0; j<k; j++){
            switch(i){
                case 0:
                  printf("M");
                case 1:
                  printf("CM");
                case 2:
                  printf("")
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
         
            }

        }
    }

    */
}
