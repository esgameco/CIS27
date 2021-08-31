#include <stdio.h>

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

	// Finish
	free(arr);

	return 0;
}