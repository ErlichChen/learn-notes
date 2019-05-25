# C语言中内嵌汇编

## x86汇编的两种语法

x86汇编在intel的官方文档中使用intel语法，Windows也使用intel语法，
而UNIX平台的汇编器一直使用AT&T语法。
mov %edx,%eax 这条指令如果用intel语法来写，就是 mov eax,edx ，寄存器名不加 % 号，
并且源操作数和目标操作数的位置互换。

## 限制符

| 限定符 | 说明  |
|:-----:|:----:|
| r | 通用寄存器 |
| a | eax, ax, al |
| b | ebx, bx, bl |
| c | ecx, cx, cl |
| d | edx, dx, dl |
| S | esi, si |
| D | edi, di |
| q | 寄存器a, b, c, d |
| m | 内存 |
| g | 任意寄存器, 内存， 立即数 |

## 示例

```c
#include <stdio.h>

int main()
{
    int result = 0;
    int input = 1;

    int a = 1;
    int b = 2;

		// %1代表input对应的寄存器
		// %0代表result对应的寄存器
    asm volatile (
        "movl %1, %0\n"
        : "=r"(result) // 输出
        : "r"(input)   // 输入
        );

    printf("result = %d\n", result);
    printf("input = %d\n", input);

	  //"=a"(a), "=b"(b) 代表输出参数，且将EAX寄存器与变量a关联，将EBX寄存器与b相连
    //"a"(a), "b"(b)   代表输入参数，且将EAX寄存器与变量a关联，将EBX寄存器与b相连
    asm volatile (
        "movl %%eax, %%ecx\n"
        "movl %%ebx, %%eax\n"
        "movl %%ecx, %%ebx\n"
        : "=a"(a), "=b"(b)
        : "a"(a), "b"(b)
        );

    printf("a = %d\n", a);
    printf("b = %d\n", b);

    return 0;
}
```

## 内嵌汇编进行系统调用