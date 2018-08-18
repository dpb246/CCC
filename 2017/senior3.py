
N = int(input())
boards = [int(i) for i in input().split(" ")]

sums = [0 for i in range(20)]
buckets = [0 for i in range(20)]

for b in boards:
    buckets[b] += 1
print(buckets)
for i in range(1, 21):
    if buckets[i]:
        for j in range(i, 20):
            if i == j: sums[i+j] += buckets[i] >> 1
            elif buckets[j]:
                sums[i + j] += min(buckets[i], buckets[j])
            print(sums)
ans1 = 0
ans2 = 0

for i in range(1, 20):
    if sums[i] > ans1:
        ans1 = sums[i]
        ans2 = 1
    elif sums[i] == ans1:
        ans2 += 1

print(ans1, ans2)
