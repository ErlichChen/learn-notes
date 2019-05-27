#include <stdio.h>

int gcd(int var1, int var2)
{
	int result = 0;
	__asm__ __volatile__ (
		"movl %1, %%eax;"
		"movl %2, %%ebx;"
		"CONTD: cmpl $0, %%ebx;"
		"je DONE;"
		"xorl %%edx, %%edx;"
		"idivl %%ebx;"
		"movl %%ebx, %%eax;"
		"movl %%edx, %%ebx;"
		"jmp CONTD;"
		"DONE: movl %%eax, %0;"
		:"=r"(result)
		:"r"(var1), "r"(var2)
	);
	return result;
}

int main(void)
{
	int result = 0;
  int input = 1;

	asm volatile (
	    "movl %1, %0\n"
	    : "=r"(result)
	    : "r"(input)
	    );

	printf("result = %d\n", result);
	printf("input = %d\n", input);
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

	int first = 15, second = 35;
	result = gcd(first, second);
	printf("result = %d\n", result);
	return 0;
}

