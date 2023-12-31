#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *generate(size_t size);
void merge(int *arr, size_t left, size_t mid, size_t right);
void sort_merge(int *arr, size_t left, size_t right);
void init_merge(size_t size);
unsigned long *sort_bubble(int *arr, size_t size);
void init_bubble(size_t size);
unsigned long *sort_insertion(int *arr, size_t size);
void init_insertion(size_t size);
void init_selection(size_t size);
unsigned long *sort_selection(int *arr, size_t size);
void init_quick1(size_t size);
void sort_quick1(int *arr, size_t left, size_t right);


size_t size;

int main(int ac, char *av[])
{
    const char *title = "Alert";
    const char *message = "Done sorting!!";
    int choise;
    if (ac == 1){
    printf("Whats the size of the array: ");
    scanf("%ld", &size);
    printf("What  sorting algorithm you want to use:\n[1]: Merge         [2]: Bubble\n[3]: insertion     [4]: selection\n[5]: quick (Lomuto)\n\n");
    scanf("%d", &choise);
    }
    else
        choise = atoi(av[1]), size = atoi(av[2]);


    switch (choise){
        case 1:
            init_merge(size);
            break;
        case 2:
            init_bubble(size);
            break;
        case 3:
            init_insertion(size);
            break;
        case 4:
            init_selection(size);
            break;
        case 5:
            init_quick1(size);
            break;
        default:
            printf("Unkown choise\n");
            break;
    }

    return (0);
}

