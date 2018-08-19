'''
CCC 2016 Senior 2
Score: 15/15
'''

t = int(input())
n = int(input())
d = [int(i) for i in input().split(" ")]
p = [int(i) for i in input().split(" ")]
total = 0

d = sorted(d)
if t == 1:
    p = sorted(p)
else:
    p = sorted(p)[::-1]
for i in range(n):
    total += max(p[i], d[i])
print(total)
