
# num nodes, num edges
n, m = map(int, input().split())

edges = {}

for i in range(m):
    x, y, z = map(int, input().split())
    if not x in edges.keys():
        edges[x] = [(y, z)]
    else:
        edges[x].append((y,z))
    # edges go both ways!
    if not y in edges.keys():
        edges[y] = [(x, z)]
    else:
        edges[y].append((x,z))

k = int(input())

current_possible_cities = set(edges.keys())
next_possible_cities = set()

# propagates graph
for i in range(k):
    move = int(input())
    for city in edges.keys():
        # if this city has an edge with one of the possible cities of the type
        for edge, type in edges[city]:
            if edge in current_possible_cities and type == move:
                next_possible_cities.add(city)
    current_possible_cities = next_possible_cities
    next_possible_cities = set()

if len(current_possible_cities) == 0:
    print('Impossible')
else:
    for city in current_possible_cities:
        print(city)
