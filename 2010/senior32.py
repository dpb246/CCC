import math

def difzip(array):
    return zip(array[:-1], array[1:])

def calc_distances(houses):
    output = [h2-h for h, h2 in difzip(houses)]
    output.append( (houses[0] + 1000000) - houses[-1]) #Account for wrapping around circle
    return output

def find_longest_hose(fire_spots):
    max = 0
    for pos, length in fire_spots:
        if max < length:
            max = length
    return max

def find_min_pair(fire_spots):
    min_dis = 10000000
    location = 0
    for i in range(len(fire_spots)-1):
        if min_dis > fire_spots[i+1][0] - fire_spots[i][0]:
            min_dis = fire_spots[i+1][0] - fire_spots[i][0]
            location = i
    if min_dis > fire_spots[0][0] + 1000000 - fire_spots[-1][0]:
        min_dis = fire_spots[0][0] + 1000000 - fire_spots[-1][0]
        location = i
    return min_dis, location

def main():
    H = int(input())
    houses = sorted([int(input()) for i in range(H)])
    k = int(input())

    if k >= H: #Each has their own fire hydrant also ensures that len(houses)>1 since k>1 and therefore to not trigger this len(houses) is atleast 2
        print(0)
        return 0

    fire_spots = [[h, 0] for h in houses] #location of fire hydrants, distance to reach it

    while len(fire_spots) > k:
        dis, loc = find_min_pair(fire_spots)
        print(dis, loc)
        to_merge = fire_spots.pop(loc)
        temp = fire_spots[loc]
        fire_spots[loc][0] = math.ceil((temp[0] - to_merge[0]) / 2) + to_merge[0]
        fire_spots[loc][1] = (temp[0] - to_merge[0]) / 2 + to_merge[1] + temp[1]
    print(math.ceil(find_longest_hose(fire_spots)/2))
    print("H {}".format(H))
    print("houses {}".format(houses))
    print("fire hydrants {}".format(fire_spots))
    print("k {}".format(k))

if __name__ == "__main__":
    main()
