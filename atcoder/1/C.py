n, m = map(int, input().split())

adj = dict()

ric = [0] * m

for i in range(m):
    inp = list(map(int, input().split()))
    ric[i] = inp[0]
    for ig in inp[1:]:
        if not ig in adj.keys():
            adj[ig] = []
        adj[ig].append(i)

cnt = 0

tols = list(map(int, input().split()))
for to in tols:
    for i in adj[to]:
        ric[i] -= 1
        if ric[i] == 0:
            cnt += 1
    print(cnt)