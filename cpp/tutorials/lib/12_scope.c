#include <stdio.h>
#include <string.h>
#include "../include//12_scope.h"

extern int var1;
// error: static var
// extern int var2;

extern void sub_scope1();
// error: static function
// extern void sub_scope2();

void scope()
{
	printf("extern var: %d\n", var1);
    // printf("%d", var2);

    sub_scope1();
    // sub_scope2();
}



//int main01()
//{
//    printf("%d\n", a);
//    //变量的作用范围：从创建到所在函数结束
//    int a = 10;
//
//    printf("=================\n");
//    //{//程序体 代码体  函数体}
//    //int *p;
//    //{
//    //	printf("%d\n", a);
//    //	int a = 1000;
//    //	p = &a;
//    //	printf("%d\n", a);
//    //}
//    //int b = 100;
//    //printf("p=%d\n", *p);
//    printf("=================\n");
//
//    int i = 100;
//    for (int i = 0; i < 10; i++)
//    {
//        printf("%d\n", i);
//    }
//    printf("%d\n", i);
//    printf("=================\n");
//
//    //int i = 100;
//    fun01(a,a,a);
//    printf("%d\n", a);
//    //system("pause");
//    return EXIT_SUCCESS;
//}
////如果全局变量写在主函数下面 想使用需要申明
////int a = 100;


//extern  int a1;
//extern  int a2;

//static  int a1 = 10;
//int a2 = 100;
void fun02()
{
    //static int a = 10;
    //a++;
    //int a = 10;
    //printf("%d\n", a++);
}
int main03()
{
    //int a1 = 10;
    //a1 = 100;
    ////静态局部变量
    //static int a2 = 10;
    //a2 = 100;
    //printf("%d\n", a1);
    //printf("%d\n", a2);

    //for (int i = 0; i < 10; i++)
    //{
    //	fun02();
    //}
    //static int a = 10;
    //赋值
    //a1 = 100;
    //printf("%d\n", a1);
    //a2 = 1000;
//    printf("%d\n", a2);
}

//int a = 10;