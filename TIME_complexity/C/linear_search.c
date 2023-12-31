#include <time.h>
#include <stdio.h>

int find_idx(int *arr, int target, size_t size);

int main(void)
{
    int target = 81, idx;
    int arr[100] = {
    -99, -97, -92, -91, -87, -81, -78, -77, -74, -72,
    -66, -64, -60, -57, -55, -54, -53, -52, -50, -49,
    -45, -44, -43, -41, -40, -37, -36, -33, -32, -29,
    -27, -25, -24, -23, -22, -20, -18, -15, -13,
    -12, -11, -10, -8, -6, -4, -3, -2, -1, 0,
    1, 3, 4, 6, 7, 10, 12, 13, 14, 15,
    17, 18, 19, 20, 21, 23, 24, 25, 27, 28,
    29, 30, 31, 33, 35, 37, 38, 41, 43, 46,
    47, 49, 51, 52, 55, 58, 59, 61, 64, 65,
    67, 70, 74, 76, 78, 81, 83, 86, 88, 95, 99};
    
    clock_t start, end;
    double run_time;
    size_t size = sizeof(arr) / sizeof(int);


    start = clock();
    idx = find_idx(arr, target, size);
    end = clock();

    run_time = ((double)((end - start)) / CLOCKS_PER_SEC) * 1000;

    if (idx)
        printf("The index of [%d] is: <%d>\n", target, idx);
    else
        printf("The target is not in the list\n");

    printf("The run time is: %f ms\n", run_time);
    return (0);
}

int find_idx(int *arr, int target, size_t size)
{
    size_t i;

    for (i = 0; i < size; i++)
    {
        if (arr[i] == target)
            return (i);
    }
}