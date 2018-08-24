
def getLine():
    d, w = input().split()
    return [int(d), float(w)]
for run in range(10):
    n = int(input())
    wieghts = [getLine() for i in range(n)]
    wieghts = sorted(wieghts, reverse=True)
    total = 0.0
    for i in range(wieghts[0][0], 0, -1):#count down from longest date
        if i > (wieghts[0][0]): continue
        best = 0.0
        index = -1
        for l in range(len(wieghts)):
            if wieghts[l][0] < i:
                break
            if wieghts[l][1] > best:
                best = wieghts[l][1]
                index = l
        if index != -1:
            temp = wieghts.pop(index)
            total += temp[1]
    print('{:.4f}'.format(total))

