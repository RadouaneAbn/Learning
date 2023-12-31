from time import time
import random

def sort_list(array):
    arr = array.copy()
    size = len(arr)
    T = True

    start = time()
    count = 0
    while T:
        i = 0
        count += 1
        T = False
        while i < size - 1:
            if arr[i] > arr[i + 1]:
                T = True
                tmp = arr[i]
                arr[i] = arr[i + 1]
                arr[i + 1] = tmp
            i += 1
    end = time()
    run_time = (end - start) * 1000
    print(f"loops: [{count}]")
    print(f"size of the array: [{size}]")
    return run_time


arr = [random.randint(1, 100000) for _ in range(10000)]

run_time = sort_list(arr)
SEC = "ms"
if run_time > 1000:
    run_time = run_time / 1000
    SEC = "s"
print(f"The normal sorting run time is: {run_time:.5f} {SEC}")
# A_run = 0
# all_start = time()
# for n in range(0, 100):
#     run_time = sort_list(arr)
#     A_run += run_time

# all_end = time()
# average = A_run / 100
# all_A = (all_end - all_start) * 1000

# print(f"The average run time is:        {all_A:.5f} ms")