void print(int *arr)
{
    int i;
    printf("{");
    for (i = 0; i < size - 1; i++)
        printf("%d, ", arr[i]);
    printf("%d", arr[i]);
    printf("}\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_quick1(int *arr, size_t left, size_t right)
{
    if (left < right)
    {
        size_t i = left, j = left;
        int pivot = arr[right];

        while (j < right){
            if (arr[j] <= pivot){
                swap(&arr[i], &arr[j]);
                i++;
            }
        j++;
        }

        swap(&arr[i], &arr[right]);
        if (i > 0)
            sort_quick1(arr, left, i - 1);
        sort_quick1(arr, i + 1, right);
    }
}

void copyArray(int source[], int destination[], size_t size) {
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
    printf("Array copied\n");
}



int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) { 
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void sort_quick_t(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        sort_quick_t(arr, low, pi - 1);
        sort_quick_t(arr, pi + 1, high);
    }
}

void init_quick1(size_t size)
{
    int i, err = 0, err_2 = 0;
    int *arr = generate(size);
    int arr2[10] = {4, 5, 7, 6, 1, 8, 3, 9, 0, 2};
    // int *arr_2 = malloc(sizeof(int) * size);
    clock_t start, end, start_2, end_2;
    double run_time, run_time_2;

    // copyArray(arr, arr_2, size);
    start = clock();
    sort_quick1(arr, 0, size - 1);
    end = clock();

    // start = clock();
    // sort_quick_t(arr, 0, size - 1);
    // end = clock();


    for (i = 0; i < size - 1; i++)
        if (arr[i] > arr[i + 1]){
            err = 1;
            break;
        }

    // for (i = 0; i < size - 1; i++)
    //     if (arr_2[i] > arr_2[i + 1]){
    //         err_2 = 1;
    //         break;
    //     }
    printf("\n");

    run_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    // run_time_2 = ((double) (end_2 - start_2)) / CLOCKS_PER_SEC;

    printf("The sorting method: quick (Lomuto) sort\n\n");

    if (err == 1)
        printf("Somthing went wrong!!\n");
    else
    {
        printf("Sorting worked!!\n");
        printf("\nArray_1 size is: [%ld]\n\n", size);
        if (run_time > 60)
            printf("The run time is: %.2f m\n", run_time / 60);
        else if (run_time >= 0.1)
            printf("The run time is: %.2f s\n", run_time);
        else
            printf("The run time is: %f ms\n", run_time / 1000);
    }

    // if (err_2 == 1)
    //     printf("Somthing went wrong!!\n");
    // else
    // {
    //     printf("Sorting worked!!\n");
    //     printf("\nArray size is: [%ld]\n\n", size);
    //     if (run_time_2 > 60)
    //         printf("The run time is: %.2f m\n", run_time_2 / 60);
    //     else if (run_time_2 >= 0.1)
    //         printf("The run time is: %.2f s\n", run_time_2);
    //     else
    //         printf("The run time is: %f ms\n", run_time_2 / 1000);
    // }

    free(arr);
    // free(arr_2);
}

void init_selection(size_t size)
{
    int i, count = 0, T_count = 0, err = 0;
    int *arr = generate(size);
    clock_t start, end;
    double run_time;
    unsigned long *sp;

    start = clock();
    sp = sort_selection(arr, size);
    end = clock();

    for (i = 0; i < size - 1; i++)
        if (arr[i] > arr[i + 1])
            err = 1;

    run_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("The sorting method: selection sort\n\n");

    if (err == 1)
        printf("Somthing went wrong!!\n");
    else
    {
        printf("Sorting worked!!\n");
        printf("\nArray size is: [%ld]\n\n", size);
        if (run_time > 60)
            printf("The run time is: %.2f m\n", run_time / 60);
        else if (run_time >= 0.1)
            printf("The run time is: %.2f s\n", run_time);
        else
            printf("The run time is: %f ms\n", run_time / 1000);
    }

    printf("loops: %lu\nTotal loops: %lu\n", sp[0], sp[1]);
    free(arr);
}

unsigned long *sort_selection(int *arr, size_t size)
{
    size_t i, j;
    int min, idx;
    unsigned long *sp = malloc(sizeof(unsigned long) * 2);
    unsigned long count = 0, T_count = 0;

    for (i = 0; i < size - 1; i++)
    {
        count++;
        min = arr[i], idx = i;
        for (j = i + 1; j < size; j++)
        {
            T_count++;
            if (arr[j] < min)
                min = arr[j], idx = j;
        }

        arr[idx] = arr[i];
        arr[i] = min;
    }

    sp[0] = count;
    sp[1] = T_count;
    return (sp);
}

int *generate(size_t size)
{
    size_t i;
    int *arr = malloc(sizeof(int) * size);

    srand(time(NULL) * rand());

    for (i = 0; i < size; i++)
        arr[i] = rand();

    return (arr);
}

void merge(int *arr, size_t left, size_t mid, size_t right)
{
    size_t i, j, k;
    size_t L = mid - left + 1, R = right - mid;
    int tmp_l[L], tmp_r[R];

    for (i = 0; i < L; i++)
        tmp_l[i] = arr[left + i];

    for (i = 0; i < R; i++)
        tmp_r[i] = arr[mid + 1 + i];

    i = left;
    for (j = 0, k = 0; j < L && k < R; i++)
    {
        if (tmp_l[j] <= tmp_r[k])
            arr[i] = tmp_l[j], j++;
        else
            arr[i] = tmp_r[k], k++;
    }

    while (j < L)
        arr[i] = tmp_l[j], i++, j++;
    while (k < R)
        arr[i] = tmp_r[k], i++, k++;
}

void sort_merge(int *arr, size_t left, size_t right)
{
    size_t mid = left + (right - left) / 2, i = 0;
    
    if (left < right)
    {

        sort_merge(arr, left, mid);
        sort_merge(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void init_merge(size_t size)
{
    int i, err = 0;
    // char *name = "array_m.txt", *new_name = "sorted_array_m.txt";
    // FILE *fp;
    int *arr = generate(size);
    clock_t start, end;
    double run_time;

    // fp = fopen(name, "w");
    // for (i = 0; i < size; i++)
    //     fprintf(fp, "%d\n", arr[i]);
    // fclose(fp);

    start = clock();
    sort_merge(arr, 0, size - 1);
    end = clock();

    // fp = fopen(new_name, "w");
    // for (i = 0; i < size; i++)
    //     fprintf(fp, "%d\n", arr[i]);
    // fclose(fp);

    for (i = 0; i < size - 1; i++)
        if (arr[i] > arr[i + 1])
            err = 1;

    run_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("The sorting method: merge sort\n\n");
    if (err == 1)
        printf("Somthing went wrong!!\n");
    else
    {
        printf("Sorting worked!!\n");
        printf("\nArray size is: [%ld]\n\n", size);
        if (run_time >= 0.1)
            printf("The run time is: %.2f s\n", run_time);
        else
            printf("The run time is: %f ms\n", run_time / 1000);
    }

    free(arr);
}

unsigned long *sort_bubble(int *arr, size_t size)
{
    size_t i;
    unsigned long *sp = malloc(sizeof(unsigned long) * 2);
    unsigned long count = 0, T_count = 0;
    
    int T = 1, tmp;

    while (T)
    {
        count++;
        T = 0;
        for (i = 0; i < size - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                T_count++;
                T = 1;
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = arr[i];
            }
        }
    }
    sp[0] = count;
    sp[1] = T_count;
    return (sp);
}

void init_bubble(size_t size)
{
    int i, count = 0, T_count = 0, err = 0;
    int *arr = generate(size);
    FILE *fp;
    clock_t start, end;
    double run_time;
    unsigned long *sp;

    start = clock();
    sp = sort_bubble(arr, size);
    end = clock();

    for (i = 0; i < size - 1; i++)
        if (arr[i] > arr[i + 1])
            err = 1;

    run_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("The sorting method: Bubble sort\n\n");

    if (err == 1)
        printf("Somthing went wrong!!\n");
    else
    {
        printf("Sorting worked!!\n");
        printf("\nArray size is: [%ld]\n\n", size);
        if (run_time > 60)
            printf("The run time is: %.2f m\n", run_time / 60);
        else if (run_time >= 0.1)
            printf("The run time is: %.2f s\n", run_time);
        else
            printf("The run time is: %f ms\n", run_time / 1000);
    }

    printf("loops: %lu\nTotal loops: %lu\n", sp[0], sp[1]);
    free(arr);
}

unsigned long *sort_insertion(int *arr, size_t size)
{
    int tmp, idx = 1, i, j, T = 1;
    unsigned long *sp = malloc(sizeof(unsigned long) * 2);
    unsigned long loop = 0, T_loop = 0;

    while (T)
    {
        T = 0;
        i = idx;
        while (i < size && arr[i] > arr[i - 1])
            i++, T_loop++;

        idx = i + 1;
        while (i < size && arr[i] < arr[i - 1])
        {
            tmp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = tmp;
            T = 1; i--, T_loop++;
        }
        loop++;
    }
    sp[0] = loop;
    sp[1] = T_loop;

    return (sp);
}

void init_insertion(size_t size)
{
    int i, count = 0, T_count = 0, err = 0;
    int *arr = generate(size);
    // FILE *fp;
    clock_t start, end;
    double run_time;
    unsigned long *sp;

    start = clock();
    sp = sort_insertion(arr, size);
    end = clock();

    for (i = 0; i < size - 1; i++)
        if (arr[i] > arr[i + 1])
        {
            err = 1;
            break;
        }

    run_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("The sorting method: insertion sort\n\n");

    if (err == 1)
        printf("Somthing went wrong!!\n");
    else
    {
        printf("Sorting worked!!\n");
        printf("\nArray size is: [%ld]\n\n", size);
        if (run_time > 60)
            printf("The run time is: %.2f m\n", run_time / 60);
        else if (run_time >= 0.1)
            printf("The run time is: %.2f s\n", run_time);
        else
            printf("The run time is: %f ms\n", run_time / 1000);
    }

    printf("loops: %lu\nTotal loops: %lu\n", sp[0], sp[1]);
    free(arr);
}
