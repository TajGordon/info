from ast import Tuple
from collections import defaultdict


n, h, f = map(int, input().split())
hip = []
has_hippo = defaultdict(bool)
for i in range(h):
    x = int(input())
    hip.append(x)
    has_hippo[x] = True

if f >= 2 * h - (1 if has_hippo[1] else 0) - (1 if has_hippo[n] else 0):
    print(n - h)
    exit()

tulip_sections = []
saw_hippo = True
for i in range(1, n+1):
    if has_hippo[i]:
        saw_hippo = True
        continue
    else:
        if saw_hippo:
            tulip_sections.append([1, 2])
        else:
            tulip_sections[-1][0] += 1
        saw_hippo = False

if not has_hippo[1]:
    tulip_sections[0][1] = 1
if not has_hippo[n]:
    tulip_sections[-1][1] = 1

tulip_sections.sort(key=lambda x: (-x[0], x[1]))


#print(tulip_sections)

sum = 0

while f > 0 and len(tulip_sections) > 0:
    if tulip_sections[0][1] <= f:
        sum += tulip_sections[0][0]
        f -= tulip_sections[0][1]
    tulip_sections.pop(0)

print(sum)
