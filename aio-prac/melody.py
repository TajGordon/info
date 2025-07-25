n, k = map(int, input().split())
# k = max num
song = []
for i in range(n):
    a = int(input())
    song.append(a)

f1 = [0] * (k+1)
f2 = [0] * (k+1)
f3 = [0] * (k+1)

for i in range(0,n,3):
    f1[song[i]] += 1
for i in range(1,n,3):
    f2[song[i]] += 1
for i in range(2,n,3):
    f3[song[i]] += 1

total_1 = sum(f1) - max(f1)
total_2 = sum(f2) - max(f2)
total_3 = sum(f3) - max(f3)

total = total_1 + total_2 + total_3
print(total)