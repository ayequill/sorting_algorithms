#include "sort.h"
/**
* swap_integers - Swaps two integers
*
* @n: First integer
* @m: Second integer
*
* Return: Nothing
*/

void swap_integers(int *n, int *m)
{
	int temp;

	temp = *n;
	*n = *m;
	*m = temp;
}

/**
* partition - splits  the array between low - high
* Description: Splits the array using Lomuto Algorithm
* @array: array to be split
* @low: left side of array
* @high: rigth side of array
*
* Return: Returns the index of the pivot
*/

int partition(int array[], int low, int high,
		size_t size
)
{
	int pivot_value, i, j;

	/* The pivot is always the last element */
	pivot_value = array[high];

	/* i will point to the position where the pivot should be placed */
	i = low - 1;

	/* j will traverse the array */
	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot_value)
		{
			i++;
			if(i != j)
			{
				swap_integers(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	/* Place the pivot in its correct position */
	if(i + 1 != high)
	{
		swap_integers(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	/* Return the index of the pivot */
	return (i + 1);
}

/**
* sort_array - Sorts the array using quick sort.
* @array: array to be sorted.
* @low: left side of array
* @high: rigth side of array
*
*/

void sort_array(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);

		sort_array(array, low, pivot - 1, size);
		sort_array(array, pivot + 1, high, size);
	}
}

/**
* quick_sort - A wrapper function for quick sort.
* @array: array to be sorted
* @size: size of the array
*
*/

void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	sort_array(array, 0, size - 1, size);
}
