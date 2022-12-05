#include <stdio.h>
#include <stdlib.h>

int main()
{
printf("Enter a number (CTRL-D to quit): ");
int value;

while (1 == scanf("%d", &value)) {
if (value <= 0 || value >= 4000) {
printf("Enter a number (CTRL-D to quit): ");
continue;
}
printf("%d: ", value);
decimal_to_roman(value);
printf("Enter a number (CTRL-D to quit): ");
}
printf("\nQuitting ...\n");
return 0;
    return 0;
}
