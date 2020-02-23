#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

	int a, b, c;
	// scanf("%d %d %d", &a, &b, &c);
	// printf("which one is max? \n");

	// if (a > b)
	// {
	// 	if (a > c)
	// 	{
	// 		printf("a is max %d", a);
	// 	}
	// 	else
	// 	{
	// 		printf("c is max %d", c);
	// 	}
	// } else {
	// 	if (b > c)
	// 	{
	// 		printf("b is max %d", b);
	// 	}
	// 	else
	// 	{
	// 		printf("c is max %d", c);
	// 	}
	// }

	int index = 100;
	do
	{
		int a = 0, b = 0, c = 0;
		a = index / 100;
		b = index / 10 % 10;
		c = index % 10;
		if (a*a*a + b*b*b + c*c*c == index)
		{
			printf("%d是水仙花\n", index);
		}
		index++;
	} while(index < 1000);

	for(int i = 0; i <= 9; i++)
	{
		for(int j = 0; j <= 9; j++)
		{
			printf("%dx%d=%d ", i, j, i * j);
		}
		printf("\n");
	}


	system("pause");
	return EXIT_SUCCESS;


	int a = 40;
	int b = 50;
	int c = 30;
	//��Ŀ
	//int d = a>b ? 1 : 0;
	//����ʽ1?(����ʽ2?���1:���2):(����ʽ3?���1:���2);
	int d = a > b ? (a > c ? a : c) :( b > c ? b : c);
	printf("%d\n", d);

	return EXIT_SUCCESS;

	int a;
	scanf("%d", &a);
	//switch (a)
	//{
	//case 1:
	//	printf("a��ֵΪ��%d", a);
	//	break;
	//case 10:
	//	printf("a��ֵΪ��%d\n", a);
	//	break;
	//default:
	//	printf("a��ɶ��\n");
	//	break;
	//}

	switch (a/10)
	{
	case 10:
		//printf("����\n");
		//break;
	case 9:
		printf("����\n");
		break;
	case 8:
		printf("����\n");
		break;
	case 7:
		//printf("����\n");
		//break;
	case 6:
		printf("����\n");
		break;
	default:
		printf("������\n");
		break;
	}
}