'''
ID: dpb2461
TASK: beads
LANG: PYTHON3
'''
import re
from copy import deepcopy
fin = open('beads.in', 'r')
n = int(fin.readline().strip())
beads = list(fin.readline().strip())

def set_beads(c, i, w):
    for j in range(i, w+i+1):
        beads[j] = c
def find():
    save = ' '
    if beads[0] == 'w':
        for i in range(n-1, -1, -1):
            if beads[i] != 'w':
                save = beads[i]
                break
    else:
        save = beads[0]
    return save
def score(neck):
    counts = [0]
    last = neck[0]
    index = 0
    for i in range(len(neck)):
        if neck[i] == last:
            counts[index] += 1
        else:
            index += 1
            last = neck[i]
            counts.append(1)
    if len(counts)<2:
        return counts[0]
    if neck[0] == neck[-1]:
        counts[0] += counts.pop(-1)
    sums = [counts[i]+counts[i+1] for i in range(len(counts)-1)]
    sums.append(counts[0]+counts[-1])
    #print(sums, counts)
    return max(sums)
def place(neck):
    for i in range(len(neck)):
        if neck[i] == 'w':
            temp = deepcopy(neck)
            temp[i] = 'r'
            s1 = place(temp)
            temp[i] = 'b'
            s2 = place(temp)
            return max(s1, s2)
    else:
        return score(neck)
    
def process():
    save = find()
    if save == ' ':
        return n
    
    index_last = 0
    w_count = 0
    for i in range(n):
        if beads[i] == 'w':
            w_count += 1
        elif beads[i] == save:
            set_beads(beads[i], index_last, w_count)
            w_count = 0
            index_last = i
        else:
            w_count = 0
            save = beads[i]
            index_last = i
    return place(beads)
    

with open('beads.out', 'w') as fout:
    fout.write(str(process())+'\n')
    #print(''.join(beads))
