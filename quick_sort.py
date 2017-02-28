import random

def quicksort(list, p, r):
    if(p < r):
        print("--start--")
        print("p :", p,"r: ", r)
        print("partition")
        piv = partition(list, p, r)
        print("lhs")
        quicksort(list, p, piv -1)
        print("rhs")
        quicksort(list, piv + 1, r)

def partition(list, p, r):
    print(p, r)
    x = list[r]
    i = p - 1
    for jay in  range(p, r):
        print(list[jay], " <= ", x, "?")
        if list[jay] <= x:
            i = i + 1;
            list[i], list[jay] = list[jay], list[i]
            print(list)
    list[i + 1], list[r] = list[r], list[i + 1]
    print(list)

    return i + 1

def part_mod(list, p, r, x):
    i = p - 1
    for jay in  range(p, r):
        if list[jay] <= x:
            i = i + 1;
            list[i], list[jay] = list[jay], list[i]
    list[i + 1], list[r] = list[r], list[i + 1]
    return i + 1



# array = [random.random() for x in range(0, 101)]
# print(array)
#
# print("------------")
#
# quicksort(array, 0, (len(array) - 1))
# print(array)

list = [5, 4, 3, 2, 1]
quicksort(list, 0, len(list) -1)
# list = [10-i for i in range(0, 11)]
# quicksort(list, 0, (len(list) - 1))
# print(list)
