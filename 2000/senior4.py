distance = int(input())
clubcount = int(input())
clubs = sorted([int(input()) for i in range(clubcount)])[::-1]

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

