'''
ID: dpb2461
TASK: milk3
LANG: PYTHON3
'''
fin = open("milk3.in")
capacity = [int(i) for i in fin.readline().split()]

output = set()

starting_levels = [0, 0, capacity[2]] #c starts at full

def find(current, level):
    if current[0] == 0 and level > 0 and current[2] not in output: #if bucket a is empty
        output.add(current[2]) #add bucket c to answer
        return
    if level > 4:
        return
    level += 1
    print(current)
    for i in range(3):
        for j in range(3):
            if j==i: continue #don't pour into self
            if current[i] > capacity[j]: #current bucket is bigger than pouring
                ogi = current[i]
                ogj = current[j]
                current[i] += min(capacity[j], current[j])
                current[j] -= min(capacity[j], current[j])
                find(current, level)
                current[i] = ogi
                current[j] = ogj
            elif current[i] < capacity[j]:
                ogi = current[i]
                ogj = current[j]
                change = max(capacity[i], current[j])
                current[i] += change
                current[j] -= change
                find(current, level)
                current[i] = ogi
                current[j] = ogj
                
find(starting_levels, 0)
print(sorted(output))
