import random
from quick_sort import *

def smallest(Array, n):
    small = Array[1]; sm_index = 1
    for jay in range(2, n):
        if Array[jay] <= small:
            small = Array[jay]
            sm_index = jay

    print(small)
    return sm_index


list = [random.random() for x in range(0, 25)]
print(list)

print("--------")
print(smallest(list, len(list)))
print("--------")

# quicksort(list, 0, (len(list) - 1))
# print(list)
