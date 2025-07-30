t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    tot = 0
    bc = 0
    bad = False
    for i in range(n):
        if b[i] == -1:
            bc += 1
        else:
            if tot == 0:
                tot = a[i] + b[i]
            else:
                # print(f"tot = {tot}, aibi = {a[i] + b[i]}")
                if a[i] + b[i] != tot:
                    bad = True
                    break
    if bad or ((max(a) > tot or k < tot) and tot > 0):
        print(0)
    elif tot != 0:
        print(1)
    else:
        lo = k + min(a)
        mo = lo - max(a)
        print(mo + 1)
