'''
CCC Senior 4
Score: 9/15
'''
#TODO: Make faster by changing algorithm
import math
saved = {2: 1}
def balance(N):
    count = 0
    if N in saved.keys():
        return saved[N]
    count += math.ceil((2*N)/3)
    n = math.floor(N/3)
    for i in range(2, n+1):
        count += balance(math.floor(N/i))
    saved[N] = count
    return count

print(balance(int(input())))
