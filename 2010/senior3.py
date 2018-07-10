'''
CCC 2010 Senior 3
Score: 3/15 Wrong Answer
Correct on Subtask:
4
5
'''
from copy import deepcopy
import random
H = int(input())
houses = [int(input()) for i in range(H)]
houses.sort()
k = int(input())

def sortedPos(arr, number):
    arr2 = deepcopy(arr)
    arr2.sort()
    #print(arr2, number)
    if len(arr2) < number:
        return arr2[0]
    return arr2[-number]

if k >= H: #Each has their own fire hydrant
    print(0)
else:
    distances_between = list()
    for i in range(1, len(houses)):
        distances_between.append(houses[i] - houses[i-1])
    #print(distances_between)
    shortest = 1000000
    while len(distances_between)+1 > k:
        #print(distances_between)
        '''
        Find smallest ajacent pair and merge
        '''
        location = 0
        sum = 100000000
        for i in range(0, len(distances_between)-1):
            if sum > distances_between[i] + distances_between[i+1]:
                sum = distances_between[i] + distances_between[i+1]
                location = i
        distances_between.pop(location)
        distances_between[location] = sum
        if len(distances_between) <= k:
            #print("short", int(sortedPos(distances_between, k)/2), "shortest", shortest)
            if (sortedPos(distances_between, k)/2 < shortest) == True:
                shortest = sortedPos(distances_between, k)/2
    print(int(shortest)) #Take largest distance and place hydrant in center
