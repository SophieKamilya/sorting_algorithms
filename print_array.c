#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array
 *
 * @arr: array
 * @sz: size
 */
void print_array(const int *arr, size_t sz)
{
	size_t i;

	i = 0;
	while (arr && i < sz)
	{
		if (i > 0)
			printf(", ");
		printf("%d", arr[i]);
		++i;
	}
	printf("\n");
}
