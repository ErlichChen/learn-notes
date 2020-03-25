#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{

	int a = 10;
	//定义一个变量 在堆中  单位是BYTE
	//char *p = (char *)malloc(sizeof(char));

	//*p = 100;
	//printf("%c\n", *p);

	//int arr[10];
	int * p = (int *)malloc(sizeof(int) * 10);

	for (int i = 0; i < 10; i++)
	{
		p[i] = i;
	}

	for (int i = 0; i < 10; i++)
		//printf("%d\n", *(p + i));
		printf("%d\n", p[i]);

	//释放   根据首地址自动释放  如果创建完的堆空间在使用结束之后不释放 会占用系统资源
	free(p);

	system("pause");
	return EXIT_SUCCESS;
}