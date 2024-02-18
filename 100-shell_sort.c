#include "sort.h"

/**
 * swap_ints - Swap function
 * @a: The first
 * @b: The second
 */
void swap_ints(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

/**
 * shell_sort - Sort using the shell sort algorithm
 * @arr: An array
 * @sz: The size
 */
void shell_sort(int *arr, size_t sz)
{
	size_t gap, i, j;

	if (arr == NULL || sz < 2)
		return;

	for (gap = 1; gap < (sz / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < sz; i++)
		{
			j = i;
			while (j >= gap && arr[j - gap] > arr[j])
			{
				swap_ints(arr + j, arr + (j - gap));
				j -= gap;
			}
		}
		print_array(arr, sz);
	}
}
