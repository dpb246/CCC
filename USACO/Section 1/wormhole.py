'''
ID: dpb2461
TASK: wormhole
LANG: PYTHON3
'''
class hole:
    def __init__(self, s):
        self.x, self.y = (int(i) for i in s.split())
fin = open("wormhole.in")
N = int(fin.readline())
holes = [hole(fin.readline()) for i in range(N)] #never change order
ways_to_get_stuck = 0

y_pairs = [None for i in range(N)] #if none then besty is free
for i in range(len(holes)):
    for j in range(len(holes)):
        if holes[j].x > holes[i].x and holes[i].y == holes[j].y:
            if y_pairs[i] == None:
                y_pairs[i] = j
            elif holes[j].x-holes[i].x < holes[y_pairs[i]].x-holes[i].x:
                y_pairs[i] = j
                
def cycle():
    for i in range(N):
        pos = i
        for j in range(N):
            if pos == None: break
            if partner[pos] == None:
                pos = None
                break
            pos = y_pairs[partner[pos]]
        if pos != None: return True
    return False

partner = [None for i in range(N+1)]
def solve():
    i = total = 0
    for i in range(N+1):
        if partner[i] == None:
            break
    if i >= N:
        if cycle(): return 1
        else: return 0

    for j in range(i+1, N):
        if partner[j] == None:
            partner[j] = i
            partner[i] = j
            total += solve()
            partner[i] = partner[j] = None
    return total

with open("wormhole.out", "w+") as fout:
    fout.write(str(solve()) + "\n")
