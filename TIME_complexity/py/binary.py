from time import time

def find_idx(arr, target):
    left, right = 0, len(arr)

    start = time()

    while (left < right):
        mid = int((left + right) / 2)

        if arr[mid] == target:
            break
        elif arr[mid] < target:
            left = mid
        else:
            right = mid

    end = time()
    run = (end - start) * 1000

    return [mid, run]

target = -23
mil_arr = [ n for n in range(-1000000, 1000000) ]

idx, run = find_idx(mil_arr, target)
print(f"The index of {target} is <{idx}>")
print(f"The run time: {run:.5f} ms")

A_run = 0
all_start = time()
for n in range(0, 100):
    idx, run = find_idx(mil_arr, target)
    A_run += run
all_end = time()

average = A_run / 100
all_A = (all_end - all_start) * 1000

print(f"The average run_time is: [{average:.5f} ms] in [{all_A:.5f} s]")
