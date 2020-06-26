#include <stdio.h>
#include <limits.h>
#include <float.h>

#define PI 3.1415926;

void data_types()
{
    printf("**************************************************\n");
    printf("*****              1.date types              *****\n");
    printf("**************************************************\n\n");

	char           c_min  = -128; // CHAR_MIN
    char           c_max  = 127;  // CHAR_MAX
	unsigned char  uc_min = 0;
    unsigned char  uc_max = 255;  // UCHAR_MAX
    short          s_min  = -32768; // SHRT_MIN
    short          s_max  = 32767;  // SHRT_MIN
    unsigned short us_min = 0;
    unsigned short us_max = 65535;  // USHRT_MAX
    int            i_min  = -2147483648; // INT_MIN
    int            i_max  = 2147483647;  // INT_MAX
    unsigned int   ui_min = 0;
    unsigned int   ui_max = 4294967295;  // UINT_MAX
    long           l_min  = -9223372036854775808; // LONG_MIN
    long           l_max  = 9223372036854775807;  // LONG_MAX
    unsigned long  ul_min = 0;
    unsigned long  ul_max = 18446744073709551615; // ULONG_MAX

    printf("type char min %d, max %d size %d\n", c_min, c_max, sizeof(c_max));
    printf("type unsigned char min %d, max %d size %d\n", uc_min, uc_max, sizeof(uc_max));

    printf("type short min %d, max %d size %d\n", s_min, s_max, sizeof(s_max));
    printf("type unsigned short min %d, max %d size %d\n", us_min, us_max, sizeof(us_max));

    printf("type int min %d, max %d size %d\n", i_min, i_max, sizeof(i_max));
    printf("type unsigned int min %d, max %d size %d\n", ui_min, ui_max, sizeof(ui_max));

    printf("type long min %d, max %d size %d\n", l_min, l_max, sizeof(l_max));
    printf("type unsigned long min %d, max %d size %d\n", ul_min, ul_max, sizeof(ul_max));

    int i10  = 15;

    printf("number: %d, dec: %d, oct: %o, hex: %x\n", i10, i10, i10, i10);

//    printf("Range of signed char %d to %d\n", SCHAR_MIN, SCHAR_MAX);
//    printf("Range of unsigned char 0 to %d\n\n", UCHAR_MAX);

    float  i1 = 129;
    double i2 = 255;

	printf("%d \n", i1);
    printf("%d \n", i2);

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
//	char ta1 = 'a';
//	int  tb1 = ta1;
//	printf("char: %c - int: %d\n", ta1, tb1);
//
//	float ta2 = 1.1;
//	int   tb2 = (int)ta2;
//	printf("float: %f - int: %d\n", ta2, tb2);
//
//	int ta3 = 129;
//	char tb3 = (char)ta3;
//	printf("number: 129 - int: %d - char: %d\n\n", ta3, tb3);


//	printf("Range of float %e to %e\n", FLT_MIN, FLT_MAX);
//	printf("Range of double %e to %e\n", DBL_MIN, DBL_MAX);
//	printf("Range of long double %Le to %Le\n", LDBL_MIN, LDBL_MAX);
}