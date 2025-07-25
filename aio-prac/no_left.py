n = int(input())

carts = {}

for i in range(n):
    x,y = map(int, input().split())
    if not x in carts.keys():
        carts[x] = [y]
    else:
        carts[x].append(y)

length_of_slice = {}
total_dist = 0

prev_x = None

for x in sorted(carts.keys()):
    length_of_slice[x] = max(carts[x]) - min(carts[x])
    total_dist += length_of_slice[x]

    # add the distance between slices
    if prev_x:
        total_dist += abs(prev_x - x)
    prev_x = x


