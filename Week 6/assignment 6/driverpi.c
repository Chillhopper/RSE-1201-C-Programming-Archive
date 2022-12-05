#include <stdio.h>
#include "pi.h"

int main(void)
{
	printf("calculus_pi(1) returned %.3f\n",calculus_pi(1));
	printf("calculus_pi(10) returned %.3f\n", calculus_pi(10));
	printf("calculus_pi(100) returned %.3f\n", calculus_pi(100));

	printf("leibniz_pi(1) returned %.3f\n", leibniz_pi(1));
	printf("leibniz_pi(10) returned %.3f\n", leibniz_pi(10));
	printf("leibniz_pi(100) returned %.3f\n", leibniz_pi(100)); 
	return 0; 
}