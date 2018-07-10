'''
CCC 2010 Senior 2
Score: 15/15
'''
N = int(input())
decoder = {}
for i in range(N):
    letter, code = [i for i in input().split()]
    decoder[code] = letter
message = input().rstrip()
output = ""
i = 0
while i < len(message):
    for j in range(i, len(message)+1):
        if message[i:j] in decoder:
            output += decoder[message[i:j]]
            break
    i += j-i
print(output)
