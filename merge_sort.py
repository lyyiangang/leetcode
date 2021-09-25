# 归并排序
import numpy as np

n_nums = 5
arr = np.random.randint(0, 10, size = n_nums)
print('ori arr:', arr)
gt = sorted(arr)
print('sorted arr:', gt)

def merge_sort(arr):
    if arr is None or len(arr) < 2:
        return arr
    process(arr, 0, len(arr) - 1) 
    return arr

def process(arr, left, right):
    if left == right:
        return
    mid = left + (right - left) // 2
    process(arr, left, mid)
    process(arr, mid + 1, right)
    merge(arr, left, mid, right)

def merge(arr, left, mid, right):
    # print(left, mid, right)
    buff = [0] *  (right - left + 1)
    l, r = left, mid + 1
    i = 0
    while l <= mid and r <= right:
        # ipdb.set_trace() 
        if arr[l] < arr[r]:
            buff[i] = arr[l]
            l+=1
        else:
            buff[i] = arr[r]
            r+=1
        i+=1

    while l <= mid:
        buff[i] = arr[l]
        i+=1
        l+=1

    while r <= right:
        buff[i] = arr[r]
        i+=1
        r+=1 

    i = 0 
    for idx in range(left, right + 1):
        arr[idx] = buff[i]
        i+=1

   

pred = merge_sort(arr)

print('my sort:', pred)

assert np.array_equal(gt, pred)