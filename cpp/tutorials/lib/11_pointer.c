#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* removeSpace(char*);
char* getPointer();
char* newStrstr(char*, char*);
void  bubbleSort1(int*, int len);
void  bubbleSort2(char**, int len);

void pointer()
{

    数字指针
    字符指针
    字符串指针

	char arr1[] = "h e l l o";
	int size = strlen(arr1);
	char arr2[size];
	removeSpace(arr1, arr2);
	printf("before: %s\n", arr1);
	printf(" after: %s\n", arr2);

//	printf("[int  **] size: %lu\n", sizeof(int **));
//	printf("[int ***] size: %lu\n", sizeof(int ***));
//	printf("[void  *] size: %lu\n", sizeof(void *));
//
//	int arr3[10] = {1,2,3};
//	printf("arr {1,2,3} 1th element: %d - addr: %p\n", *arr3, &arr3[0]);
//	printf("arr {1,2,3} 2nd element: %d - addr: %p\n", *(arr3 + 1), arr3 + 1);
//	printf("arr {1,2,3} 3td element - 1th element distance: %ld\n", &arr3[2] - &arr3[0]);
//
//	char *arr4 = getPointer();
//	printf("inside pointer: %s\n", arr4);
//
//	char *p = newStrstr("testtest", "tt");
//	printf("%s\n", p);


//	int a = 10;
//	int *p1 = &a;
//	int *p2 = NULL;
//	// *p2 = *p1; // error, value pass value.
//	p2 = p1;
//
//	int arr5[] = { 1, 3, 5, 8, 9, 2, 7, 4, 6, 0 };
//	char *arr6[] = { "cshdf", "ehsdhf", "bjhdjfhd","abee" };
//
//	bubbleSort1(arr5, 10);
//	bubbleSort2(arr6, 4);
//
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d", arr5[i]);
//	}
//	printf("\n");
//	for (int i = 0; i < 4; i++)
//	{
//		printf("%s ", arr6[i]);
//	}
//	printf("\n");
}

char* removeSpace(char *arr) {
    int len = strlen(arr);
    char newStr[10] = {};
    while (*arr != '\0')
    {
        if (*arr != ' ')
        {
            *newStr = *arr;
        }
        arr++;
    }
}

//void removeSpace(char *arr, char *newArr)
//{
//
//	char *start = arr;
//	int size = strlen(arr);
//	int index = 0;
//	for(int i = 0; i < size; i++)
//	{
//		if (*(start + i) != ' ')
//		{
//			*(newArr + index) = *(start + i);
//			index++;
//		}
//	}
//}

char* getPointer()
{
	// string array store in function stack.
	// char arr[] = "hello world";
	// string literal store in constant area.
	char *arr = "hello world";
	return arr;
}

char* newStrstr(char* dst, char* src)
{
	int i = 0;
	int dstLen = strlen(dst);
	int srcLen = strlen(src);
	char *p = NULL;

	while ((i < dstLen) && ((dstLen - i >= srcLen)))
	{
		int count = 0;
		while((count < srcLen) && (*(dst + i + count) == *(src + count)))
		{
			count++;
			if (count == srcLen) {
				p = &dst[i];
				return p;
			}
		}
		i++;
	}
	return p;
}

void bubbleSort1(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		int sorted = 1;
		for (int j = 0; j < (len - i - 1); j++)
		{
			if (*(arr + j) > *(arr + j + 1)) {
				sorted = 0;
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
		if (sorted) return;
	}
}

void bubbleSort2(char **arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		int sorted = 1;
		for (int j = 0; j < (len - i -1); j++)
		{
			// if (**(arr + j) > **(arr + j + 1))
			// {
			// 	sorted = 0;
			// 	char *tmp = *(arr + j);
			// 	*(arr + j) = *(arr + j + 1);
			// 	*(arr + j + 1) = tmp;
			// }

			// if (arr[j][0] > arr[j + 1][0])
			// {
			// 	sorted = 0;
			// 	char *temp = arr[j];
			// 	arr[j] = arr[j + 1];
			// 	arr[j + 1] = temp;
			// }

			if (*arr[j] > *arr[j + 1])
			{
				sorted = 0;
				char *temp = &arr[j][0];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

}

int main801()
{

	char arr[] = "hello world";//ABllo world
	char * p;
	p = arr;
	*p = 'A';//arr[0] p[0]

	p++;//arr[1] p[1]
	*p = 'B';
	printf("%s\n", arr);
	printf("%lu\n", sizeof(arr));//12
	printf("%lu\n", strlen(arr));//11
	printf("%lu\n", sizeof(p));//4
	printf("%lu\n", strlen(p));//1 4 10

	system("pause");
	return EXIT_SUCCESS;
}

int main08()
{
	char *arr = "hello world";//常量区
	char  arr1[] = "hello world";//栈区
	printf("%s\n", arr);
	printf("%c\n", arr[0]);
	char *p = arr;
	printf("%p\n", p);
	//字符串常量是一个常量的数组 可以读取字符或者字符串  但是不能修改
	//p[0] = 'A';
	//*p = 'A';
	p = arr1;
	printf("%p\n", p);

	//p[0] = 'A';
	//*p = 'A';
	//printf("%s", p);
}

void mystrcat(char * arr,char * s1)
{
	//while (*arr)
	//	arr++;
	//while (*arr++ = *s1++);
	while (*arr)
		arr++;
	while (*s1)
	{
		*arr = *s1;
		arr++;
		s1++;
	}
	*arr = '\0';
}
void main09()
{
	char arr[100] = "hello";
	char * s1 = "world";
	mystrcat(arr, s1);
	printf("%s\n", arr);
}
