#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *arr, size_t sz, int left, int right);
void lomuto_sort(int *arr, size_t sz, int left, int right);
void quick_sort(int *arr, size_t sz);

/**
 * swap_ints - Swap fucntion
 * @a: first
 * @b: second
 */
void swap_ints(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

/**
 * lomuto_partition - Order using the lomuto partition scheme
 * @arr: The array
 * @sz: The size
 * @left: The starting index
 * @right: The ending index
 * Return: The final partition index.
 */
int lomuto_partition(int *arr, size_t sz, int left, int right)
{
	int *rot, high, low;

	rot = arr + right;
	for (high = low = left; low < right; low++)
	{
		if (arr[low] < *rot)
		{
			if (high < low)
			{
				swap_ints(arr + low, arr + high);
				print_array(arr, sz);
			}
			high++;
		}
	}

	if (arr[high] > *rot)
	{
		swap_ints(arr + high, rot);
		print_array(arr, sz);
	}

	return (high);
}

/**
 * lomuto_sort - recursive quicksort algorithm
 * @arr: An array
 * @sz: The size
 * @left: The starting index
 * @right: The ending index
 */
void lomuto_sort(int *arr, size_t sz, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(arr, sz, left, right);
		lomuto_sort(arr, sz, left, part - 1);
		lomuto_sort(arr, sz, part + 1, right);
	}
}

/**
 * quick_sort - array quicksort in asc
 * @arr: An array
 * @sz: The size
 */
void quick_sort(int *arr, size_t sz)
{
	if (arr == NULL || sz < 2)
		return;

	lomuto_sort(arr, sz, 0, sz - 1);
}
