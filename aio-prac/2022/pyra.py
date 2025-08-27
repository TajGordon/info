from collections import defaultdict


n = int(input())
P = list(map(int, input().split()))

count = defaultdict(int)
first = defaultdict(int)
last = defaultdict(int)
for i in range(n):
    count[P[i]]+=1
    if count[P[i]] == 1:
        first[P[i]] = i
    else:
        last[P[i]] = i

base_count = 0
keys = []
ind = defaultdict(int)

for i in range(n):
    if count[P[i]] == 1:
        keys.append(P[i])
        ind[len(keys)-1] = i
    elif i == first[P[i]] or i==last[P[i]]:
        keys.append(P[i])
        ind[len(keys)-1] = i
    else:
        base_count += 1

# print(keys)
# print(ind)

m = len(keys)

min_count = n - 1

for i in range(m):
    offset = 1
    taking_with = 3
    # print("---------------------------------")
    # print(f"i = {i}, P[{i}] = {P[i]}")
    if count[P[i]-1] < 2:
        continue
    if first[P[i]-1] > ind[i] or last[P[i]-1] < ind[i]:
        continue
    # print("passed first comparison")

    while offset < P[i]:
        # print(f"checking {P[i]-offset} (offset = {offset})")
        if count[P[i]-offset-1] <2:
            break
        # print("passed offset check 1")
        if first[P[i]-offset-1] > first[P[i]-offset] or last[P[i]-offset-1] < last[P[i]-offset]:
            break
        # print("passed offset check 2")
        taking_with += 2
        offset += 1
    
    if n - taking_with < min_count: min_count = n - taking_with

print(min_count)