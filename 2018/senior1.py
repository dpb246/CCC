'''
CCC Senior 1
Score: 15/15
'''
N = int(input())
villages = list()
for i in range(N):
    villages.append(int(input()))
villages.sort()
smallest = 1000000000000000 #Set to really big number to start
for i in range(1, len(villages)-1):#1st and last village have inifite area so don't try to calculate can't be smallest
    area = (villages[i]-villages[i-1])/2 + (villages[i+1]-villages[i])/2
    if area<smallest:
        smallest = area
print("{:.1f}".format(smallest))#Print to 1 decimal place and force no exponents
