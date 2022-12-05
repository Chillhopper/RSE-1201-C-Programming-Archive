#include <stdio.h> // for printf

void dispense_change(int, int); // defined by student in q.c


int main(void) {
int denomination;
printf("Enter bill denomination inserted into machine: ");
scanf("%d", &denomination);
printf("Enter purchase price: ");
int dollars, cents;
scanf("%d.%d", &dollars, &cents);
int price_in_cents = dollars*100 + cents;
// denomination is in dollars, price_in_cents is price in cents
dispense_change(denomination, price_in_cents);
return 0;
}
