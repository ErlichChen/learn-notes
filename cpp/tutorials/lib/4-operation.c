#include <stdio.h>

int main(void)
{
	// comparison operator
	printf("comparison\n");
	int a1 = 10;
	int b1 = 20;
	printf("10 <= 20: %d\n", a1 <= b1);

	// assigning operator
	int a2 = 10;
	int b2 = 20;
	printf("assigning a = 10, b = 20\n");

	// post increment
	a2 = 10;
	int c = b2 * a2++;
	printf("post increment: b * a++ = %d\n", c);

	// pre increment
	a2 = 10;
	c = b2 * ++a2;
	printf("pre  increment: b * ++a = %d\n", c);

	// logical operator
	int a3 = 10;
	int b3 = 20;
	printf("%d\n", (a3 > b3 && b3 > a3 ));

	// arithmetic operator
	int a4 = 10;
	int b4 = 20;
	int c4 = a4 * (b4 + a4);
	printf("%d\n", c4);

	return 0;

}