'''
CCC 2018 Senior 3
Score: 15/15
'''
N, M = (int(x) for x in input().split(" "))
board = list()
moves = [[0 for i in range(M)] for i in range(N)] #stores how long it takes to get to a given location
search = list() #Places that need to be expanded
for i in range(N):
    board.append(list(input().rstrip()))
    for j in range(M):
        if board[i][j] == "S":
            search.append([i, j]) #Seed search array for while loop
for i in range(N): #Find all spots a camera can see and mark with a 'x'
    for j in range(M):
        if board[i][j] == "C":
            for k in range(i, 0, -1):
                if board[k][j] == ".":
                    board[k][j] = "x"
                if board[k][j] == "S":
                    del search[0]
                if board[k][j] == "W":
                    break
            for k in range(j, 0, -1):
                if board[i][k] == ".":
                    board[i][k] = "x"
                if board[i][k] == "S":
                    del search[0]
                if board[i][k] == "W":
                    break
            for k in range(i, N):
                if board[k][j] == ".":
                    board[k][j] = "x"
                if board[k][j] == "S":
                    del search[0]
                if board[k][j] == "W":
                    break
            for k in range(j, M):
                if board[i][k] == ".":
                    board[i][k] = "x"
                if board[i][k] == "S":
                    del search[0]
                if board[i][k] == "W":
                    break
def getExpand(location): #Return all valid (ie exist doesn't check what is there) moves from a location
    output = list()
    if location[0]+1 < N:
        output.append([location[0]+1, location[1]])
    if location[1]+1 < M:
        output.append([location[0], location[1]+1])
    if location[0]-1 > 0:
        output.append([location[0]-1, location[1]])
    if location[1]-1 > 0:
        output.append([location[0], location[1]-1])
    return output
def valueSpot(spot, distance, depth):
    if depth > 100: return 0 #Don't allow it get stuck on a RL or DU infinite loop; Super Sketchy
    global search
    x, y = spot
    if board[x][y] == "W":
        return 0
    if board[x][y] == "x":
        return -1
    if board[x][y] == "D":
        spot[0] += 1
        return valueSpot(spot, distance, depth+1)
    if board[x][y] == "U":
        spot[0] -= 1
        return valueSpot(spot, distance, depth+1)
    if board[x][y] == "R":
        spot[1] += 1
        return valueSpot(spot, distance, depth+1)
    if board[x][y] == "L":
        spot[1] -= 1
        return valueSpot(spot, distance, depth+1)
    if board[x][y] == "." and moves[x][y] == 0:
        search.append([x, y])
        return distance+1
    return 0
while len(search) > 0:#When it is empty we are done
    for spot in getExpand(search[0]): #Take the first one and expand it
        temp = valueSpot(spot, moves[search[0][0]][search[0][1]], 0)
        if (moves[spot[0]][spot[1]] > temp or moves[spot[0]][spot[1]] == 0) and temp != 0:
            moves[spot[0]][spot[1]] = temp
    del search[0] #Always just delete the first one
#print only the squares that we are supposed to be checking for in order
for i in range(N):
    for j in range(M):
        if (board[i][j] == "." or board[i][j] == "x") and moves[i][j] == 0:
            moves[i][j] = -1
        if moves[i][j] != 0:
            print(moves[i][j])
