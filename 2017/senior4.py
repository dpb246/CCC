
n, m, d = [int(i) for i in input().split(" ")]

connections = [ [] for i in range(n+1)]
cost = [10**10 for i in range(n+1)]
best_to = [0 for i in range(n+1)]
in_tree = [False for i in range(n+1)]
in_tree[0] = True #Set so can use all()

city_plan = []#Store original plan
city_cost = 0
for i in range(m):
    a, b, c = [int(i) for i in input().split(" ")]
    connections[a].append([b, c])
    connections[b].append([a, c])
    if i < n-1:
        city_plan.append(sorted([a, b]))
        city_cost += c

in_tree[1] = True
most_recent = 1

best_plan = []

total_min_cost = 0
while not all(in_tree):
    #update costs
    for con in connections[most_recent]:
        if con[1] < cost[con[0]]:
            cost[con[0]] = con[1]
            best_to[con[0]] = most_recent
    #find cheapest that isn't in in_tree
    min = 10**10
    pos = 0
    for i, c in enumerate(cost):
        if c < min and not in_tree[i]:
            min = c
            pos = i
        elif c == min and not in_tree[i]:
            if sorted([best_to[i], i]) in city_plan:
                pos = i
                min = c
    in_tree[pos] = True #Add to tree
    total_min_cost += min
    best_plan.append(sorted([best_to[pos], pos]))
    most_recent = pos

#Best plan stores minium cost now just need to find number of differences
if city_cost <= total_min_cost:
    print(0)
else:
    remove = 0
    for con in city_plan:
        if not con in best_plan:
            remove += 1
    add = 0
    for con in best_plan:
        if not con in city_plan:
            add += 1
    print(max(remove, add))
