#include "sort.h"
#include <stdlib.h>

void merge_sort(int *array, size_t size)
{
    if (array && size > 1)
        top_down_merge(array, 0, size - 1);
}

void top_down_merge(int *array, size_t left, size_t right)
{
    size_t mid = left + (right - left) / 2;

    if (left < right)
    {
        top_down_merge(array, left, mid);
        top_down_merge(array, mid + 1, right);

        merge(array, left, mid, right);
    }
}

void merge(int *array, size_t left, size_t mid, size_t right)
{
    size_t i, j, k;
    size_t left_size = mid - left + 1;
    size_t right_size = right - mid;
    int left_array[left_size], right_array[right_size];

    for (i = 0; i < left_size; i++)
        left_array[i] = array[left + i];
    
    for (i = 0; i < right_size; i++)
        right_array[i] = array[mid + 1 + i];

    i = left;
    for (j = 0, k = 0; j < left_size && k < right_size; i++)
    {
        if (left_array[j] <= right_array[k])
            array[i] = left_array[j], j++;
        else
            array[i] = right_array[k], k++;
    }

    while (j < left_size)
        array[i] = left_array[j], i++, j++;
    while (k < right_size)
        array[i] = right_array[k], i++, k++;
}