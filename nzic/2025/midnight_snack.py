n = int(input())
k = int(input())

t = 0

for i in range(n):
    c = int(input())
    if c >= k:
        t += c

print(t)