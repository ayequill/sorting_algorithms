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
* selection_sort - Sorts an array using the selection
* the selection algorithm.
*
* @array: The array to be sorted.
* @size: Size of the array.
*
* Return: Nothing.
*/

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_pos;

	for (i = 0; i < size - 1; i++)
	{
		min_pos = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_pos])
				min_pos = j;
		}
		if (min_pos != i)
			{
			swap_integers(&array[i], &array[min_pos]);
			print_array(array, size);
			}

	}
}
