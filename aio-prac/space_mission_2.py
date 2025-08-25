# reduce map to ignore any with lower on either side
# split into two sides
# do every check between the two sides (n^2)
# return min
n, f = map(int, input().split())
c = []

min_found = float('inf')
min_idx = 0

for i in range(n):
    x = int(input())
    c.append(x)
    if x < min_found:
        min_found = x
        min_idx = i

left_side = [[c[i], i] for i in range(0, min_idx)]
right_side = [[c[i], i] for i in range(min_idx, n)]
# print(left_side)
# print(right_side)

# reduce arrays
changed = True
while changed:
    changed = False
    for i in range(1, len(left_side)):
        if left_side[i][0] > left_side[i-1][0]:
            left_side.pop(i)
            changed = True
            break

for i in range(len(right_side)-2, -1, -1):
    if right_side[i][0] > right_side[i+1][0]:
        right_side.pop(i)

# print(left_side)
# print(right_side)

most_samples = -1
left_idx = 0
right_idx = 0

# check for combinations with min on right side
# will binary search this if needed, but only once so shouldn't be a big deal
for i in range(1,len(right_side)):
    if min_found + right_side[i][0] > f:
        break
    if right_side[i][1] - right_side[0][1] + 1 > most_samples:
        most_samples = right_side[i][1] - right_side[0][1] + 1


# O(n^2) brute force
# for i in range(len(left_side)):
#     for j in range(len(right_side)):
#         if left_side[i][0] + right_side[j][0] > f:
#             break
#         if right_side[j][1] - left_side[i][1] + 1 > most_samples:
#             most_samples = right_side[j][1] - left_side[i][1] + 1

# binary search! 
for i in range(len(left_side)-1, -1, -1):
    k = 0
    b = len(right_side)//2
    while b >= 1:
        while (k+b < len(right_side) and left_side[i][0] + right_side[k+b][0] <= f): k+=b
        b //= 2
    if right_side[k][0] + left_side[i][0] > f: break
    if right_side[k][1] - left_side[i][1] + 1 > most_samples:
        most_samples = right_side[k][1] - left_side[i][1] + 1
        left_idx = i
        right_idx = k

# print("most samples: ")
print(most_samples)