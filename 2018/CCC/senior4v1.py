'''
CCC 2018 Senior 4
Score: 9/15 Timeout Error
'''
import math
saved = {2: 1}
def balance(N):
    if N in saved:
        return saved[N]
    count = 0
    count += math.ceil((N*2)/3)
    for i in range(2, N//3+1):
        count += balance(N//i)
    saved[N] = count
    return count

i = int(input())
print(balance(i))
