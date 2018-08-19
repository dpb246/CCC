'''
CCC 2016 Senior 1
15/15
'''
a = list(input().rstrip())
b = list(input().rstrip())
count = [0 for i in range(26)]
for l in a:
    count[ord(l)-ord('a')] += 1
astric = 0
bad = False
for l in b:
    if l == '*':
        astric += 1
    else:
        count[ord(l)-ord('a')] -= 1
        if count[ord(l)-ord('a')] < 0:
            bad = True
            break
if sum(count) == astric and not bad:
    print("A")
else:
    print("N")

