'''
ID: dpb2461
TASK: milk2
LANG: PYTHON3
'''
fin = open('milk2.in')
n = int(fin.readline())
times = [0 for i in range(1000001)]
start = 1000000
end = 0
for i in range(n):
    s, e = map(int, fin.readline().strip().split())
    for j in range(s, e):
        times[j] = 1
    if s < start:
        start = s
    if e > end:
        end = e
max_count = {0:0, 1:0}
last = times[start]
count = 0
for i in range(start, end+1):
    if times[i] == last:
        count += 1
    else:
        if count > max_count[last]:
            max_count[last] = count
        last = times[i]
        count = 1
with open('milk2.out', 'w') as fout:
    fout.write(str(max_count[1]) + " " + str(max_count[0]) + "\n")

fin.close()
