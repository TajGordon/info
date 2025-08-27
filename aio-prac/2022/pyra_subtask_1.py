from collections import defaultdict


n = int(input())
p = list(map(int, input().split()))

min_value = float('inf')
c = defaultdict(int)
first = defaultdict(int)
last = defaultdict(int)
for i in range(n):
    x = p[i]
    c[x] += 1
    if c[x] == 1:
        first[x] = i
    else:
        last[x] = i
    if x < min_value:
        min_value = x

min_count = n - 1

for i in range(n):
    x = p[i]
    if c[x-1] < 2:
        continue
    if first[x-1] > i or last[x-1] < i:
        continue
    tot = 3
    offset = 1
    while offset + min_value < x:
        if c[x-offset-1] < 2:
            break
        if first[x-offset-1] > first[x-offset] or last[x-offset-1] < last[x-offset]:
            break
        tot += 2
        offset += 1
    if n - tot < min_count:
        min_count = n - tot

print(min_count)


