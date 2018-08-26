'''
ID: dpb2461
TASK: transform
LANG: PYTHON3
'''
f = open('transform.in')
n = int(f.readline())
init = [list(f.readline().strip()) for i in range(n)]
finished = [list(f.readline().strip()) for i in range(n)]
def compare(array1, array2):
    for i in range(len(array1)):
        for j in range(len(array1)):
            if array1[i][j] != array2[i][j]:
                return False
    return True
def rotate(array1, array2):
    temp = array1
    for i in range(1, 6):
        temp = list(zip(*temp[::-1]))
        if compare(temp, array2):
            if i == 4: return 6
            return i
    return 0
def process(array1, array2):
    value = rotate(array1, array2)
    if value:
        return value

    temp = [[' ' for i in range(n)] for i in range(n)]
    for i in range(n//2):
        for j in range(n):
            temp[j][i] = array1[j][-i-1]
            temp[j][-i-1] = array1[j][i]
    if n%2 == 1:
        for j in range(n):
            temp[j][n//2] = array1[j][n//2]
    if compare(temp, array2):
        return 4
    value = rotate(temp, array2)
    if value:
        return 5
    return 7
with open('transform.out', 'w') as fout:
    fout.write(str(process(init, finished))+"\n")
f.close()
