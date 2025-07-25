import sys
sys.setrecursionlimit(1000000000)

# n = num towns
# k = max amount of cans in backpack
# d = distances between towns
# c = cost of food in each town
N, K = map(int, input().strip().split())
D = list(map(int, input().strip().split()))
C = list(map(int, input().strip().split()))

# last town we wanna get to so basically no cost
C[-1] = -1239123
# total amount of cans = sum(D)
# need to travel across all towns minimizing cost
# d = num cans to travel
# c = cost per can

# intuition: greedy
# greedy: min possible amount of cans to get somewhere cheaper
# feel like proof by contradiction works (contradiction / exchange)
# intuition: simulate it like a game

# logic:
# if there is a cheaper town c, within a distance k, buy the exact amount of cans needed to get to c
# if there isn't a cheaper town within k, fill backpack with as many cans as possible, then continue

# using a PSA just for fun (AFTER)

# vars
# 1 - N inclusive
# storing as 0-n-1
pos = 0
spent = 0
backpack = 0

while pos < N - 1:
    inrange = False
    tinrange = 0
    sum = D[pos]
    for i in range(pos + 1, N):
        if sum > K: break
        if C[i] <= C[pos]:
            inrange = True
            tinrange = i
            break
        if i < N - 1: sum += D[i]

    if inrange:
        # sum = num cans to buy
        spent += (sum-backpack) * C[pos]

        # backpack will buy enough to get there, and then we need no more
        backpack = 0

        # move to that place
        pos = tinrange
    else:
        # buy max cans
        spent += (K - backpack) * C[pos]
        backpack = K

        # spend some cans to move
        backpack -= D[pos]
        pos += 1

print(spent)
