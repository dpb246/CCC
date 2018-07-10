'''
CCC 2010 Senior 1
Score: 15/15
'''
N = int(input())
if N != 0:
    calculated = list()
    for i in range(N):
        Name, Ram, CPU, Disk = [i for i in input().split()]
        Ram = int(Ram)
        CPU = int(CPU)
        Disk = int(Disk)
        score = 2*Ram + 3*CPU + Disk
        calculated.append([score, Name])

    calculated.sort()
    if len(calculated) == 1:
        print(calculated[0][1])
    else:
        final = [calculated[-1][1]]
        next = -2
        while calculated[next][0] == calculated[-1][0]:
            final.append(calculated[next][1])
            next -= 1
            if next < -1*len(calculated):
                break
        final.sort()
        if len(final) >= 2:
            print(final[0])
            print(final[1])
        else:
            print(final[0])
            final = [calculated[next][1]]
            second = calculated[next][0]
            while calculated[next][0] == second:
                final.append(calculated[next][1])
                next -= 1
                if next < -1*len(calculated):
                    break
            final.sort()
            print(final[0])
