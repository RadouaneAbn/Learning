#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *generate(size_t size)
{
    size_t i;
    int *arr = malloc(sizeof(int) * size);
    srand(time(NULL) * rand());

    for (i = 0; i < size; i++)
        arr[i] = rand();

    return (arr);
}

void swap(int *a, int *b)
{
    int *tmp = a;
    a = b;
    b = tmp;
}

void quick_sort(int *arr, int left, int right)
{
    if (left >= right)
        return;

    int i, fleft = left, fright = right;
    int pivot = arr[right], pidx = right;

    while (left <= right && left < pidx){
        if (arr[left] > pivot)
            swap(&arr[left], &arr[right]), right--;
        left++;
    }
    quick_sort(arr, fleft, left);
    quick_sort(arr, left, fright);
}

void print(int *arr, int size)
{
    int i;
    printf("##################\n");
    for (i = 0; i < size; i++)
        printf("%d\n", arr[i]);
    printf("##################\n\n");
}

int main(int ac, char *av[])
{
    int i, err = 0;
    clock_t start, end;
    double run_time;

    

    if (ac != 2)
    {
        printf("Usage: ./quick <size>\n");
        return (0);
    }

    int size = atoi(av[1]);
    int *arr = generate(size);

    print(arr, size);

    start = clock();
    quick_sort(arr, 0, size - 1);
    end = clock();

    print(arr, size);
    run_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    for (int i = 0; i < size - 1; i++)
        if (arr[i] > arr[i + 1]){
            err = 1;
            break;
        }
    if (err = 1)
        printf("The list is not sorted!!!!!\n");
    else{
        printf("The list is sorted\n");
        printf("\nArray_1 size is: [%d]\n\n", size);
        if (run_time > 60)
            printf("The run time is: %.2f m\n", run_time / 60);
        else if (run_time >= 0.1)
            printf("The run time is: %.2f s\n", run_time);
        else
            printf("The run time is: %f ms\n", run_time / 1000);
    }
    return (0);
}