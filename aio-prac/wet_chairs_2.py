# this is because the ORAC site wants a different approach using 2 pointers instead of whatever I did
# the last one barely ran in time
# it was probably slow because it iterated over everything everytime
# but i think it still wants that for this one?

# num chairs, num ppl, num ppl who will sit on a wet chair
c, n, k = map(int, input().split()) # ints
chairs = input() # 'd' or 'w'

minlength = float('inf')
for l in range(0, c - n):
    w = 0
    chaircount = 0
    if l + n >= c:
        break
    for i in range(l, min(l + n, c - n)):
        w += 1 if chairs[i] == 'w' else 0
        chaircount += 1
    if chaircount - w >= n - k:
        minlength = chaircount
        break
    for r in range(l + n, c - l):
        w += 1 if chairs[r] == 'w' else 0
        chaircount += 1
        if chaircount - w >= n - k:
            if chaircount < minlength:
                minlength = chaircount
            break

print(minlength)