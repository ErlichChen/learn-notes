#include <stdio.h>
#include <string.h>

////变量的定义 分配内存空间
////全局变量
//int a = 100;

int var1 = 10;
static int var2 = 100;

void sub_scope1() {
    printf("extern function\n");
}

static void sub_scope2() {
    printf("static function\n");
}