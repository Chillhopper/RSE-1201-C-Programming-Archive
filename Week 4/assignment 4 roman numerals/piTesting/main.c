#include <stdio.h>
#include <stdlib.h>

int main()
{
    double slices = 1;
    double r = 2;
    // x width of each rectangle
    double xWidth = 2/slices;
    double rectArea = 0;
    for(double i = 0; i<slices; i++){
        //my x will be 2 - xWidth*i
        double x = 2 - xWidth*i;
        double h = sqrt(r * r - x * x);
        rectArea += xWidth*h;
        printf("test %lf\n", rectArea);


    }
    printf("rectArea is %lf", rectArea);
    return;
}
