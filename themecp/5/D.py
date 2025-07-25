t = int(input())
for _ in range(t):
    n = int(input())
    a = []
    so = []
    a = list(map(int, input().split()))
    so = sorted(a)
    su = [0] * (n + 1)
    for i in range(n):
        su[i + 1] = su[i] + so[i]
    gap = [0] * (n - 1)
    for i in range(n-1):
        gap[i] = so[i + 1] - su[i + 1]
    ma = dict()
    vals = sorted(a)
    for i in range(n-1):
        g = gap[i]
        vals_to_remove = []
        for j in range(len(vals)):
            v = vals[j]
            if (v < so[i + 1] and g > 0) or v < g:
                ma[v] = i
                vals_to_remove.append(j)
            else:
                break
        for v in reversed(sorted(vals_to_remove)):
            vals.pop(v)
        if len(vals) == 0:
            break
    if len(vals) > 0:
        for v in vals:
            ma[v] = n - 1
    for e in a:
        print(f"{ma[e]}", end=" ")
    print("\n", end="")