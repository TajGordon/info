h, w = map(int, input().split())

grid = []

robots_needed = 1

for y in range(h):
    row = [] # true = empty = can go, false = wall
    row_input = input()
    for x in range(w):
        row.append(row_input[x] == '.')
    grid.append(row)

for y in range(h):
    for x in range(w):
        if not grid[y][x]: continue
        degree = 0

        if x > 0:
            degree += 1 if grid[y][x-1] else 0
        if x < w - 1:
            degree += 1 if grid[y][x+1] else 0
        if y > 0:
            degree += 1 if grid[y-1][x] else 0
        if y < h - 1:
            degree += 1 if grid[y+1][x] else 0

        robots_needed += max(0, degree - 2)
        robots_needed += 1 if x == 0 and y == 0 and degree == 2 else 0

print(robots_needed)