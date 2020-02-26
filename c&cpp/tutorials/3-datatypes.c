#include <stdio.h>
#include <limits.h>
#include <float.h>

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

	printf("int %d size %d\n", a, size_a);
	printf("int %d size %d\n", b, size_b);
	printf("float %f size %d\n", c, size_c);
	printf("double %f size %d\n", d, size_d);
	printf("char %c size %d\n", e, size_e);
	printf("short %d size %d\n", f, size_f);
	printf("long %ld size %d\n", g, size_g);

	// decimal
	int dec = 10;
	printf("dec 10: %d\n", dec);

	// octonary
	int oct = 010;
	printf("oct 010: %o\n", oct);

	// hexadecimal
	int hex = 0x10;
	printf("hex 0x10: %x\n", hex);

	char ch;
	ch = 0x5f + 2;
	// ch = 0x7f + 2; warning: implicit conversion from 'int' to 'char' changes value from 129 to -127
	printf("char ch: %c\n",ch);
	printf("number ch: %d\n",ch);

	float r = 2;
	float s1 = r * r * 3.14;

	printf("%1.2f\n", s1);

	double r2 = 2.0;
	double s2 = r2 * r2 * 3.14;
	printf("%f\n", s2);

	// type casting
	char ta1 = 'a';
	int  tb1 = ta1;
	printf("char: %c - int: %d\n", ta1, tb1);

	float ta2 = 1.1;
	int   tb2 = (int)ta2;
	printf("float: %f - int: %d\n", ta2, tb2);

	int ta3 = 129;
	char tb3 = (char)ta3;
	printf("number: 129 - int: %d - char: %d\n\n", ta3, tb3);

	printf("Range of signed char %d to %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("Range of unsigned char 0 to %d\n\n", UCHAR_MAX);

	printf("Range of signed short int %d to %d\n", SHRT_MIN, SHRT_MAX);
	printf("Range of unsigned short int 0 to %d\n\n", USHRT_MAX);

	printf("Range of signed int %d to %d\n", INT_MIN, INT_MAX);
	printf("Range of unsigned int 0 to %u\n\n", UINT_MAX);

	printf("Range of signed long int %ld to %ld\n", LONG_MIN, LONG_MAX);
	printf("Range of unsigned long int 0 to %lu\n\n", ULONG_MAX);

	// In some compilers LLONG_MIN, LLONG_MAX
	// printf("Range of signed long long int %lld to %lld\n", LONG_LONG_MIN, LONG_LONG_MAX);
	printf("Range of signed long long int %lld to %lld\n", LLONG_MIN, LLONG_MAX);
	// In some compilers ULLONG_MAX
	// printf("Range of unsigned long long int 0 to %llu\n\n", ULONG_LONG_MAX);
	printf("Range of unsigned long long int 0 to %llu\n\n", ULLONG_MAX);

	printf("Range of float %e to %e\n", FLT_MIN, FLT_MAX);
	printf("Range of double %e to %e\n", DBL_MIN, DBL_MAX);
	printf("Range of long double %Le to %Le\n", LDBL_MIN, LDBL_MAX);

	return 0;
}