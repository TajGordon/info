from collections import defaultdict
n, q = map(int, input().split())

graph = defaultdict(list)
black = defaultdict(bool)
blacks = defaultdict(set)
is_black = defaultdict(bool)
# edges are never removed, so can permanently merge lists
for _ in range(q):
    lis = list(map(int,input().split()))
    x = lis[0]
    if x == 1:
        u, v = lis[1], lis[2]
        graph[u].append(v)
        graph[u] += graph[v]
        is_black[u] = is_black[u] or is_black[v]
        for e in blacks[v]:
            if not e in blacks[u]:
                blacks[u].add(e)
        graph[v].append(u)
        graph[v] += graph[u]
        is_black[v] = is_black[u] or is_black[v]
        for e in blacks[u]:
            if not e in blacks[v]:
                blacks[v].add(e)
    elif x == 2:
        v = lis[1]
        if not black[v]:
            black[v] = True
            blacks[v].add(v)
            is_black[v] = True
            visited = set()
            stack = [v]
            while len(stack) > 0:
                z = stack[-1]
                stack.pop()
                if z in visited:
                    continue
                visited.add(z)
                is_black[z] = True
                blacks[z].add(v)
                for neighbor in graph[z]:
                    if not neighbor in visited:
                        stack.append(neighbor)
        else:
            black[v] = False
            stack = [v]
            visited = set()
            while len(stack) > 0:
                z = stack[-1]
                stack.pop()
                if z in visited:
                    continue
                visited.add(z)
                if v in blacks[z]: 
                    blacks[z].remove(v)
                if len(blacks[z]) == 0:
                    is_black[z] = False
                for neighbor in list(graph[z]):
                    if not neighbor in visited:
                        stack.append(neighbor)
    elif x == 3:
        v = lis[1]
        if is_black[v]:
            print("Yes")
        else:
            print("No")