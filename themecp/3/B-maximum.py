t = int(input())
for _ in range(t):
    l, r = input().split()

    if len(r) > len(l):
        print(int(r[0]) + 9 * (len(r)-1))
    else:
        k = 0
        while r[k] == l[k] and k + 1 < len(r):
            k += 1
        print(int(abs(int(r[k]) - int(l[k])) + 9 * (len(r) - k - 1)))


