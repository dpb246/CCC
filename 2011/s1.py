import sys
rl = sys.stdin.readline

n = int(rl())
tcount = 0
scount = 0
for line in range(n):
    for w in rl().split():
        for c in w.lower():
            if c == 't':
                tcount += 1
            elif c == 's':
                scount += 1

if tcount > scount:
    print("English")
else:
    print("French")
