"""
ID: dpb2461
LANG: PYTHON3
PROG: ride
"""
def score(word):
    product = 1
    for w in word:
        product *= ord(w) - ord('A') + 1
    return product
fin = open("ride.in", "r")
fout = open("ride.out", "w")
comet = fin.readline().strip()
group = fin.readline().strip()
if score(comet)%47 == score(group)%47:
    fout.write("GO" + "\n")
else:
    fout.write("STAY" + "\n")
fout.close()
