'''
CCC 2016 Senior 4
3/15 TLE
'''
from copy import deepcopy
n = int(input())
rice = [int(i) for i in input().split(" ")]
can_combine = [[-1 for j in range(n+1)] for i in range(n+1)]
def combine(rice):
    if len(rice) == 1: return 1
    for i in range(len(rice)-1):
        if rice[i] == rice[i+1]:
            new = deepcopy(rice)
            new[i] += new.pop(i+1)
            if combine(new):
                return 1
        if i+2 < len(rice):
            if rice[i] == rice[i+2]:
                new = deepcopy(rice)
                new[i] += new.pop(i+1) + new.pop(i+1)
                if combine(new):
                    return 1
    return 0
maximum = 0
for i in range(n):
    for j in range(i+1, n+1):
        if can_combine[i][j] == 1:
            t = sum(rice[i:j])
            if t > maximum:
                maximum = t
        elif can_combine[i][j] == -1:
            temp = combine(rice[i:j])
            can_combine[i][j] = temp
            if temp:
                t = sum(rice[i:j])
                if t > maximum:
                    maximum = t
print(maximum)

'''
3/15 recursion style

from copy import deepcopy
n = int(input())
balls = [int(i) for i in input().split(" ")]

def findmax(a):
    m = 0
    for v in a:
        if v > m:
            m = v
    return m

def biggest(rice):
    if len(rice) == 1:
        return rice[0]
    elif len(rice) == 2:
        if rice[0] == rice[1]:
            return rice[0]*2
        else:
            return max(rice[0], rice[1])
    maximum = 0
    for i in range(len(rice)-1):
        if rice[i] == rice[i+1]:
            new = deepcopy(rice)
            new[i] += new.pop(i+1)
            temp = biggest(new)
            if temp > maximum:
                maximum = temp
        if i+2 < len(rice):
            if rice[i] == rice[i+2]:
                new = deepcopy(rice)
                new[i] += new.pop(i+1) + new.pop(i+1)
                temp = biggest(new)
                if temp > maximum:
                    maximum = temp
    return max(maximum, findmax(rice))

print(biggest(balls))
'''
