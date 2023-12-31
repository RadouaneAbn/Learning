from time import time

def find_idx(arr, target):
    size = len(arr)
    i = 0

    start = time()
    while i < size:
        if arr[i] == target:
            break
        i += 1
    end = time()
    run = (end - start) * 1000

    return [i, run]

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
all_A = (all_end - all_start)

print(f"The average run_time is: [{average:.2f} ms] in [{all_A:.2f} s]")
