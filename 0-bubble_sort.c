#include "sort.h"

/**
 * swap_ints - Swap function
 * @a: integer
 * @b: integer
 */
void swap_ints(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

/**
 * bubble_sort - Sorting an array of integers in asc-order.
 * @arr: An array of integers to sort.
 * @sz: The size of the array.
 */
void bubble_sort(int *arr, size_t sz)
{
	size_t i, lenght = sz;
	bool bub = false;

	if (arr == NULL || sz < 2)
		return;

	while (bub == false)
	{
		bub = true;
		for (i = 0; i < lenght - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap_ints(arr + i, arr + i + 1);
				print_array(arr, sz);
				bub = false;
			}
		}
		lenght--;
	}
}
