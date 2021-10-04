/*#include <stdio.h>

#include "cis27Lib.h"

#define ARR_SIZE 20

int main()
{
	// Init
	time_t t;
	srand(time(&t));
	int* arr = malloc(sizeof(int) * ARR_SIZE);

	// Construct
	for (int i = 0; i < ARR_SIZE; i++)
	{
		arr[i] = rand() % 50;
	}

	// Test
	printArray(arr, ARR_SIZE);
	insertionSort(arr, ARR_SIZE);
	printArray(arr, ARR_SIZE);
	if (findInArray(arr, ARR_SIZE, 1) != -1)
		printf("1 is in the array.");
	else
		printf("1 is not in the array.");

	// Finish
	free(arr);

	return 0;
}*/