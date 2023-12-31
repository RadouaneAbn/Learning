#include <stdio.h>
#include "sort.h"

void swap(listint_t **list, listint_t *a, listint_t *b)
{
    a->next = b->next;
    b->prev = a->prev;
    if (a->prev)
        a->prev->next = b;
    else
        *list = b;

    a->prev = b;
    if (b->next)
        b->next->prev = a;
    b->next = a;
}

void insertion_sort_list(listint_t **list)
{
    listint_t *current = *list, *tmp;
    int flag;

    if (list == NULL || current == NULL || current->next == NULL)
        return;

    current = *list;
    while (current->next)
    {
        print_list(*list);
        tmp = current->next;
        flag = 1;

        while (tmp->prev && tmp->n < tmp->prev->n)
        {
            swap(list, tmp->prev, tmp);
            flag = 0 /* the list is not sorted */;
        }
        if (flag)
            current = current->next;
    }  
}
