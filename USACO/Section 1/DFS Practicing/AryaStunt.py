N, M = [int(i) for i in input().split(" ")]

tents = [int(i) for i in input().split(" ")]

loop = [0 for i in range(N+1)]
connections = [[] for i in range(N+1)]
for i in range(M):
    a, b = input().split(" ")
    connections[a].append(b)
    connections[b].append(a)

killed = 0
damaged = 0
id_attacked = []

