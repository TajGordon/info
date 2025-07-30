ro, bo, s, rp, bp = map(int, input().split(' '))

a = s - (rp - ro) + 1
b = s - (bp - bo) + 1

r = min(a,b)

if a == b:
    r-=1

r = max(0, r)

print(r)

