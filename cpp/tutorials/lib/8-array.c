#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int arr[4] = {1, 2, 3, 4};
	int len  = sizeof(arr);
	int size = sizeof(arr[0]);
	printf("The number of array is %d\n", len / size);

	// stack momery
	printf("Array address: %p\n", arr);
	printf("1st element address: %p\n", &arr[0]);
	printf("2nd element address: %p\n", &arr[1]);

	// dimensional array
	int arr2[3][3] =
	{
		{1,2,3},
		{2,3,4},
		{3,4,5}
	};

	printf("double dimensional array length is %lu\n", sizeof(arr2));
	int column = sizeof(arr2[0]) / sizeof(arr2[0][0]);
	int row = sizeof(arr2) / sizeof(arr2[0]);
	printf("column size: %d\n", column);
	printf("  row  size: %d\n", row);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			scanf("%d", &arr2[i][j]);
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			printf("%d\t", arr2[i][j]);
			if (j == column - 1) {
				printf("\n");
			}
		}
	}

	printf("2-d arrary address: %p\n", arr2);
	printf("2-d arrary 1-row address: %p\n", arr2[0]);
	printf("2-d arrary 2-row address: %p\n", arr2[1]);

	printf("1-1 element address: %p\n", &arr2[0][0]);
	printf("1-2 element address: %p\n", &arr2[0][1]);
	printf("2-1 element address: %p\n", &arr2[2][0]);
	printf("3-3 element address: %p\n", &arr2[2][2]);


	//字符数组
	//char arr[10] = { 'H','e','l','l','o' };
	//char arr[] = { 'H','e','\','0','o' };
	//char arr[] = "h\n\0e\nllo";
//	char arr[100];
//	scanf("%[^\n]", arr);

	//%s会接收字符串结束标志【'\0'】之前的所有字符 在ASCII中就是数字0
//	printf("%s", arr);

	//for (int i = 0; i < 10; i++)
	//{
	//	printf("%c", arr[i]);
	//}
	//printf("%d\n", sizeof(arr));
	//system("pause");

//	char arr1[] = "hello";//01234
//	char arr2[] = "world";
//	char arrBuf[100];//'\0'
//
//	int index = 0;
//	while (arr1[index] != '\0')
//	{
//		//1、将非\0的字符添加到arrbuf
//		arrBuf[index] = arr1[index];
//		//2、计数器增长
//		index++;
//	}
//	while (arr2[index - 5] != '\0')
//	{
//		arrBuf[index] = arr2[index - 5];
//		index++;
//	}
//
//	//添加字符串结束标志
//	arrBuf[index] = '\0';
//	printf("%s", arrBuf);
//	system("pause");

	return EXIT_SUCCESS;
}


#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include <time.h>

/*
1、添加头文件 time.h  stdlib.h
2、添加随机数种子 srand((unsigend int )time(NULL));
3、生成随机数 rand()  %
*/
//int main15()
//{
//	srand((unsigned int)time(NULL));
//	for (int i = 0; i < 100; i++)
//	{
//		printf("%d\n", rand() % 11 + 50);//50-60
//	}
//
//
//	//system("pause");
//	return EXIT_SUCCESS;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include <time.h>
//
//int main()
//{
//	srand((unsigned int)time(NULL));
//	//双色球  两种原色 红球 + 蓝球 （6+1）  红球 1-33   蓝球 1-16  打印双色球中奖信息
//	//红色球不能重复  蓝球和红球可以重复
//	int ball[6];
//
//	//红色
//	for (int i = 0; i < 6; i++)
//	{
//		// qiu = rand()%33+1;
//		ball[i] = rand() % 33 + 1;
//		//去重
//		for (int j = 0; j < i; j++)
//		{
//			if (ball[i] == ball[j])
//			{
//				i--;
//				continue;
//			}
//		}
//	}
//
//	//排序
//	for (int i = 0; i < 6; i++)
//	{
//		printf("%d   ", ball[i]);
//	}
//	printf("+   %d\n", rand() % 16 + 1);
//	system("pause");
//	return EXIT_SUCCESS;
//}