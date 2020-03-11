#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void _getchar_putchar();
void _gets_puts();
void _fgets_fputs();
void _strlen();
void _strcpy();
void _strcat();
void _strcmp();
void _sprintf_sscanf();
void _strchr_strstr();
void _strtok();
void _atoi();

int main()
{
	_getchar_putchar();
	_gets_puts();
	_fgets_fputs();
	_strlen();
	_strcpy();
	_strcat();
	_strcmp();
	_strchr_strstr();
	 _sprintf_sscanf();
	_strtok();
	_atoi();
	return EXIT_SUCCESS;
}

void _getchar_putchar()
{
	int ch;
	while((ch = getchar()) != EOF)
		putchar(ch);
	printf("\n");
}

void _gets_puts()
{
	char ch[100];
	char *p = gets(ch);
	int value = puts(ch);
	printf("%s", ch);
	printf("%s", p);
}

void _fgets_fputs()
{
	FILE* tmpf = tmpfile();
	fputs("Alan Turing\n", stdout);
	char buf[5];
	while(fgets(buf, sizeof buf, stdin) != NULL)
		printf("\"%s\"\n", buf);
}

void _strlen()
{
	char arr1[] = "he\nsfds\0llo";
	char arr2[] = "\0he\nsfds\0llo";
	char arr3[] = { 'h','e','l','l','o' };
	printf("arr1 len: %lu, arr2 len: %lu, arr2 len: %lu\n", strlen(arr1), strlen(arr2), strlen(arr3));
	printf("arr1 len: %lu, arr2 len: %lu, arr2 len: %lu\n", sizeof(arr1), sizeof(arr2), sizeof(arr3));
}

void _strcpy()
{
	char src[] = "test";
	char dst[10];
	char dst1[10];
	if (strcpy(dst, src) != NULL)
	{
		printf("copy success\n");
	}
	src[0] = 'a';
	printf("src: %s, size: %lu - dst: %s, size: %lu\n", src, sizeof(src), dst, sizeof(dst));
	if (strncpy(dst1, src, 3) != NULL)
	{
		printf("copy success\n");
	}
	dst1[2] = '\0';
	printf("dst1: %s - size: %lu\n", dst1, sizeof(dst1));
}

void _strcat()
{
	char src[10] = "src";
	char dst[10] = "dst";
	// strcat(dst, src);
	strncat(dst, src, 2);
	printf("src: %s, size: %lu - dst: %s, size: %lu\n", src, strlen(src), dst, strlen(dst));
}

void _strcmp()
{

	char arr1[] = "helworld";
	char arr2[] = "hel\0lorld";
	int rc1 = strcmp(arr1, arr2);
	int rc2 = strncmp(arr1, arr2, 4);
	if(rc1 == 0)
        printf("[%s] equals [%s]\n", arr1, arr2);
    else if(rc1 < 0)
        printf("[%s] precedes [%s]\n", arr1, arr2);
    else if(rc1 > 0)
        printf("[%s] follows [%s]\n", arr1, arr2);

	if(rc2 == 0)
        printf("[%s] equals [%s]\n", arr1, arr2);
    else if(rc2 < 0)
        printf("[%s] precedes [%s]\n", arr1, arr2);
    else if(rc2 > 0)
        printf("[%s] follows [%s]\n", arr1, arr2);
}

void _sprintf_sscanf()
{
	int a1, b1, a2, b2, a3, b3, a4, b4;
	char *dst1 = "2+1";
	char *dst2 = "2-1";
	char *dst3 = "2*2";
	char *dst4 = "2/2";
	char dst[20];
	sscanf(dst1, "%d+%d=", &a1, &b1);
	sscanf(dst2, "%d-%d=", &a2, &b2);
	sscanf(dst3, "%d*%d=", &a3, &b3);
	sscanf(dst4, "%d/%d=", &a4, &b4);
	sprintf(dst, "%d+%d=%d", a1, b1, a1 + b1);
	printf("%s\n", dst);
	sprintf(dst, "%d-%d=%d", a2, b2, a2 - b2);
	printf("%s\n", dst);
	sprintf(dst, "%d*%d=%d", a3, b3, a3 * b3);
	printf("%s\n", dst);
	sprintf(dst, "%d/%d=%d", a4, b4, a4 / b4);
	printf("%s\n", dst);
}

void _strchr_strstr()
{
	char* arr = "hello world hello world";
	char  target1 = 'l';
	char* target2 = "world";
	const char* result = arr;
	while((result = strchr(result, target1)) != NULL) {
    printf("Found char '%c' starting at '%s'\n", target1, result);
    ++result;
  }

	result = arr;
	while((result = strstr(result, target2)) != NULL) {
    printf("Found string '%s' starting at '%s'\n", target2, result);
    ++result;
  }

}

void _strtok()
{
	char str[] = "*#10?-ssid=test&-passwd=12345678&-netmask=255.255.255.0&-gateway=192.168.1.1&";
	char *ptr;
	printf("before strtok: %s\n", str);
	ptr = strtok(str, "?&");
	printf("ptr: %s\n", ptr);
	printf("str: %s\n", str);
	while (ptr != NULL) {
		printf("str: %s\n",str);
		ptr = strtok(NULL, "&");
		printf("ptr: %s\n", ptr);
	}
}

void _atoi()
{
	char arr[] = "100.01";
	int a = atoi(arr);
	//long a = atol(arr);
	// float a = atof(arr);
	printf("%d\n", a);
}


