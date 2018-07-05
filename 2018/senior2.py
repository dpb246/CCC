'''
CCC Senior 2
Score: 15/15
'''
N = int(input())
data = [[int(x) for x in input().split()] for i in range(N)]
'''
Exit when:
    top left is smaller than bottom left
    top left is smaller than top right
    bottom left is smaller than bottom right
    top right is smaller than bottom right
'''
while (data[0][0] < data[N-1][0] and data[0][N-1] < data[N-1][N-1] and data[0][0] < data[0][N-1] and data[N-1][0] < data[N-1][N-1]) == False:
    data = list(zip(*data[::-1]))#Rotates array 90 degrees
for i in data:
    print(" ".join(str(int(x)) for x in i))#Need to fancy print it
