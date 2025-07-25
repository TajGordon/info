n = int(input())

h = list(map(int,input().split()))

h.sort()

c = 0
for l in sorted(h):
    if l > c:
        c += 1

print(c)