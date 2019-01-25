N = int(input())
connections = [[] for i in range(N+1)]
for i in range(N-1):
    u, v = [int(i) for i in input().split()]
    connections[u].append(v)
    connections[v].append(u)

visited = [0 for i in range(N+1)]

def dfs(s, length):
    visited[s] = length
    for i in connections[s]:
        if visited[i] == 0:
            dfs(i, length+1)
dfs(1, 1)
Q = int(input())
minNum = 0
minDis = 10000000
while Q > 0:
    Q -= 1
    g = int(input())
    if minDis>visited[g]:
        minDis = visited[g]
        minNum = g
    elif minDis == visited[g]:
        minNum = min(minNum, g)
 
print(minNum)
