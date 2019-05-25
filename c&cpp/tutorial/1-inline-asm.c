#include <stdio.h>

int main(void)
{
	printf("Hello world\n");
	int a;
	int b;
	int c;
	a = 10;
	b = 20;
	c = a + b;
	asm volatile (
		"movl %%eax, %%ecx\n"
		"movl %%ebx, %%eax\n"
		"movl %%ecx, %%ebx\n"
		: "=a"(a), "=b"(b)
		: "a"(a), "b"(b)
	);

	printf("a = %d\n", a);
	printf("b = %d\n", b);

	return 0;
}