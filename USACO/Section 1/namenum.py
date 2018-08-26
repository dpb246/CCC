"""
ID: dpb2461
TASK: namenum
LANG: PYTHON3
"""
valid_name_file = open("dict.txt")
valid_names = [line.strip() for line in valid_name_file]
letter = {'A':2, 'B':2, 'C':2, 'D':3, 'E':3, 'F':3, 'G':4, 'H':4, 'I':4, 'J':5, 'K':5, 'L':5, 'M':6, 'N':6, 'O':6, 'P':7, 'R':7, 'S':7, 'T':8, 'U':8, 'V':8, 'W':9, 'X':9, 'Y':9, 'Z':0, 'Q':0}
output = []
target = open('namenum.in').readline().strip()
for name in valid_names:
    s = ""
    for l in name:
        s += str(letter[l])
    if target == s:
        output.append(name)
with open('namenum.out', 'w') as fout:
    if len(output) == 0:
        fout.write("NONE\n")
    else:
        for name in output:
            fout.write(name + "\n")
