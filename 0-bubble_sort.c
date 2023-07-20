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
* bubble_sort - Uses the bubble sort
* algorithm to sort integers in an array
*
* @array: The array to be sorted
* @size: size of the array
*
* Return: Returns an elements in the array
* in an accending order.
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int has_swapped;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
{
	has_swapped = 0;
	for (j = 0; j < size - 1 - i; j++)
{
	if (array[j] > array[j + 1])
	{
		swap_integers(&array[j], &array[j + 1]);
		print_array(array, size);
		has_swapped = 1;
	}

}
	if (!has_swapped)
		break;
}
}
