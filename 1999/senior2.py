import re

n = int(input())

form1 = re.compile("[0-9]{2}/[0-9]{2}/[0-9]{2}")
form2 = re.compile("[0-9]{2}\.[0-9]{2}\.[0-9]{2}")
form3 = re.compile("[a-zA-Z]{*} [0-9]{2}, [0-9]{2}")
#//2[0-9]//2[0-9]
for i in range(n):
    line = input()
    toreplace = re.findall(form1, line)+re.findall(form2, line)+re.findall(form3, line)
    #print(toreplace)
    print(re.findall(form1, line),re.findall(form2, line),re.findall(form3, line))
