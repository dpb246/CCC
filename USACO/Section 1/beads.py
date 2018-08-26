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
    maxscore = 0
    for i in range(n):
        count = 0
        while beads[(i+count)%n] == 'w':
            count += 1
            if (i+count)%n == i:
                break
        starting = beads[(i+count)%n]
        for j in range((i+count), n*2):
            if beads[j%n] == starting or beads[j%n] == 'w':
                count += 1
            else:
                break
        for j in range(i+count, n*2):
            if beads[j%n] == starting:
                break
            else:
                count += 1
        if count > n: count = n
        if count > maxscore:
            maxscore = count
    return maxscore

with open('beads.out', 'w') as fout:
    #print(process())
    fout.write(str(process())+'\n')
