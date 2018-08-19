"""
Full Marks
"""
import string
plain = input()
decode = input()
message = input()

alphabet = list(string.ascii_uppercase)
alphabet.append(" ")

mapping = {l:"." for l in alphabet}

for l1, l2 in zip(plain, decode):
    mapping[l2] = l1

print("".join(mapping[l] for l in message))
