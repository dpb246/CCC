'''
ECCO 2018 round 2 question 3
4/10 Timeout Error
'''
import time
factorial = 1
last_n = 1
K, M = [int(i) for i in input().split()]
bigNumber = K**M
multiplier = 1
while True:
    if factorial%bigNumber == 0:
        print(last_n)
        break
    else:
        temp = factorial*(last_n+1)
        factorial = temp
        last_n += 1
