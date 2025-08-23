from operator import index


n = int(input())
st= [""] * 3
st[0] = input()
st[1] = input()
st[2] = input()
cnt = [0, 0, 0]
indexes = []
for i in range(n):
    if st[0][i] == st[1][i] == st[2][i]:
        cnt[0] += 1
        cnt[1] += 1
        cnt[2] += 1
        continue
    indexes.append(i)

# print(min(cnt))
# print(indexes)
indexes_2 = []
for i in indexes:
    should_break = False
    for x in range(3):
        for y in range(3):
            if x == y: continue
            for z in range(3):
                if x == z or y == z: continue
                if st[x][i] == st[y][i] and cnt[z] != min(cnt):
                    cnt[x] += 1
                    cnt[y] += 1
                    should_break = True
                    break
            if should_break:
                break
        if should_break:
            break
    if should_break:
        continue

    indexes_2.append(i)

# print(min(cnt))
for i in indexes_2:
    for x in range(3):
        if cnt[x] == min(cnt):
            cnt[x] += 1
            break

print(min(cnt))

