#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{

	int a = 10;
	void *p = &a;
	// (int *)p = &a;

	printf("%d - %d", a, *(int *)p);

	return EXIT_SUCCESS;
}