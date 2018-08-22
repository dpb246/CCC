"""
ID: dpb2461
TASK: gift1
LANG: PYTHON3
"""
fin = open("gift1.in", "r")
np = int(fin.readline().strip())
balence = {fin.readline().strip():0 for i in range(np)}

for i in range(np):
    giver = fin.readline().strip()
    amount, numpeople = map(int, fin.readline().strip().split())
    if numpeople == 0: continue #avoid % 0
    for j in range(numpeople):
        balence[fin.readline().strip()] += amount // numpeople
    balence[giver] += amount % numpeople - amount

with open("gift1.out", "w") as fout:
    for key, value in balence.items():
        fout.write(str(key) + " " + str(value) + "\n")
fin.close()
