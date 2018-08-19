'''
CCC 2017 Senior 3
Score: 15/15
'''
N = int(input())
boards = [int(i) for i in input().split(" ")]

sums = [0 for i in range(4002)]
buckets = [0 for i in range(2002)]

for b in boards:
    buckets[b] += 1

for i in range(1, 2001):
    if buckets[i]:
        for j in range(i, 2001):
            if i == j:
                sums[i+j] += buckets[i] // 2
            elif buckets[j]:
                sums[i + j] += min(buckets[i], buckets[j])
ans1 = 0
ans2 = 0
for i in range(1, 4000):
    if sums[i] > ans1:
        ans1 = sums[i]
        ans2 = 1
    elif sums[i] == ans1:
        ans2 += 1

print(ans1, ans2)
