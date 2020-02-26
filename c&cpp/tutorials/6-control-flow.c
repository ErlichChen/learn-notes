#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

	// if else
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("which one is max? \n");

	if (a > b)
	{
		if (a > c)
		{
			printf("a is max, %d\n", a);
		}
		else
		{
			printf("c is max, %d\n", c);
		}
	} else {
		if (b > c)
		{
			printf("b is max, %d\n", b);
		}
		else
		{
			printf("c is max, %d\n", c);
		}
	}

	// conditional operator
	char res = a > b ? (a > c ? 'a' : 'c' ) : (b > c ? 'b' : 'c');
	switch (res)
	{
	case 'a':
		printf("%c is max, %d\n", res, a);
		break;

	case 'b':
		printf("%c is max, %d\n", res, b);
		break;

	default:
		printf("%c is max, %d\n", res, c);
		break;
	}
	return EXIT_SUCCESS;
}