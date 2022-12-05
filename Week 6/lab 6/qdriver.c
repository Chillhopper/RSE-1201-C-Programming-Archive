
#include"q.h"
#define MAX 100
int main(void)
{
	int gr[MAX] = { 0.0 };
	int const tot= read_ints_from_stdin(gr, MAX);
	if (tot)
	{
		maximum(gr, tot);
		minimum(gr, tot);
		average(gr, tot);
	}
	return 0;
}