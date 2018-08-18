k = int(input())

message = input()

def shift(i):
    return (3*(i+1)+k)

output = ""
for i,l in enumerate(message):
    output += chr((ord(l)-ord('A') - shift(i)) % 26 + ord('A'))
print(output)
