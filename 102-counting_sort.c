#include "sort.h"

/**
 * get_max - the maximum val
 * @arr: array
 * @sz: size
 * Return: max int
 */
int get_max(int *arr, int sz)
{
	int max, i;

	for (max = arr[0], i = 1; i < sz; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}

	return (max);
}

/**
 * counting_sort - Sort using the counting sort algorithm
 * @arr: array
 * @sz: size
 */
void counting_sort(int *arr, size_t sz)
{
	int *count, *sorted, max, i;

	if (arr == NULL || sz < 2)
		return;

	sorted = malloc(sizeof(int) * sz);
	if (sorted == NULL)
		return;
	max = get_max(arr, sz);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)sz; i++)
		count[arr[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);

	for (i = 0; i < (int)sz; i++)
	{
		sorted[count[arr[i]] - 1] = arr[i];
		count[arr[i]] -= 1;
	}

	for (i = 0; i < (int)sz; i++)
		arr[i] = sorted[i];

	free(sorted);
	free(count);
}
