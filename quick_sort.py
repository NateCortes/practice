import random

def quicksort(list, p, r):
    if(p < r):
        piv = partition(list, p, r)
        quicksort(list, p, piv -1)
        quicksort(list, piv + 1, r)

def partition(list, p, r):
    x = list[r]
    i = p - 1
    for jay in  range(p, r):
        if list[jay] <= x:
            i = i + 1;
            list[i], list[jay] = list[jay], list[i]
    list[i + 1], list[r] = list[r], list[i + 1]
    return i + 1

# array = [random.random() for x in range(0, 100001)]
# print(array)
#
# print("------------")
#
# quicksort(array, 0, (len(array) - 1))
# print(array)
