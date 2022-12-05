#include <stdio.h> // printf, scanf

void print_line(int index, double cents, int value)
{
    double dcents = (double)cents;
    printf("| %d  |        %d|     %.2lf  |",index, value, dcents);
 /*   
    printf("+----+--------------+-------+");
    printf("| #  | Denomination | Count  |");
    printf("| 1  |        100.00|     0  |");
    printf("| 2  |         50.00| 0      |");
    printf("| 3  |         10.00| 1      |");
    printf("| 4  |          5.00| 1      |");
    printf("| 5  |          2.00| 1      |");
    printf("| 6  |          1.00|      1 |");
    printf("| 7  |          0.50|      1 |");
    printf("| 8  |          0.20|      1 |");
    printf("| 9  |          0.10|      1 |");
    printf("| 10 |          0.05|      1 |");
    printf("| 11 |          0.01|      1 |");
*/
}
void coins(int cents)
{
// TODO: provide proper implementation later

int centClone = cents;


int hundreds = centClone/10000;
centClone -= hundreds*10000;

int fifties = centClone/5000;
centClone -= fifties*5000;

int tens = centClone/1000;
centClone -= centClone*1000;

int fives = centClone/500;
centClone -= fives*500;

int twos = centClone/200;
centClone -= twos*200;

int ones = centClone/100;
centClone -= ones*100;

int fiftycents = centClone/50;
centClone -= fiftycents*50;

int twentycents = centClone/20;
centClone -= twentycents*20;

int tencents = centClone/10;
centClone -= tencents*10;

int fivecents = centClone/5;
centClone -= fivecents*5;

int onecents = centClone/1;
centClone -= onecents*1;
printf("+----+--------------+-------+");

print_line(1, 100, hundreds);
print_line(2, 50, fifties);
print_line(3, 10, tens);
print_line(4, 5, fives);
print_line(5, 2, twos);
print_line(6, 1, ones);
print_line(7, 0.5, fiftycents);
print_line(8, 0.2, twentycents);
print_line(9, 0.10, tencents);
print_line(10, 0.05, fivecents);
print_line(11, 0.01, onecents);


    
}
int main(void)
{
printf("input your value");
int dollars;
int cents;
int inputcount = scanf("%d.%d",&dollars, &cents);
if(inputcount != 2){
  printf("You did not type in the correct format in terms of dollars and cents.");
  break;
}




int centVal = inputVal*100;
coins(centVal);
}

//100 50 10 5 2 1 0.5 0.2 0.1 0.05 0.01