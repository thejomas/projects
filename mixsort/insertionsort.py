import numpy as np
import math
import sys
import random
random.seed(1)

def InsertionSort(my_list):
    # for every element in our array
    for index in range(1, len(my_list)):
        current = my_list[index]
        position = index

        while position > 0 and my_list[position-1] > current:
            my_list[position] = my_list[position-1]
            position -= 1

        my_list[position] = current

    return my_list

arr = [0]*100000
for x in arr:
    x = random.randint(0, 1000)
sorted_arr = InsertionSort(arr)
print(all(sorted_arr[i] <= sorted_arr[i+1] for i in range(len(sorted_arr)-1)))
