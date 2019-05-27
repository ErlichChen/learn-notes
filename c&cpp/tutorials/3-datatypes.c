#include <stdio.h>

#define PI 3.1415926;

int main(void)
{
	int a;
	a = 1;
	int size_a = sizeof(a);

	const int b = 2;
	int size_b  = sizeof(b);

	float c = 3.14;
	int size_c = sizeof(c);

	double d = PI;
	int size_d = sizeof(d);

	char e = 'a';
	int size_e = sizeof(e);

	short f = 3;
	int size_f = sizeof(f);

	long g = 4;
	int size_g = sizeof(g);

	printf("int %d ---> size %d\n", a, size_a);
	printf("int %d ---> size %d\n", b, size_b);
	printf("float %f ---> size %d\n", c, size_c);
	printf("double %f ---> size %d\n", d, size_d);
	printf("char %c ---> size %d\n", e, size_e);
	printf("short %d ---> size %d\n", f, size_f);
	printf("long %ld ---> size %d\n", g, size_g);
	return 0;
}