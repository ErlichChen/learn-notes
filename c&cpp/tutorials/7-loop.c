#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

	// 0 ~ 100 sum
	int a = 0;
	int sum = 0;
	while (a < 100)
	{
		a += 1;
		sum += a;
	}
	printf("0 ~ 100 sum is %d \n", sum);

	a = 0;
	sum = 0;
	do {
		a += 1;
		sum += a;
	} while (a < 100);
	printf("0 ~ 100 sum is %d \n", sum);

	// narcissistic number
	for (int i = 100; i < 1000; i++)
	{
		int a = 0, b = 0, c = 0;

		a = i / 100;
		b = i / 10 % 10;
		c = i % 10;

		if (a*a*a + b*b*b + c*c*c == i)
		{
			printf("%d is narcissistic number\n", i);
		}
	}

	// triangle
	printf("triangle\n");
	int row = 10;
	for (int i = 1; i < row; i++) {
		for (int j = 1; j < (row - i); j++)
		{
			printf(" ");
		}
		for (int k = 1; k < (i * 2); k++)
		{
			printf("*");
		}
		printf("\n");
	}
	printf("\n");

	// multiplication tables
	printf("multiplication tables\n");
	for (int i = 1; i < 10; i++)
	{
		for (int j =1; j < 10; j++) {
			printf("%d x %d = %d\t", i, j, i * j);
		}
		printf("\n");
	}
	printf("\n");

	return EXIT_SUCCESS;
}