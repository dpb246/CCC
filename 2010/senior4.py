'''
CCC 2010 Senior 4
Score: 12/15 Wrong Answer Subtask 1
'''
from copy import deepcopy
N = int(input())
class Pen:
    def __init__(self):
        self.costs = {}
    def add(self, corner, cost):
        self.costs[str(corner)] = cost
    def findMin(self):
        minVal = 50000
        minKey = ""
        for key, val in self.costs.items():
            if val < minVal:
                minKey = key
                minVal = val
            if val == minVal:
                pass
        return minKey
def merge(pen1, pen2):
    output = Pen()
    for i in pen1.costs.keys():
        output.add(i, pen1.costs[i])
    for i in pen2.costs.keys():
        output.add(i, pen2.costs[i])
    return output
pens = list()
for i in range(N):
    row = [int(i) for i in input().split()]
    corners = row[1:(1+row[0])]
    pairs = list()
    for j in range(1, len(corners)):
        temp = [corners[j-1], corners[j]]
        temp.sort()
        pairs.append(temp)
    temp = [corners[0], corners[-1]]
    temp.sort()
    pairs.append(temp)
    pens.append(Pen())
    for j, pair in enumerate(pairs):
        pens[-1].add(pair, row[j+row[0]+1])
if N==1:
    print(0)
else:
    total_cost = 0
    outside_broke = False
    while True:
        if outside_broke and len(pens) == 0: break
        if not outside_broke and len(pens) == 1: break
        active_pen = pens.pop() #Take a pen
        min_edge = active_pen.findMin()
        total_cost += active_pen.costs.pop(min_edge)
        shared_with_pen = Pen()
        for i, pen in enumerate(pens):
            if min_edge in pen.costs:
                shared_with_pen = deepcopy(pen)
                pens.pop(i)
                break
        else:
            print("breaking")
            outside_broke = True
            continue
        shared_with_pen.costs.pop(str(min_edge))
        pens.append(merge(active_pen, shared_with_pen))
    print(len(pens))
    print(total_cost)
