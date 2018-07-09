'''
CCC 2018 Senior 4
Score: 9/15 Timeout Error
This is based on https://dmoj.ca/problem/ccc18s4 ideas but still fails to run in time.  This was then converted to the c++ code.
'''

import time
from math import sqrt

n = int(input())
saved = {1:1, 2:1}
def f(n):
    #print(n)
    if n in saved:
        return saved[n]
    output = (n - n//3)
    root = sqrt(n)
    for j in range(3, int(root+1)):
        output += (n//j - n//(j+1)) * f(j)
    for j in range(2, n+1):
        temp = n//j
        if temp <= root: break
        output += f(temp)
    saved[n] = output
    return output

start_time = time.clock()
print(f(n))
print("--- %s seconds ---" % (time.clock() - start_time))
