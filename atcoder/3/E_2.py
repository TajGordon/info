from collections import defaultdict
n, q = map(int, input().split())

is_black = defaultdict(bool)
blacks = defaultdict(set)
head = [i for i in range(0,n+1)]
print(head)

for _ in range(q):
    print(f"iter #{_}, head: {head}")
    lis = list(map(int, input().split()))
    query_type = lis[0]
    if query_type == 1:
        u, v = lis[1], lis[2]
        print(f" sets before the union for {u}, {v}, {head[u]}, {head[v]}: {blacks[head[u]]}, {blacks[head[v]]} whats supposed to be the union")
        blacks[head[u]] = blacks[head[u]].union(blacks[head[v]])
        print(f"set head {head[v]} to head {head[u]}")
        head[v] = head[u]
        print(f"should be equal {head[v]} --- {head[u]}")
        print(f"sets after the union: {blacks[head[u]]}")
    elif query_type == 2:
        u = lis[1]
        print(f"set before for head {head[u]} for node {u}: {blacks[head[u]]}")
        if not is_black[u]:
            is_black[u] = True
            blacks[head[u]].add(u)
        else:
            is_black[u] = False
            blacks[head[u]].remove(u)
        print(f"set after for head {head[u]}: {blacks[head[u]]}")
    else:
        u = lis[1]
        if len(blacks[head[u]]) > 0:
            print(f" the set with items in it for head {head[u]}: {blacks[head[u]]}")
            print("Yes")
        else:
            print("No")
