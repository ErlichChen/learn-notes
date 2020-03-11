#include <stdio.h>
#include <stdlib.h>

// 1.declaration
extern void bubbleSort(int[], int);

int main(void)
{
	int arr[] = { 7, 4, 2, 3, 5, 8, 9, 6, 1, 10 };
	int len = sizeof(arr) / sizeof(arr[0]);
	// bubble sort
	printf("bubble sort\n\n");
	printf("Initial array: \n");
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n\n");

  // 3.call
	bubbleSort(arr, len);

	printf("Sorted array: \n");
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return EXIT_SUCCESS;
}

// 2.definition
void bubbleSort(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - i; j++ )
		{
			if (arr[j] < arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}