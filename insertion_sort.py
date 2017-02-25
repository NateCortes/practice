import random
import math

def insertion_sort( list ):
    for jay in range(1, len(list)):
        i = jay - 1
        key = list[jay]

        while (i >= 0) & (list[i] > key):
            list[i + 1] = list[i]
            i = i - 1
        list[i + 1] = key

def insertion_sort_part( list, p, r):
    for jay in range(p + 1, r):
        i = jay - 1
        key = list[jay]
        while (i > (p-1)) & (list[i] > key):
            list[i + 1] = list[i]
            i = i - 1
        list[i + 1] = key

def part_test(list, interval):
    i = 0
    while(i < math.floor(len(list) // interval)):
        print("-----------")
        print(list[(interval * (i)):(interval * (i+1))])
        insertion_sort_part(list, (interval * (i)), (interval * (i+1)))
        print(list[(interval * (i)):(interval * (i+1))])
        print("-----------")
        i = i + 1

    insertion_sort_part(list, len(list)-(len(list)%interval), len(list))
    print(list[len(list)-(len(list)%interval):len(list)])

# array = [random.random() for x in range(0, 100001)]
# print(array)
#
# print("------------")
#
# insertion_sort(array)
# print(array)

array_2 = [int(random.random() * 1000) for x in range(0, 27)]

print(array_2)
part_test(array_2, 5)
