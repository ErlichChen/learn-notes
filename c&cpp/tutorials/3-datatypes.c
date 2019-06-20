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

	// decimal
	int dec=10;
	printf("%d\n", dec);

	// octonary
	int oct=010;
	printf("%o\n", oct);

	// hexadecimal
	int hex=0X10;
	printf("%x\n", hex);

	char ch;
	ch=0x5f+2;
	// ch=0x7f+2; warning: implicit conversion from 'int' to 'char' changes value from 129 to -127
	printf("%c\n",ch);
	// printf("%d\n",ch);

	float r = 2;
	float s1 = r * r * 3.14;

	printf("%1.2f\n", s1);

	double r2 = 2.0;
	double s2 = r2 * r2 * 3.14;
	printf("%f\n", s2);

	return 0;
}