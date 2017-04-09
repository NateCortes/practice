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
    medians = []
    i = 0
    while(i < math.floor(len(list) // interval)):
        print("-----------")
        print(list[(interval * (i)):(interval * (i+1))])
        insertion_sort_part(list, (interval * (i)), (interval * (i+1)))
        print(list[(interval * (i)):(interval * (i+1))])
        print("-----------")
        medians.append(list[(i * 5) + 2])
        i = i + 1

    insertion_sort_part(list, len(list)-(len(list)%interval), len(list))
    rem_median  = (len(list) % 5)
    if( rem_median % 2 == 1):
        medians.append(list[(len(list)-1) - math.floor(rem_median / 2)])
    elif( rem_median != 0):
        medians.append(list[(len(list)-1) - (rem_median // 2) + 1])

    print(list[len(list)-(len(list)%interval):len(list)])
    print(medians)

    insertion_sort(medians)
    if( len(medians) % 2 == 1):
        x = medians[math.floor(len(medians) / 2)]
    else:
        x = medians[(len(medians) // 2)]
    print(x)

# array = [random.random() for x in range(0, 100001)]
# print(array)
#
# print("------------")
#
# insertion_sort(array)
# print(array)

array_2 = [int(random.random() * 1000) for x in range(0, 23)]

print(array_2)
part_test(array_2, 5)
