"""
Full marks
"""
distance = int(input())
clubcount = int(input())
clubs = [int(input()) for i in range(clubcount)]

moves = [0 for i in range(distance+1)]
for i in range(1,distance+1):
    minimum = 1000000
    for c in clubs:
        if c <= i:
            if (1+moves[i-c] < minimum):
                minimum = 1+moves[i-c]
    moves[i] = minimum
if moves[-1] == 1000000:
    print("Roberta acknowledges defeat.")
else:
    print("Roberta wins in {} strokes.".format(moves[-1]))


"""
Recursive style: TLE on test 5
def number(distance):
    if distance == 0:
        return 0
    else:
        minimum = 1000000
        for c in clubs:
            if c <= distance:
                moves = 1 + number(distance-c)
                if moves < minimum:
                    minimum = moves
        return minimum

value = number(distance)
if value == 1000000:
    print("Roberta acknowledges defeat.")
else:
    print("Roberta wins in {} strokes.".format(value))
"""

"""
Bad Greedy style, doesn't solve all cases
n = 0
i = 0
while True:
    if distance-clubs[i] >= 0:
        distance -= clubs[i]
        n+=1
    else:
        i+=1
    if i >= len(clubs):
        print("Roberta acknowledges defeat.")
        break
    if distance == 0:
        print("Roberta wins in {} strokes.".format(n))
        break

"""
