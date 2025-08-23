


# find for base
# for each one, check all squares in its row/column
# if any of those cells contain an impossible tile, decrease amount needed
# if all cells are the same, increase needed 

r, c, q = map(int, input().split())

is_blue = [[False] * c] * r
# y, x

for y in range(r):
    s = input()
    for x in range(c):
        if s[x] == 'B':
            is_blue[y][x] = True

print(is_blue)

dead_cell = [[True] * c] * r

dead_cells = []
dc_y = []
dc_x = []
# if not overlapping its 1 for 2 or 1, else if 2 on same line just 1 for 3>
needed = 0
buffer_switch = True
def update():
    for y in range(r):
        for x in range(c):
            for i in range(r):
                if is_blue[i][x] != is_blue[y][x]:
                    dead_cell[y][x] = False
                    break
            if not dead_cell[y][x]:
                continue
            for i in range(c):
                if is_blue[y][i] != is_blue[y][x]:
                    dead_cell[y][x] = False
                    break
            if dead_cell[y][x]:
                if not dc_y.find(y) and not dc_x.find(x):
                    if buffer_switch:
                        needed += 1
                        buffer_switch = False
                    else:
                        buffer_switch = True

                dead_cells.append((y, x))
                dc_y.append(y)
                dc_x.append(x)
update()
        
print(needed)

for i in range(q):
    y, x = map(int, input().split())
    is_blue[y][x] = not is_blue[y][x]
    update()
    print(needed)