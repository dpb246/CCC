"""
ID: dpb2461
LANG: PYTHON3
TASK: test
"""
fin = open("test.in", "r")
fout = open("test.out", "w")
x, y = map(int, fin.readline().split())
fout.write(str(x+y) + "\n")
fout.close()
