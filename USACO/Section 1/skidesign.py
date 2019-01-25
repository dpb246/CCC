'''
ID: dpb2461
TASK: skidesign
LANG: PYTHON3
'''
fin = open("skidesign.in")

MAX_N = 1000
MAX_H = 100

N = int(fin.readline())
hills = []
for i in range(N):
    hills.append(int(fin.readline().strip()))

def calc_cost(x, f):
    return (abs(x-f))*(abs(x-f))

min_cost = 100000000000000
for i in range(MAX_H-17+1):
    j = i+17 #i set to bottom of range; j set to top
    cost = 0
    for h in hills:
        if h < i:
            cost += calc_cost(h, i)
        elif h > j:
            cost += calc_cost(h, j)
    if cost < min_cost:
        min_cost = cost
        
with open("skidesign.out", "w+") as fout:
    fout.write(str(min_cost)+"\n")
    
    
