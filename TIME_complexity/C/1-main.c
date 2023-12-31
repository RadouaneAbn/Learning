#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
    listint_t *list;
    listint_t *node;
    int *tmp;

    list = NULL;
    while (size--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        tmp = (int *)&node->n;
        *tmp = array[size];
        node->next = list;
        node->prev = NULL;
        list = node;
        if (list->next)
            list->next->prev = list;
    }
    return (list);
}

int *generate(size_t size)
{
    size_t i;
    int *arr = malloc(sizeof(int) * size);

    srand(time(NULL) * rand());

    for (i = 0; i < size; i++)
        arr[i] = rand() % 100;

    return (arr);
}

int main(void)
{
    listint_t *list, *current;
    /*int arr[] = {89, 34, 37, 9, 1, 88, 81, 21, 97, 31};
    size_t n = sizeof(array) / sizeof(array[0]);*/
    size_t n = 0;
    int *arr = generate(n), flag = 0;

    list = create_listint(arr, n);
    if (!list)
        return (1);
    print_list(list);
    printf("\n");
    insertion_sort_list(&list);
    printf("\n");
    print_list(list);

    current = list;
    while (current->next)
    {
        if (current->n > current->next->n)
            flag = 1;
        current = current->next;
    }

    if (flag == 1)
        printf("FAILURE !!!!!\n");
    else
        printf("SUCCESS !!!\n");

    return (0);
}