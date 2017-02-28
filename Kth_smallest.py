def k_smallest(list, l, r, k):
    if((k > 0) & (k <= r - l + 1)):
        pos = partition(list, l , r)

        if(pos-l == k - 1):
            return list[pos]

        if(pos - l > k - 1):
            return k_smallest(list, l, pos-1,k)

        return k_smallest(list, pos+1, r, k-pos+l-1)

    return "doesn't exist"

def partition(list, p, r):
    x = list[r]
    i = p - 1
    for jay in range(p, r):
        if(list[jay] <= x):
            i = i + 1
            list[i], list[jay] = list[jay], list[i]
    list[i + 1], list[r]
    return i + 1




array = [12, 3, 5, 7, 4, 19, 26]

print(k_smallest(array, 0, len(array) - 1, 0))
print(k_smallest(array, 0, len(array) - 1, len(array) - 1))
print(k_smallest(array, 0, len(array) - 1, len(array)))
print(k_smallest(array, 0, len(array) - 1, len(array) + 1))
