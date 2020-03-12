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

	return EXIT_SUCCESS;
}