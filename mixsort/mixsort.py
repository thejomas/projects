#Tager ca 100x så lang tid som insertionsort kek (kan det være pga cache misses?)
import numpy as np
import math
import sys
import random
random.seed(1)
def InsertionSort(arr):
    ptr = 0
    for i in range(1, len(arr)):
        key = arr[i]
        index = BinarySearch(arr[:i], key)
        del arr[i]
        arr.insert(index, key)
    return arr

def BinarySearch(arr, n):
    low = 0
    high = len(arr) - 1
    mid = 0
    while(low <= high):
        mid = high+low//2
        if (arr[mid] > n):
            high = mid - 1
        elif (arr[mid] < n):
            low = mid + 1
        else:
            break

    if (arr[mid] < n): mid += 1
    return mid

arr = [0]*10000
for x in arr:
    x = random.randint(0, 1000)
sorted_arr = InsertionSort(arr)
print(all(sorted_arr[i] <= sorted_arr[i+1] for i in range(len(sorted_arr)-1)))
