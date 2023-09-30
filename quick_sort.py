def quickSort(arr, left=None, right=None):
    left = 0 if left is None else left
    right = len(arr)-1 if right is None else right
    if left < right:
        partitionIndex = partition(arr, left, right)
        quickSort(arr, left, partitionIndex-1)
        quickSort(arr, partitionIndex+1, right)
    return arr

def partition(arr, left, right):
    pivot = left
    index = pivot+1
    i = index
    while  i <= right:
        if arr[i] < arr[pivot]:
            swap(arr, i, index)
            index+=1
        i+=1
    swap(arr,pivot,index-1)
    return index-1

def swap(arr, i, j):
    arr[i], arr[j] = arr[j], arr[i]


if __name__ == '__main__':
    arr = [3, 8, 1, 0, 9]
    ac_arr = sorted(arr)
    print(f'gt arr:{ac_arr}')
    my_arr = quickSort(arr)
    print(f'my arr:{my_arr}')
    