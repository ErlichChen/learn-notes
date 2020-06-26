#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define BUBBLE_SIZE 20

int *allocate_memory(int);
void release_memory(int *);
void bubble_sort();
void copy_string(char *);
void memory_set();

void memory(void)
{
    int *p;
    int exit = 0;
    int size;
    char *str = "Hello C&CPP";
    while (!exit)
    {
        int item;
        printf("1. allocate memory\n");
        printf("2. release memory\n");
        printf("3. bubble sort\n");
        printf("4. copy string\n");
        printf("5. set memory\n");
        printf("select item: ");
        scanf("%d", &item);
        switch (item) {
            case 0:
                release_memory(p);
                exit = 1;
                break;

            case 1:
                printf("allocate size: ");
                scanf("%d", &size);
                allocate_memory(size);
                exit = 0;
                break;

            case 2:
                release_memory(p);
                exit = 1;
                break;

            case 3:
                bubble_sort();
                exit = 1;
                break;

            case 4:
                copy_string(str);
                exit = 1;
                break;

            case 5:
                memory_set();
                exit = 1;
                break;

            default:
                release_memory(p);
                exit = 1;
                break;
        }
    }

}

int *allocate_memory(int size)
{
    int *p = (int *)malloc(sizeof(int) * size);
    return p;
}

void release_memory(int *p)
{
    if (p != NULL)
    {
        free(p);
    }

    if (p != NULL)
    {
        printf("p != NULL");
    } else {
        printf("p == NULL");
    }
}

void bubble_sort()
{
    srand((unsigned int)time(NULL));
    int *p = (int *)malloc(sizeof(int) * BUBBLE_SIZE);
    //int len = sizeof(p)
    for (int i = 0; i < BUBBLE_SIZE; i++)
    {
        p[i] = rand() % 50;
        // *(p + i) = rand() % 50;
        // *p++ = rand() % 50;
    }
    printf("unordered array: \n");
    for (int i = 0; i < BUBBLE_SIZE; i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n");
    for (int i = 0; i < BUBBLE_SIZE - 1; i++)
    {
        for (int j = 0; j < BUBBLE_SIZE - i - 1; j++)
        {
            if (p[j] > p[j + 1])
            {
                int temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
        printf("ordering %d: ", i);
        for (int k = 0; k < BUBBLE_SIZE; k++)
        {
            printf("%d ", p[k]);
        }
        printf("\n");
    }
    printf("ordered array: \n");
    for (int i = 0; i < BUBBLE_SIZE; i++)
    {
        printf("%d ", p[i]);
    }
    free(p);
}

void copy_string(char *str)
{
    char *p1 = "hello c";
    char *p2 = "hello c";
    char *p3 = malloc(sizeof(char) * 10);
    strcpy(p3, "hello c");

    printf("p1 p2 point to same string %s, p3 is new malloc memory.\n", p1);
    printf("p1: %p\n", p1);
    printf("p2: %p\n", p2);
    printf("p3: %p\n", p3);
    free(p3);

    char *newStr = (char *)malloc(sizeof(char) * strlen(str));
    printf("%p\n", newStr);
    strcpy(newStr, str);
    printf("%p\n", newStr);
    newStr[6] = 'E';
    printf("%s\n", newStr);
    free(newStr);
}


void memory_set()
{
    int *p = (int *)malloc(sizeof(int) * 10);
    memset(p, 0, 10);
    memset(p, 1, 5);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", p[i]);
    }
    free(p);

    //memset(p, 0, 40);
    //for (int i = 0; i < 10; i++)
    //{
    //	printf("%d\n", p[i]);
    //}
    //char * p = malloc(sizeof(char) * 10);
    //memset(p, 0, 10);
    //printf("%s\n", p);


//    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//    memset(arr, 0, 40);
//    for (int i = 0; i < 10; i++)
//    {
//        printf("%d\n", arr[i]);
//    }


}
int main1502()
{
    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
    //int *p = malloc(sizeof(int) * 10);
    //memcpy(p, arr, 40);
    //for (int i = 0; i < 10; i++)
    //{
    //	printf("%d\n", p[i]);
    //}

    //free(p);

    memcpy(&arr[2], arr, 20);
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", arr[i]);
    }
    char arr1[] = { 'h','e','l','l','o' };
    char * p = malloc(100);
    memset(p, 0, 100);
    //1、函数参数不同
    //2、strcpy拷贝字符串 memcpy 可以拷贝一块内存
    //3、拷贝结束标志不同 strcpy \0 memcpy  以个数为结尾
    strcpy(p, arr1);
    memcpy(p, arr1, 5);
    printf("%s\n", p);
    free(p);
    return 0;
}

int main1503()
{
    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
    //memmove拷贝重叠内存地址不会出现问题  但是效率比较低   如果拷贝源和拷贝目标没有重叠  两个函数效率一样
    memmove(&arr[2], arr, 20);

    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", arr[i]);
    }
}
int main121()
{
    //int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
    //int arr2[5] = { 1,2,3,4 };

    //int val = memcmp(arr1, arr2, 20);
    //if (!memcmp(arr1, arr2, 8))
    //{
    //	printf("前两个数组元素内容相同");
    //}
    //printf("%d\n", val);

    //int * p1 = malloc(sizeof(int) * 10);
    //char * p2 = malloc(sizeof(char) * 40);

    //memcpy(p1, "hello", 6);
    //memcpy(p2, "hello", 6);
    //if (!memcmp(p1, p2, 6))
    //{
    //	printf("内容相同\n");
    //}
    //else
    //{
    //	printf("内容不相同\n");

    //}

    int a = 0xffff;
    char b = 0xffff;
    //printf("%d\n", b);
    if (!memcmp(&a, &b, 2))
    {
        printf("内容相同\n");
    }
    else
    {
        printf("内容不相同\n");

    }

    //free(p1);
    //free(p2);
    //练习   求出三名学生 三门功课成绩 并排序   通过堆空间来实现  arr[3][3];
    int ** p = (int **)malloc(sizeof(int *) * 3);
    p[0] = (int *)malloc(sizeof(int) * 3);
    p[1] = (int *)malloc(sizeof(int) * 3);
    p[2] = (int *)malloc(sizeof(int) * 3);

    p[0][0] = 90;
    p[0][1] = 80;
    p[0][2] = 70;

    //排序

    free(p[0]);
    free(p[1]);
    free(p[2]);

    free(p);


    return 0;
}