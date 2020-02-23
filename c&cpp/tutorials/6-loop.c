#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main07()
{

	int a = 0;
	int sum = 0;
	while (a<100)
	{
		a++;//a+=1 a=a+1
		sum += a;
		//printf("a=%d\n", a);
	}
	printf("1��100�ĺ�Ϊ��%d\n", sum);
	system("pause");


int a = 0;
	do
	{
		a++;
		if (a == 100)
		{
			break;
		}
		printf("%d\n", a);
	} while (a);
	printf("%d\n", a);
	system("pause");

	return EXIT_SUCCESS;


	int index = 100;
	do
	{
		//��һ����λ�����ɸ�λ ʮλ ��λ
		int a = 0, b = 0, c = 0;
		//��λ
		a = index / 100;
		//ʮλ
		b = index / 10 % 10;
		//��λ
		c = index % 10;
		if (a*a*a + b*b*b + c*c*c == index)
		{
			printf("%d��ˮ�ɻ�\n", index);
		}
		index++;
	} while (index < 1000);

	system("pause");
	return EXIT_SUCCESS;
}