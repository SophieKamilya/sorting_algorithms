#include "sort.h"

/**
 * swap_ints - Swap function
 * @a: first int
 * @b: second int
 */
void swap_ints(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

/**
 * selection_sort - Sort using the selection sort algorithm
 * @arr: An array of integers.
 * @sz: The size of the array.
 */
void selection_sort(int *arr, size_t sz)
{
	int *minimum;
	size_t i, j;

	if (arr == NULL || sz < 2)
		return;

	for (i = 0; i < sz - 1; i++)
	{
		minimum = arr + i;
		for (j = i + 1; j < sz; j++)
			minimum = (arr[j] < *minimum) ? (arr + j) : minimum;

		if ((arr + i) != minimum)
		{
			swap_ints(arr + i, minimum);
			print_array(arr, sz);
		}
	}
}
