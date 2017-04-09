import random

def sort_merge(A):
    copy = A[:]
    merge_sort(copy, A, 0, len(A))

def merge_sort(copy_list, result, start, end):
    if end - start < 2:
        return
    if end - start == 2:
        if result[start] > result[start+1]:
            result[start], result[start+1] = result[start+1], result[start]
        return

    mid = (start + end) // 2
    merge_sort(result, copy_list, start, mid)
    merge_sort(result, copy_list, mid, end)

    i = start
    j = mid
    idx = start
    while idx < end:
        if j >= end or (i<mid and copy_list[i] < copy_list[j]):
            result[idx] = copy_list[i]
            i=i+1
        else:
            result[idx] = copy_list[j]
            j=j+1
        idx=idx+1

list = [random.random() for x in range(0, 100001)]
print(list)

print("--------------")

sort_merge(list)
print(list)
