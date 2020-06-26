#include <stdio.h>
#include "../include/1_datatypes.h"
#include "../include/1_inline_asm.h"
#include "../include/12_scope.h"
#include "../include/13_memory.h"

int main(void) {
//    inline_asm();
    int select = 0;
    printf("Learn c&cpp\n");
    printf("1. data types\n");
    printf("12. scope\n");
    printf("13. memory\n");
    printf("select item: ");
    scanf("%d", &select);
    switch (select) {
        case 1:
            data_types();
            break;
        case 12:
            scope();
            break;
        case 13:
            memory();
            break;
        default:
            printf("error: no item!");
            break;
    }
    return 0;
}
