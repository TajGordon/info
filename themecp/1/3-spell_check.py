t = int(input())

for _ in range(t):
    n = int(input())
    s = input()
    if n != 5:
        print("NO")
        continue
    Tc = 0
    ic = 0
    mc = 0
    uc = 0
    rc = 0
    for c in s:
        if c == 'T':
            Tc += 1
        if c == 'i':
            ic += 1
        if c == 'm':
            mc += 1
        if c == 'u':
            uc += 1
        if c == 'r':
            rc += 1
    if Tc == 1 and ic == 1 and mc == 1 and uc == 1 and rc == 1:
        print("YES")
    else:
        print("NO")