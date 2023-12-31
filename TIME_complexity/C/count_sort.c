#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void print_array(const int *array, size_t size);

/**
 * counting_sort - sorts an array of integers in ascending
 * order using the Counting sort algorithm
 * @array: Our array.
 * @size: size of the array.
 */
void counting_sort(int *array, size_t size)
{
    int j, *count, *output, max = array[0];
    size_t i;

    if (!array || size < 2)
        return;

    for (i = 0; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    output = malloc(sizeof(int) * size);
    if (!output)
    {
        free(output);
        return;
    }
    count = malloc(sizeof(int) * (max + 1));
    if (!count)
    {
        free(count);
        free(output);
        return;
    }
    for (j = 0; j <= max; j++)
        count[j] = 0;
    for (i = 0; i < size; i++)
        count[array[i]]++;
    for (j = 1; j <= max; j++)
        count[j] += count[j - 1];
    print_array(count, max + 1);
    for (i = size - 1; i < size; i--)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }
    for (i = 0; i < size; i++)
        array[i] = output[i];
    free(count);
    free(output);
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */

int *generate(size_t size)
{
	size_t i;
	int *arr = malloc(sizeof(int) * size);

	srand(time(NULL) * rand());

	for (i = 0; i < size; i++)
		arr[i] = rand() % 1000;

	return (arr);
}

// int main(void)
// {
//     int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
//     size_t n = sizeof(array) / sizeof(array[0]);

//     print_array(array, n);
//     printf("\n");
//     counting_sort(array, n);
//     printf("\n");
//     print_array(array, n);
//     return (0);
// }

int main(void)
{
	size_t i, flag;
	int *array, n;

	srand(time(NULL) * rand());
	n = rand() % 1000;
	array = generate(n);
    
	print_array(array, n);
	printf("\n");
	counting_sort(array, n);
	printf("\n");
	print_array(array, n);

	for (i = 0, flag = 0; n > 1 && i < n - 1; i++)
	{
		if (array[i] > array[i + 1])
			flag = 1;
	}

	if (flag == 1)
		printf("FAILURE !!!!!\n");
	else
		printf("SUCCESS !!!\n");
	free(array);
	return (0);
}


/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}